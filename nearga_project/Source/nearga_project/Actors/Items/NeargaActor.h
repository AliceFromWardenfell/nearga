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
	virtual void ShowInfoOnTrace() override;

private:

	UFUNCTION()
	void HideWidget() const;
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InfoWidget")
	float SecondsToHide;
	UPROPERTY(BlueprintReadOnly, Category = "InfoWidget")
	UInfoWidgetComponent* InfoWidgetComponentRef;
	
private:
	
	UPROPERTY()
	FTimerHandle InfoTimerHandle;
	
};
