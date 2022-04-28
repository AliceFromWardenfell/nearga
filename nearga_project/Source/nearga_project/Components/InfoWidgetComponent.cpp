#include "InfoWidgetComponent.h"

void UInfoWidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	
	SetComponentTickEnabled(false);
	GetUserWidgetObject()->SetVisibility(ESlateVisibility::Hidden);
}