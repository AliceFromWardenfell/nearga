#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SatiationComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, DisplayName="SatiationComponent" )
class NEARGA_PROJECT_API USatiationComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	USatiationComponent();

protected:

	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void TakeHungerDamage();
	UFUNCTION(BlueprintCallable)
	void Eat(const int32 PointsToRestore);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Satiation")
	int32 MaxSatiation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Satiation")
	int32 InitialSatiation;
	UPROPERTY(BlueprintReadOnly)
	int32 CurrentSatiation;

	// How many points one hunger-tick inflicts to satiation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Satiation")
	int32 HungerPower;
	// How often one hunger-tick happens in seconds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Satiation")
	float HungerRate;

	// How many points one damage-tick inflicts to health if hungry
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DamageFromHunger")
	int32 DamageToInflict;
	// How often one damage-tick happens in seconds if hungry
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DamageFromHunger")
	float DamageRate;
	
	UPROPERTY()
	FTimerHandle SatiationTimerHandle;
	
};