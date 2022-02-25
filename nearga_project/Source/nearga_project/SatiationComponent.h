// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SatiationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Satiation")
	int32 MaxSatiation;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Satiation")
	int32 InitialSatiation;
	UPROPERTY(BlueprintReadOnly)
	int32 CurrentSatiation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Satiation")
	int32 HungerDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Satiation")
	float HungerDamageRate;
	
	UPROPERTY()
	FTimerHandle  TimerHandle;
	
};
