// Fill out your copyright notice in the Description page of Project Settings.


#include "SatiationComponent.h"
#include "PlayerHUD.h"
#include "Blueprint/UserWidget.h"

// Sets default values for this component's properties
USatiationComponent::USatiationComponent()	:
	MaxSatiation(100),
	InitialSatiation(MaxSatiation),
	CurrentSatiation(InitialSatiation),
	HungerDamage(5),
	HungerDamageRate(0.5)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	UE_LOG(LogTemp, Warning, TEXT("SatiationComponent has constructed"));
}

// Called when the game starts
void USatiationComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("In satioation component BeginPlay"));
	
	PlayerHUD = Cast<APlayerHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	check(PlayerHUD != nullptr);
	
	AActor* Owner = GetOwner();
	Owner->GetWorldTimerManager().SetTimer(TimerHandle, this, &USatiationComponent::TakeHungerDamage, HungerDamageRate, true, 0.5f);
	UE_LOG(LogTemp, Warning, TEXT("Timer has been set"));
}

void USatiationComponent::TakeHungerDamage()
{
	CurrentSatiation = FMath::Clamp(CurrentSatiation - HungerDamage, 0, MaxSatiation);
	PlayerHUD->UpdateSatiation(CurrentSatiation, MaxSatiation);
	UE_LOG(LogTemp, Warning, TEXT("Got %d hunger damage"), HungerDamage);
}

void USatiationComponent::Eat(const int32 PointsToRestore)
{
	CurrentSatiation = FMath::Clamp(CurrentSatiation + PointsToRestore, 0, MaxSatiation);
	PlayerHUD->UpdateSatiation(CurrentSatiation, MaxSatiation);
	UE_LOG(LogTemp, Warning, TEXT("Restored %d satiation"), PointsToRestore);
}


// Called every frame
void USatiationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}
