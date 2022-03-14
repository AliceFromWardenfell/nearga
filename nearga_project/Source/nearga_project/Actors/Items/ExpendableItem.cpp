#include "ExpendableItem.h"

AExpendableItem::AExpendableItem() :
	ItemName("DefaultName"),
	PointsToRestore(10)
{
	PrimaryActorTick.bCanEverTick = true;

}

void AExpendableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExpendableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

