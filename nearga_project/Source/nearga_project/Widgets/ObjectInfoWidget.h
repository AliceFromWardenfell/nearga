#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectInfoWidget.generated.h"

UCLASS(Abstract)
class NEARGA_PROJECT_API UObjectInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Properties")
	FName ItemName;
	
};
