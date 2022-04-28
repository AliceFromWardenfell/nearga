#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerPropertiesWidget.generated.h"

UCLASS()
class NEARGA_PROJECT_API UPlayerPropertiesWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateHealth(int32 CurrentHealth, int32 MaxHealth);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateSatiation(int32 CurrentSatiation, int32 MaxSatiation);
	
};