// Fill out your copyright notice in the Description page of Project Settings.


#include "ExpendableItem.h"

// Sets default values
AExpendableItem::AExpendableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExpendableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExpendableItem::ShowInfo()
{
	check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 2.0, FColor::Red, GetName());
}

// Called every frame
void AExpendableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

