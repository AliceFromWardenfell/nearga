// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingKit.h"

AHealingKit::AHealingKit()
{
	ItemName = TEXT("HEALING KIT");
	PointsToRestore = 20;
}

void AHealingKit::ServerInteract_Implementation()
{
	Super::ServerInteract_Implementation();

	UE_LOG(LogTemp, Warning, TEXT("This is Healing kit"));
	RestoreHealthPoints();
}
