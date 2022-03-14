// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NeargaActor.h"
#include "ExpendableItem.generated.h"

UCLASS(Abstract)
class NEARGA_PROJECT_API AExpendableItem : public ANeargaActor
{
	GENERATED_BODY()
	
public:	

	AExpendableItem();

protected:

	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	int32 PointsToRestore;

};
