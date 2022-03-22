// Fill out your copyright notice in the Description page of Project Settings.


#include "SatiationComponent.h"
#include "Blueprint/UserWidget.h"

// Sets default values for this component's properties
USatiationComponent::USatiationComponent()	:
	MaxSatiation(100),
	InitialSatiation(MaxSatiation),
	HungerPower(5),
	HungerRate(0.5),
	DamageToInflict(5),
	DamageRate(1.0)
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
	UE_LOG(LogTemp, Warning, TEXT("In satiation component BeginPlay"));
	
	PlayerHUD = Cast<APlayerHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	check(PlayerHUD != nullptr);
	
	CurrentSatiation = InitialSatiation;
	GetOwner()->GetWorldTimerManager().SetTimer(SatiationTimerHandle, this, &USatiationComponent::TakeHungerDamage, HungerRate, true, 0.5f);
	UE_LOG(LogTemp, Warning, TEXT("Satiation timer has been set"));

	//GetOwner()->GetWorldTimerManager().SetTimer(HealthTimerHandle, this, &USatiationComponent::InflictHealthDamage, DamageRate, true, 0.5f);
	//UE_LOG(LogTemp, Warning, TEXT("Health timer has been set"));
}

void USatiationComponent::TakeHungerDamage()
{
	CurrentSatiation = FMath::Clamp(CurrentSatiation - HungerPower, 0, MaxSatiation);
	//PlayerHUD->UpdateSatiation(CurrentSatiation, MaxSatiation);
	
	//UE_LOG(LogTemp, Warning, TEXT("Got %d damage to satiation"), HungerDamage);
	//UE_LOG(LogTemp, Warning, TEXT("Current satiation: %d"), CurrentSatiation);
}

void USatiationComponent::Eat(const int32 PointsToRestore)
{
	CurrentSatiation = FMath::Clamp(CurrentSatiation + PointsToRestore, 0, MaxSatiation);
	//PlayerHUD->UpdateSatiation(CurrentSatiation, MaxSatiation);

	UE_LOG(LogTemp, Warning, TEXT("Restored %d satiation"), PointsToRestore);
}

//void USatiationComponent::InflictHealthDamage()
//{
//	UE_LOG(LogTemp, Warning, TEXT("Inflicted %d damage from hunger"), DamageToInflict);
//}
