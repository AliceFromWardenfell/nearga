#pragma once

#include "CoreMinimal.h"
#include "ExpendableItem.h"
#include "Banana.generated.h"

UCLASS()
class NEARGA_PROJECT_API ABanana : public AExpendableItem
{
	GENERATED_BODY()
	
public:

	ABanana();

protected:

	virtual void Server_Interact_Implementation(ACharacter* InteractingCharacter) override;

	UFUNCTION(BlueprintImplementableEvent)
	void RestoreSatiationPoints();
	
};
