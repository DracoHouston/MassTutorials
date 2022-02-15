// Copyright Epic Games, Inc. All Rights Reserved.

#include "MassTutorialsGameMode.h"
#include "MassTutorialsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMassTutorialsGameMode::AMassTutorialsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
