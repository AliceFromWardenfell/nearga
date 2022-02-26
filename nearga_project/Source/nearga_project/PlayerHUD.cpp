// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	if (PlayerWidgetClass)
	{
		WidgetHUD = CreateWidget<UWidgetHUD>(GetWorld(), PlayerWidgetClass);
		
		if (WidgetHUD)
		{
			UE_LOG(LogTemp, Warning, TEXT("Added to viewport"));
			WidgetHUD->AddToViewport();
		}
	}
}

void APlayerHUD::UpdateSatiation(int32 CurrentSatiation, int32 MaxSatiation)
{
	if (WidgetHUD)
	{
		WidgetHUD->UpdateSatiation(CurrentSatiation, MaxSatiation);
	}
}
