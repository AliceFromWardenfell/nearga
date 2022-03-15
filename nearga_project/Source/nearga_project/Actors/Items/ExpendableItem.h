// Fill out your copyright notice in the Description page of Project Settings.

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

protected:

	virtual void BeginPlay() override;
	virtual void ShowInfoOnTrace() override;

private:

	UFUNCTION()
	void HidePressKeyWidget();
	
public:
	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(Server, Reliable)
	void Interact();

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	int32 PointsToRestore;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> PressKeyWidgetClass;
	
private:
	
	UPROPERTY()
	UPressKeyToInteractWidget* PressKeyWidget;

	UPROPERTY()
	FTimerHandle PressKeyTimerHandle;
	
};
