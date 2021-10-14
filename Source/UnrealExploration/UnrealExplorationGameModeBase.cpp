// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealExplorationGameModeBase.h"
#include "PlayerBase.h"

AUnrealExplorationGameModeBase::AUnrealExplorationGameModeBase()
{
    DefaultPawnClass = APlayerBase::StaticClass();
}
