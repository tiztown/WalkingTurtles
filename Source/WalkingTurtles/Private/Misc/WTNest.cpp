// Fill out your copyright notice in the Description page of Project Settings.


#include "Misc/WTNest.h"

#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Misc/WTButton.h"

// Sets default values
AWTNest::AWTNest()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
    BaseMeshComponent->SetupAttachment(GetRootComponent());

    TurtleSpawnPoint = CreateDefaultSubobject<USceneComponent>("TurtleSpawnPoint");
    TurtleSpawnPoint->SetupAttachment(BaseMeshComponent);

    BoxCollisionComp = CreateDefaultSubobject<UBoxComponent>("BoxCollisionComponent");
    BoxCollisionComp->SetupAttachment(BaseMeshComponent);

    DestroySphereComponent = CreateDefaultSubobject<USphereComponent>("DestroySphereComponent");
    DestroySphereComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AWTNest::BeginPlay()
{
    Super::BeginPlay();

    if (AssignedButton)
    {
        AssignedButton->OnInteract.AddDynamic(this, &AWTNest::OnNestActivated);
    }
}

void AWTNest::OnNestActivated()
{
    UE_LOG(LogTemp, Warning, TEXT("TurtleSpawned"));
    // Spawn Turtle
    // Set BT to Turtle
    // Spawn sound
    // Spawn Emitter
}
