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

	virtual void ServerInteract_Implementation() override;

	UFUNCTION(BlueprintImplementableEvent)
	void RestoreSatiationPoints();
	
};
