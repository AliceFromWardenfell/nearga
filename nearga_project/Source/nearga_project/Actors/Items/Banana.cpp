// Fill out your copyright notice in the Description page of Project Settings.


#include "Banana.h"

ABanana::ABanana()
{
	ItemName = TEXT("BANANA");
	PointsToRestore = 70;
}

void ABanana::Server_Interact_Implementation()
{
	Super::Server_Interact_Implementation();

	UE_LOG(LogTemp, Warning, TEXT("This is Banana"));
}
