// Copyright Epic Games, Inc. All Rights Reserved.

#include "nearga_projectGameMode.h"
#include "nearga_projectCharacter.h"
#include "UObject/ConstructorHelpers.h"

Anearga_projectGameMode::Anearga_projectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
