#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractInterface.generated.h"

UINTERFACE(MinimalAPI)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};

class NEARGA_PROJECT_API IInteractInterface
{
	GENERATED_BODY()

public:

	UFUNCTION()
	virtual void ShowInfoOnTrace() = 0;
	
};
