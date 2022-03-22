// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../PlayerHUD.h"
#include "HealthComponent.h"
#include "SatiationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, DisplayName="SatiationComponent" )
class NEARGA_PROJECT_API USatiationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USatiationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void TakeHungerDamage();

	UFUNCTION(BlueprintCallable)
	void Eat(const int32 PointsToRestore);

	//UFUNCTION(BlueprintCallable)
	//void InflictHealthDamage();
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Satiation")
	int32 MaxSatiation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Satiation")
	int32 InitialSatiation;
	UPROPERTY(BlueprintReadOnly)
	int32 CurrentSatiation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Satiation")
	int32 HungerPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Satiation")
	float HungerRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DamageFromHunger")
	int32 DamageToInflict;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DamageFromHunger")
	float DamageRate;
	
	UPROPERTY()
	FTimerHandle SatiationTimerHandle;
	//UPROPERTY()
	//FTimerHandle HealthTimerHandle;
	//UPROPERTY()
	//UHealthComponent* HealthComponent;
	UPROPERTY(BlueprintReadOnly)
	APlayerHUD* PlayerHUD;
	
};
