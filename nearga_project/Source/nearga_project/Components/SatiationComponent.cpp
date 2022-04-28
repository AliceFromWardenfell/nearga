#include "SatiationComponent.h"

USatiationComponent::USatiationComponent() :
	MaxSatiation(100),
	InitialSatiation(MaxSatiation),
	HungerPower(5),
	HungerRate(0.5),
	DamageToInflict(5),
	DamageRate(1.0)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void USatiationComponent::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentSatiation = InitialSatiation;
	GetOwner()->GetWorldTimerManager().SetTimer(SatiationTimerHandle, this, &USatiationComponent::TakeHungerDamage, HungerRate, true, 0.5f);
}

void USatiationComponent::TakeHungerDamage()
{
	CurrentSatiation = FMath::Clamp(CurrentSatiation - HungerPower, 0, MaxSatiation);
}

void USatiationComponent::Eat(const int32 PointsToRestore)
{
	CurrentSatiation = FMath::Clamp(CurrentSatiation + PointsToRestore, 0, MaxSatiation);
	UE_LOG(LogTemp, Warning, TEXT("Restored %d satiation"), PointsToRestore);
}