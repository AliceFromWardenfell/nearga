#include "Banana.h"

ABanana::ABanana()
{
	ItemName = TEXT("BANANA");
	PointsToRestore = 700;
}

void ABanana::ServerInteract_Implementation()
{
	Super::ServerInteract_Implementation();

	UE_LOG(LogTemp, Warning, TEXT("This is Banana"));
	RestoreSatiationPoints();
}