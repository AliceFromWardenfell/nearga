// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingKit.h"

AHealingKit::AHealingKit()
{
	ItemName = TEXT("Healing kit");
	PointsToRestore = 20;
}

void AHealingKit::BeginPlay()
{
	Super::BeginPlay();

	//ObjectInfoWidget->
}