#include "ExpendableItem.h"

#include "Kismet/GameplayStatics.h"

AExpendableItem::AExpendableItem() :
	ItemName("DefaultName"),
	PointsToRestore(10)
{
	PrimaryActorTick.bCanEverTick = true;
	
	static ConstructorHelpers::FClassFinder<UUserWidget> Finder(TEXT("/Game/LevelBlueprints/Widgets/BPW_PressKeyToInteract"));
	if (Finder.Succeeded())
	{
		PressKeyWidgetClass = Finder.Class;
	}
}

void AExpendableItem::BeginPlay()
{
	Super::BeginPlay();

	if (PressKeyWidgetClass)
	{
		PressKeyWidget = CreateWidget<UPressKeyToInteractWidget>(GetWorld(), PressKeyWidgetClass);
		check(PressKeyWidget != nullptr);
		PressKeyWidget->SetVisibility(ESlateVisibility::Hidden);
		PressKeyWidget->AddToViewport();
	}
}

void AExpendableItem::ShowInfoOnTrace()
{
	Super::ShowInfoOnTrace();
	
	PressKeyWidget->SetVisibility(ESlateVisibility::Visible);
	GetWorldTimerManager().SetTimer(PressKeyTimerHandle, this, &AExpendableItem::HidePressKeyWidget, 0.1, false);
}

void AExpendableItem::HidePressKeyWidget()
{
	PressKeyWidget->SetVisibility(ESlateVisibility::Hidden);
}

void AExpendableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExpendableItem::Interact_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacted"));
}


