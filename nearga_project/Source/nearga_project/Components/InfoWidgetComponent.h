#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"
#include "nearga_project/Interfaces/InteractInterface.h"
#include "InfoWidgetComponent.generated.h"

UCLASS()
class NEARGA_PROJECT_API UInfoWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:

	UInfoWidgetComponent(const FObjectInitializer& ObjectInitializer);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:

	virtual void BeginPlay() override;

	// UFUNCTION()
	// void AddInfoWidgetToViewport();
	// UFUNCTION()
	// void RemoveInfoWidgetFromViewport();
	
private:

	UPROPERTY()
	USphereComponent* InfoRadius;
	
};
