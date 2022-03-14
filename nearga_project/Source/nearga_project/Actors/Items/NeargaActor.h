// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "nearga_project/Interfaces/InteractInterface.h"
#include "nearga_project/Components/InfoWidgetComponent.h"
#include "NeargaActor.generated.h"

UCLASS(Abstract)
class NEARGA_PROJECT_API ANeargaActor : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	

	ANeargaActor();
	
protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void ShowInfoOnTrace() override;

public:

	virtual void Tick(float DeltaTime) override;

	// UFUNCTION()
	// void AddInfoWidgetToViewport(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	//
	// UFUNCTION()
	// void RemoveInfoWidgetFromViewport(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:

	bool bIsInteractable;
	// UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	// TSubclassOf<UUserWidget> ObjectInfoWidgetClass;
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InfoWidget")
	float SecondsToHide;
	
	UPROPERTY(BlueprintReadOnly, Category = "InfoWidget")
	UInfoWidgetComponent* InfoWidgetComponentRef;
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	// float DisplayRadius;
	
protected:

	// UPROPERTY()
	// USphereComponent* ObjectInfoRadius;
	//
	UPROPERTY()
	FTimerHandle InfoTimerHandle;

private:

	UFUNCTION()
	void HideWidget();
	
};
