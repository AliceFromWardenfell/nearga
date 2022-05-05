#include "nearga_projectCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interfaces/InteractInterface.h"

#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"

Anearga_projectCharacter::Anearga_projectCharacter() :
	SecondsToHide(0.5),
	ItemsInfoRadius(200)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void Anearga_projectCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	InfoWidgetComponentRef = FindComponentByClass<UInfoWidgetComponent>();
}

//////////////////////////////////////////////////////////////////////////
// Input

void Anearga_projectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &Anearga_projectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &Anearga_projectCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &Anearga_projectCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &Anearga_projectCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &Anearga_projectCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &Anearga_projectCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &Anearga_projectCharacter::OnResetVR);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &Anearga_projectCharacter::Interact);
}

void Anearga_projectCharacter::OnResetVR()
{
	// If nearga_project is added to a project via 'Add Feature' in the Unreal Editor the dependency on HeadMountedDisplay in nearga_project.Build.cs is not automatically propagated
	// and a linker error will result.
	// You will need to either:
	//		Add "HeadMountedDisplay" to [YourProject].Build.cs PublicDependencyModuleNames in order to build successfully (appropriate if supporting VR).
	// or:
	//		Comment or delete the call to ResetOrientationAndPosition below (appropriate if not supporting VR)
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void Anearga_projectCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void Anearga_projectCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

bool Anearga_projectCharacter::TraceForward(FHitResult& HitResult) const
{
	FVector					EyesLocation = FollowCamera->GetComponentLocation();
	FRotator				Rotation = FollowCamera->GetComponentRotation();
	FCollisionQueryParams	TraceParams;
	//AController*			ActorController = GetController();

	
	
	//if (!ActorController)
	//{
	//	GEngine->AddOnScreenDebugMessage(0, 2, FColor::Blue, TEXT("!ActorController"));
	//}
	//else
	//{
		//GetOwner()->GetActorEyesViewPoint(EyesLocation, Rotation);
		//ActorController->GetPlayerViewPoint(EyesLocation, Rotation);
	//}
	FVector EndTraceLocation = EyesLocation + (Rotation.Vector() * 2000);
	
	//DrawDebugLine(GetWorld(), EyesLocation, EndTraceLocation, FColor::Magenta, false, 4, 0, 0);
	
	return GetWorld()->LineTraceSingleByChannel(HitResult, EyesLocation, EndTraceLocation, ECC_Visibility, TraceParams);
}

void Anearga_projectCharacter::ShowInfoAboutInteractableItem() const
{
	FHitResult HitResult;
	bool bIsHit = TraceForward(HitResult);

	if (bIsHit && FVector::Dist(GetActorLocation(), HitResult.ImpactPoint) <= ItemsInfoRadius)
	{
		IInteractInterface* InteractInterface = Cast<IInteractInterface>(HitResult.GetActor());
		if (InteractInterface)
		{
			InteractInterface->ShowInfoOnTrace();
		}
	}
}

void Anearga_projectCharacter::Interact()
{
	FHitResult HitResult;
	bool bIsHit = TraceForward(HitResult);

	if (bIsHit)
	{
		AExpendableItem* Item = Cast<AExpendableItem>(HitResult.GetActor());
		if (Item)
		{
			Item->ServerInteract();
		}
	}
}

void Anearga_projectCharacter::ShowInfoOnTrace()
{
	if (InfoWidgetComponentRef)
	{
		InfoWidgetComponentRef->SetComponentTickEnabled(true);
		InfoWidgetComponentRef->GetUserWidgetObject()->SetVisibility(ESlateVisibility::Visible);
		GetWorldTimerManager().SetTimer(InfoTimerHandle, this, &Anearga_projectCharacter::HideWidget, SecondsToHide, false);
	}
}

void Anearga_projectCharacter::HideWidget() const
{
	if (InfoWidgetComponentRef)
	{
		InfoWidgetComponentRef->GetUserWidgetObject()->SetVisibility(ESlateVisibility::Hidden);
		InfoWidgetComponentRef->SetComponentTickEnabled(false);
	}
}

void Anearga_projectCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void Anearga_projectCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void Anearga_projectCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void Anearga_projectCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
