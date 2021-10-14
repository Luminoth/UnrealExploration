// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBase.h"

#include "PaperFlipbookComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

APlayerBase::APlayerBase() : Health(0)
{
    // only allow yaw rotation
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = true;
    bUseControllerRotationRoll = false;

    // TODO: remove this when the real character exists
    CreateTemporaryMesh();

    // setup the camera
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 600.0f;
    CameraBoom->bDoCollisionTest = false;
    CameraBoom->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

    SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
    //SideViewCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
    SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    SideViewCameraComponent->bUsePawnControlRotation = false;
    SideViewCameraComponent->bAutoActivate = true;

    // replicate animations over the network
    GetSprite()->SetIsReplicated(true);
    bReplicates = true;
}

void APlayerBase::CreateTemporaryMesh()
{
    // create a temporary capsule mesh for the player
    UStaticMeshComponent *TemporaryMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Temporary Mesh"));
    UStaticMesh *TemporaryMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'")).Object;
    TemporaryMeshComponent->SetStaticMesh(TemporaryMesh);
    TemporaryMeshComponent->SetupAttachment(GetSprite());
}

void APlayerBase::Damage(int amount)
{
    Health -= amount;

    if (Health <= 0)
    {
        Health = 0;
        UE_LOG(LogTemp, Warning, TEXT("Dead"));
    }
}
