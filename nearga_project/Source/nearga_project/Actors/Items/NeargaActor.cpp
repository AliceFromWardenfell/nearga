#include "NeargaActor.h"

#include "IDetailTreeNode.h"
#include "GameFramework\PlayerController.h"
#include "Kismet/GameplayStatics.h"

ANeargaActor::ANeargaActor() :
	bIsInteractable(false),
	SecondsToHide(0.5)
{
	PrimaryActorTick.bCanEverTick = true;
	// PrimaryActorTick.bStartWithTickEnabled = false;
	//
	// ObjectInfoRadius = CreateDefaultSubobject<USphereComponent>(TEXT("ObjectInfoRadius"));
	// ObjectInfoRadius->InitSphereRadius(200.0);

}

// Called when the game starts or when spawned
void ANeargaActor::BeginPlay()
{
	Super::BeginPlay();

	InfoWidgetComponentRef = FindComponentByClass<UInfoWidgetComponent>();
	// if (ObjectInfoWidgetClass)
	// {
	// 	ObjectInfoWidget = CreateWidget<UObjectInfoWidget>(GetWorld(), ObjectInfoWidgetClass);
	// 	check(ObjectInfoWidget != nullptr);
	// 	ObjectInfoWidget->SetVisibility(ESlateVisibility::Hidden);
	// }
	// ObjectInfoRadius->OnComponentBeginOverlap.AddDynamic(this, &ANeargaActor::AddInfoWidgetToViewport);
	// ObjectInfoRadius->OnComponentEndOverlap.AddDynamic(this, &ANeargaActor::RemoveInfoWidgetFromViewport);
}

void ANeargaActor::ShowInfoOnTrace()
{
	//check(GEngine != nullptr);
	//GEngine->AddOnScreenDebugMessage(-1, 2.0, FColor::Red, GetName());
	
	if (InfoWidgetComponentRef)
	{
		//UE_LOG(LogTemp, Warning, TEXT("In ShowInfoOnTrace"));
		//InfoWidgetComponentRef->SetComponentTickEnabled(true);
		InfoWidgetComponentRef->SetComponentTickEnabled(true);
		InfoWidgetComponentRef->GetUserWidgetObject()->SetVisibility(ESlateVisibility::Visible);
		GetWorldTimerManager().SetTimer(InfoTimerHandle, this, &ANeargaActor::HideWidget, SecondsToHide, false);
	}
	// PrimaryActorTick.SetTickFunctionEnable(true);
	// ObjectInfoWidget->SetVisibility(ESlateVisibility::Visible);
	
}

// Called every frame
void ANeargaActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// FVector2D WidgetScreenLocation;
	//
	// UGameplayStatics::GetPlayerController(GetWorld(), 0)->
	// 	ProjectWorldLocationToScreen(ObjectInfoRadius->GetComponentLocation() + FVector(0, 0, 50), WidgetScreenLocation);
	// ObjectInfoWidget->SetPositionInViewport(WidgetScreenLocation);
	
	//UE_LOG(LogTemp, Warning, TEXT("InfoTick"));
}

// void ANeargaActor::AddInfoWidgetToViewport(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
// {
// 	UE_LOG(LogTemp, Warning, TEXT("Added to viewport"));
// 	ObjectInfoWidget->AddToViewport();
// }

// void ANeargaActor::RemoveInfoWidgetFromViewport(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
// {
// 	UE_LOG(LogTemp, Warning, TEXT("Removed from viewport"));
// 	ObjectInfoWidget->RemoveFromParent();
// }

void ANeargaActor::HideWidget()
{
	UE_LOG(LogTemp, Warning, TEXT("In HideWidget"))
	InfoWidgetComponentRef->GetUserWidgetObject()->SetVisibility(ESlateVisibility::Hidden);
	InfoWidgetComponentRef->SetComponentTickEnabled(false);
	//InfoWidgetComponentRef->SetComponentTickEnabled(false);
	// ObjectInfoWidget->SetVisibility(ESlateVisibility::Hidden);
	// PrimaryActorTick.SetTickFunctionEnable(false);
}
