// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../PlayerHUD.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, DisplayName="HealthComponent" )
class NEARGA_PROJECT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(const int32 Damage);

	UFUNCTION(BlueprintCallable)
	void RestoreHealth(const int32 PointsToRestore);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	int32 MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	int32 InitialHealth;
	UPROPERTY(BlueprintReadOnly)
	int32 CurrentHealth;

	UPROPERTY()
	APlayerHUD* PlayerHUD;
	
};
