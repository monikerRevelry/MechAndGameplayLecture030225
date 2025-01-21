// Copyright Epic Games, Inc. All Rights Reserved.

#include "UECvsBPGameMode.h"
#include "UECvsBPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUECvsBPGameMode::AUECvsBPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
