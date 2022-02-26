// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WidgetHUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class NEARGA_PROJECT_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	UFUNCTION()
	void UpdateSatiation(int32 CurrentSatiation, int32 MaxSatiation);
	UFUNCTION()
	void UpdateHealth(int32 CurrentHealth, int32 MaxHealth);
	
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> PlayerWidgetClass;

private:
	
	UPROPERTY()
	UWidgetHUD* WidgetHUD;
	
};
