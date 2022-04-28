#include "PlayerHUD.h"

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	if (PlayerWidgetClass)
	{
		PlayerPropertiesWidget = CreateWidget<UPlayerPropertiesWidget>(GetWorld(), PlayerWidgetClass);
		check(PlayerPropertiesWidget != nullptr);
		PlayerPropertiesWidget->AddToViewport();
	}
}

void APlayerHUD::UpdateSatiation(const int32 CurrentSatiation, const int32 MaxSatiation) const
{
	PlayerPropertiesWidget->UpdateSatiation(CurrentSatiation, MaxSatiation);
}

void APlayerHUD::UpdateHealth(const int32 CurrentHealth, const int32 MaxHealth) const
{
	PlayerPropertiesWidget->UpdateHealth(CurrentHealth, MaxHealth);
}