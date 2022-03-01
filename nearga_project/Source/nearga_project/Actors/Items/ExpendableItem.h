// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "nearga_project/Interfaces/InteractInterface.h"
#include "ExpendableItem.generated.h"

UCLASS(Abstract)
class NEARGA_PROJECT_API AExpendableItem : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	

	AExpendableItem();

protected:

	virtual void BeginPlay() override;
	virtual void ShowInfo() override;

public:
	
	virtual void Tick(float DeltaTime) override;

};
