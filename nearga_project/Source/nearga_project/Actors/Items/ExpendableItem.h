#pragma once

#include "CoreMinimal.h"
#include "NeargaActor.h"
#include "nearga_project/Widgets/PressKeyToInteractWidget.h"
#include "ExpendableItem.generated.h"

UCLASS(Abstract)
class NEARGA_PROJECT_API AExpendableItem : public ANeargaActor
{
	GENERATED_BODY()
	
public:	

	AExpendableItem();

	UFUNCTION(Server, Reliable)
	void ServerInteract();

protected:

	virtual void BeginPlay() override;
	virtual void ShowInfoOnTrace() override;

private:

	UFUNCTION(BlueprintCallable)
	void HidePressKeyWidget() const;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	FName ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	int32 PointsToRestore;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> PressKeyWidgetClass;
	UPROPERTY()
	UPressKeyToInteractWidget* PressKeyWidget;
	UPROPERTY()
	FTimerHandle PressKeyTimerHandle;
	
};
