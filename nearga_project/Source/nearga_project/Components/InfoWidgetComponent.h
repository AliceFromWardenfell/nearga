#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "InfoWidgetComponent.generated.h"

UCLASS()
class NEARGA_PROJECT_API UInfoWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	
};
