#include "HealthComponent.h"

UHealthComponent::UHealthComponent() :
	MaxHealth(100),
	InitialHealth(MaxHealth)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentHealth = InitialHealth;
}

void UHealthComponent::TakeDamage(const int32 Damage)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0, MaxHealth);
}

void UHealthComponent::RestoreHealth(const int32 PointsToRestore)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + PointsToRestore, 0, MaxHealth);
	UE_LOG(LogTemp, Warning, TEXT("Restored %d HP"), PointsToRestore);
}