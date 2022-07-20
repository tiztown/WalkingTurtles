// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WTAICharacter.generated.h"

class UNiagaraSystem;
class USoundCue;
UCLASS(HideCategories = ("Variable", "Transform", "Sockets", "Shape", "Navigation", "ComponentTick", "Physics", "Tags", "Cooking", "HLOD",
    "Mobile", "Activation", "Component Replication", "Events", "Asset User Data", "Collision", "Rendering", "Input", "Actor", "LOD"))
class WALKINGTURTLES_API AWTAICharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AWTAICharacter();

    void SetDestinations(FVector StartLocation, FVector EndLocation);

    void GetDestinations(FVector& StartLocation, FVector& EndLocation) const;

    void DestinationReached();


protected:
    virtual void BeginPlay() override;

    UPROPERTY()
    UAudioComponent* CurrentSound;

    FVector DestinationEndLocation;

    FVector DestinationStartLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    USoundCue* DestroySound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    USoundCue* WalkSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UNiagaraSystem* DestroyVFX;


public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
