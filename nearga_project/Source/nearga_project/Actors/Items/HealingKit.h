#pragma once

#include "CoreMinimal.h"
#include "ExpendableItem.h"
#include "HealingKit.generated.h"

UCLASS()
class NEARGA_PROJECT_API AHealingKit : public AExpendableItem
{
	GENERATED_BODY()

public:

	AHealingKit();

protected:

	virtual void Server_Interact_Implementation(ACharacter* InteractingCharacter) override;

	UFUNCTION(BlueprintImplementableEvent)
	void RestoreHealthPoints();
	
};
