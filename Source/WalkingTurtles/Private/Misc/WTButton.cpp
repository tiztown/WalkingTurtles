// Fill out your copyright notice in the Description page of Project Settings.


#include "Misc/WTButton.h"

#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
AWTButton::AWTButton()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
    RootComponent = MeshComp;

    TextComponent = CreateDefaultSubobject<UTextRenderComponent>("TextComponent");
    TextComponent->SetupAttachment(MeshComp);

    ButtonMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("ButtonMeshComponent");
    ButtonMeshComp->SetupAttachment(GetRootComponent());

    BoxComp = CreateDefaultSubobject<UBoxComponent>("BaseCollisionComponent");
    BoxComp->SetupAttachment(GetRootComponent());
}

void AWTButton::Interact()
{
    UGameplayStatics::PlaySound2D(this, PressSound);

    OnInteract.Broadcast();
}


// Called when the game starts or when spawned
void AWTButton::BeginPlay()
{
    Super::BeginPlay();
}
