// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "nearga_project/Interfaces/InteractInterface.h"
#include "nearga_project/Widgets/ObjectInfoWidget.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "NeargaActor.generated.h"

UCLASS(Abstract)
class NEARGA_PROJECT_API ANeargaActor : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	

	ANeargaActor();
	
protected:

	virtual void BeginPlay() override;
	virtual void ShowInfoOnTrace() override;

public:	

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void AddInfoWidgetToViewport(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void RemoveInfoWidgetFromViewport(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> ObjectInfoWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	float SecondsToHide;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	UObjectInfoWidget* ObjectInfoWidget;
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	// float DisplayRadius;
	
protected:

	UPROPERTY()
	USphereComponent* ObjectInfoRadius;

	UPROPERTY()
	FTimerHandle InfoTimerHandle;

private:

	UFUNCTION()
	void HideWidget();
	
};
