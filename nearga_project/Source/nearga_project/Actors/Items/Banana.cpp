// Fill out your copyright notice in the Description page of Project Settings.


#include "Banana.h"

ABanana::ABanana()
{
	ItemName = TEXT("BANANA");
	PointsToRestore = 70;
}

void ABanana::Interact_Implementation()
{
	Super::Interact_Implementation();

	UE_LOG(LogTemp, Warning, TEXT("This is banana"));
}
