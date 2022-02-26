// Fill out your copyright notice in the Description page of Project Settings.


 #include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()	:
	MaxHealth(100),
	InitialHealth(MaxHealth),
	CurrentHealth(InitialHealth)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerHUD = Cast<APlayerHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	check(PlayerHUD != nullptr);

	CurrentHealth = InitialHealth;
}

void UHealthComponent::TakeDamage(const int32 Damage)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0, MaxHealth);
	
	UE_LOG(LogTemp, Warning, TEXT("Got %d damage"), Damage);

	
}

void UHealthComponent::RestoreHealth(const int32 PointsToRestore)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + PointsToRestore, 0, MaxHealth);
	UE_LOG(LogTemp, Warning, TEXT("Restored %d HP"), PointsToRestore);
}
