#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, DisplayName="HealthComponent" )
class NEARGA_PROJECT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UHealthComponent();

protected:
	
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
	
};
