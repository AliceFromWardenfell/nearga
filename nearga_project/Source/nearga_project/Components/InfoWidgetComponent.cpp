#include "InfoWidgetComponent.h"

UInfoWidgetComponent::UInfoWidgetComponent(const FObjectInitializer& ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false; // Dosn't working, hmm..

	InfoRadius = CreateDefaultSubobject<USphereComponent>(TEXT("InfoRadius"));
	InfoRadius->InitSphereRadius(400.0);

	if (GetOwner())
	{
		if (GetOwner()->GetRootComponent())
			this->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		else
			GetOwner()->SetRootComponent(this);
		InfoRadius->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);
	}

	//SetTickMode(ETickMode::Automatic);
	//GetUserWidgetObject()->SetVisibility(ESlateVisibility::Hidden);
	//FAttachmentTransformRules AttachmentRules = FAttachmentTransformRules::KeepRelativeTransform;
	// bool bCheck = InfoRadius->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);
	// if (bCheck)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Success"));
	// }
	// else
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Fail"));
	// }
}

void UInfoWidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	
	
	SetComponentTickEnabled(true);
	//GetUserWidgetObject()->RemoveFromParent();
	//InfoRadius->OnComponentBeginOverlap.AddDynamic(this, &ANeargaActor::AddInfoWidgetToViewport);
	//InfoRadius->OnComponentEndOverlap.AddDynamic(this, &ANeargaActor::RemoveInfoWidgetFromViewport);
}

// void UInfoWidgetComponent::AddInfoWidgetToViewport()
// {
// }
//
// void UInfoWidgetComponent::RemoveInfoWidgetFromViewport()
// {
// }

void UInfoWidgetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// if (GetUserWidgetObject())
	// {
	// 	if (GetUserWidgetObject()->IsInViewport())
	// 	{
	// 		UE_LOG(LogTemp, Warning, TEXT("IsInViewport"));
	// 	}
	// 	else
	// 	{
	// 		UE_LOG(LogTemp, Warning, TEXT("IsNOTInViewport"));
	// 	}
	// }
	
	UE_LOG(LogTemp, Warning, TEXT("InfoWidgetComponent Tick"));
}
