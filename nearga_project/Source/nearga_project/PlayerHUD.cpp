// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	if (PlayerWidgetClass)
	{
		WidgetHUD = CreateWidget<UWidgetHUD>(GetWorld(), PlayerWidgetClass);
		check(WidgetHUD != nullptr);
		
		UE_LOG(LogTemp, Warning, TEXT("Added to viewport"));
		WidgetHUD->AddToViewport();
	}
}

void APlayerHUD::UpdateSatiation(int32 CurrentSatiation, int32 MaxSatiation)
{
	WidgetHUD->UpdateSatiation(CurrentSatiation, MaxSatiation);
}

void APlayerHUD::UpdateHealth(int32 CurrentHealth, int32 MaxHealth)
{
	WidgetHUD->UpdateHealth(CurrentHealth, MaxHealth);
}
