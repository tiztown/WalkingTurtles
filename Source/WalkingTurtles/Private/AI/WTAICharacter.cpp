// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/WTAICharacter.h"

#include "AIController.h"
#include "BrainComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
AWTAICharacter::AWTAICharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void AWTAICharacter::SetDestinations(const FVector StartLocation, const FVector EndLocation)
{
    DestinationStartLocation = StartLocation;
    DestinationEndLocation = EndLocation;
}

void AWTAICharacter::GetDestinations(FVector& StartLocation, FVector& EndLocation) const
{
    StartLocation = DestinationStartLocation;
    EndLocation = DestinationEndLocation;
}

void AWTAICharacter::DestinationReached()
{
    const AAIController* AIController = GetController<AAIController>();
    if (AIController)
    {
        AIController->BrainComponent->Cleanup();
    }

    if (DestroySound)
    {
        UGameplayStatics::PlaySound2D(this, DestroySound);
    }

    if (DestroyVFX)
    {
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, DestroyVFX, GetActorLocation());
    }

    if (CurrentSound)
    {
        CurrentSound->Deactivate();
        CurrentSound->DestroyComponent();
    }

    Destroy();
}

void AWTAICharacter::BeginPlay()
{
    Super::BeginPlay();

    CurrentSound = UGameplayStatics::SpawnSoundAttached(WalkSound, GetRootComponent());
}


// Called every frame
void AWTAICharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (CurrentSound)
    {
        if (!GetVelocity().Size() && CurrentSound->IsPlaying())
        {
            CurrentSound->Stop();
        }
        else if (GetVelocity().Size() && !CurrentSound->IsPlaying())
        {
            CurrentSound->Play();
        }
    }
}
