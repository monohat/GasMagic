// Copyright Epic Games, Inc. All Rights Reserved.

#include "GasMagicGameMode.h"
#include "GasMagicCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGasMagicGameMode::AGasMagicGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
