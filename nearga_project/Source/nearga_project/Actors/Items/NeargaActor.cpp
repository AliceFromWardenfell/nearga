#include "NeargaActor.h"

ANeargaActor::ANeargaActor() :
	SecondsToHide(0.5)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ANeargaActor::BeginPlay()
{
	Super::BeginPlay();
	InfoWidgetComponentRef = FindComponentByClass<UInfoWidgetComponent>();
}

void ANeargaActor::ShowInfoOnTrace()
{
	if (InfoWidgetComponentRef)
	{
		InfoWidgetComponentRef->SetComponentTickEnabled(true);
		InfoWidgetComponentRef->GetUserWidgetObject()->SetVisibility(ESlateVisibility::Visible);
		GetWorldTimerManager().SetTimer(InfoTimerHandle, this, &ANeargaActor::HideWidget, SecondsToHide, false);
	}
}

void ANeargaActor::HideWidget() const
{
	InfoWidgetComponentRef->GetUserWidgetObject()->SetVisibility(ESlateVisibility::Hidden);
	InfoWidgetComponentRef->SetComponentTickEnabled(false);
}