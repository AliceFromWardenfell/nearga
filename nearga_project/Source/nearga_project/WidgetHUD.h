// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetHUD.generated.h"

/**
 * 
 */
UCLASS()
class NEARGA_PROJECT_API UWidgetHUD : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHealth(int32 CurrentHealth, int32 MaxHealth);
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateSatiation(int32 CurrentSatiation, int32 MaxSatiation);
	
};
