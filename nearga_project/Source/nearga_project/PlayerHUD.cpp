// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	if (PlayerWidgetClass)
	{
		PlayerPropertiesWidget = CreateWidget<UPlayerPropertiesWidget>(GetWorld(), PlayerWidgetClass);
		check(PlayerPropertiesWidget != nullptr);
		PlayerPropertiesWidget->AddToViewport();
	}
}

void APlayerHUD::UpdateSatiation(int32 CurrentSatiation, int32 MaxSatiation)
{
	PlayerPropertiesWidget->UpdateSatiation(CurrentSatiation, MaxSatiation);
}

void APlayerHUD::UpdateHealth(int32 CurrentHealth, int32 MaxHealth)
{
	PlayerPropertiesWidget->UpdateHealth(CurrentHealth, MaxHealth);
}
