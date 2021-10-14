// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBase.h"

APlayerBase::APlayerBase()
{
    RootComponent = CreateTemporaryMesh();
}

UStaticMeshComponent *APlayerBase::CreateTemporaryMesh()
{
    // create a temporary capsule mesh for the player
    UStaticMeshComponent *TemporaryMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Temporary Mesh"));
    UStaticMesh *TemporaryMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'")).Object;
    TemporaryMeshComponent->SetStaticMesh(TemporaryMesh);

    return TemporaryMeshComponent;
}
