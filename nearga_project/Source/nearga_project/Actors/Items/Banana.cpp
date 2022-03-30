// Fill out your copyright notice in the Description page of Project Settings.


#include "Banana.h"

ABanana::ABanana()
{
	ItemName = TEXT("BANANA");
	PointsToRestore = 700;
}

void ABanana::Server_Interact_Implementation(ACharacter* InteractingCharacter)
{
	Super::Server_Interact_Implementation(InteractingCharacter);

	UE_LOG(LogTemp, Warning, TEXT("This is Banana"));
	RestoreSatiationPoints();
}
