// Copyright Epic Games, Inc. All Rights Reserved.

#include "MB2GameMode.h"
#include "MB2Character.h"
#include "UObject/ConstructorHelpers.h"

AMB2GameMode::AMB2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;


}
