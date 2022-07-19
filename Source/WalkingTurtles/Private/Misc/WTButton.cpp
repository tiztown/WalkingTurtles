// Fill out your copyright notice in the Description page of Project Settings.


#include "Misc/WTButton.h"

#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWTButton::AWTButton()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
    RootComponent = MeshComp;

    ButtonMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("ButtonMeshComponent");
    ButtonMeshComp->SetupAttachment(GetRootComponent());

    SphereComp = CreateDefaultSubobject<USphereComponent>("ButtonCollisionComponent");
    SphereComp->SetupAttachment(ButtonMeshComp);

    BoxComp = CreateDefaultSubobject<UBoxComponent>("BaseCollisionComponent");
    BoxComp->SetupAttachment(GetRootComponent());
}

void AWTButton::Interact()
{
    UGameplayStatics::PlaySoundAtLocation(this, PressSound, ButtonMeshComp->GetComponentLocation());

    OnInteract.Broadcast();
}

// Called when the game starts or when spawned
void AWTButton::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AWTButton::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
