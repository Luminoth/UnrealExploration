// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealExplorationGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class UNREALEXPLORATION_API AUnrealExplorationGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player, meta = (AllowPrivateAccess = "true"))
    int32 PlayerHealth;

public:
    AUnrealExplorationGameModeBase();

    FORCEINLINE int32 GetPlayerHealth() const { return PlayerHealth; }
};
