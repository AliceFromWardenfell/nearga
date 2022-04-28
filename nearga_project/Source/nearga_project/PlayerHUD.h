#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Widgets/PlayerPropertiesWidget.h"
#include "PlayerHUD.generated.h"

UCLASS()
class NEARGA_PROJECT_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void UpdateSatiation(const int32 CurrentSatiation, const int32 MaxSatiation) const;
	UFUNCTION(BlueprintCallable)
	void UpdateHealth(const int32 CurrentHealth, const int32 MaxHealth) const;
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> PlayerWidgetClass;

	UPROPERTY()
	UPlayerPropertiesWidget* PlayerPropertiesWidget;
	
};
