// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingKit.h"

AHealingKit::AHealingKit()
{
	ItemName = TEXT("HEALING KIT");
	PointsToRestore = 20;
}

void AHealingKit::Server_Interact_Implementation(ACharacter* InteractingCharacter)
{
	Super::Server_Interact_Implementation(InteractingCharacter);

	UE_LOG(LogTemp, Warning, TEXT("This is Healing kit"));
	RestoreHealthPoints();
}
