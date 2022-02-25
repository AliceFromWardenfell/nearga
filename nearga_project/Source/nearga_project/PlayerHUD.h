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
	
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> PlayerWidgetClass;

	UPROPERTY()
	UWidgetHUD* WidgetHUD;
};
