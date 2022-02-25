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
			WidgetHUD->AddToViewport();
		}
	}
}
