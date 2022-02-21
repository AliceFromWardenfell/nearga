// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), DisplayName="HealthComponent" )
class NEARGA_PROJECT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnTakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	int32 MaxHealth;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Health")
	int32 InitialHealth;
	UPROPERTY(BlueprintReadOnly)
	int32 CurrentHealth;
	
};
