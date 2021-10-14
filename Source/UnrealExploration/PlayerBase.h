// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PlayerBase.generated.h"

/**
 *
 */
UCLASS()
class UNREALEXPLORATION_API APlayerBase : public APaperCharacter
{
    GENERATED_BODY()

    UStaticMeshComponent *CreateTemporaryMesh();

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent *CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent *SideViewCameraComponent;

public:
    APlayerBase();
};
