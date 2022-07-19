// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WTButton.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractSignature)


class UNiagaraSystem;
class UBoxComponent;
class USphereComponent;
UCLASS()
class WALKINGTURTLES_API AWTButton : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AWTButton();

    void Interact();

    FOnInteractSignature OnInteract;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    USphereComponent* SphereComp;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComp;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* ButtonMeshComp;

    UPROPERTY(VisibleAnywhere)
    UBoxComponent* BoxComp;

    UPROPERTY(EditAnywhere, Category = "FX")
    USoundBase* PressSound;
};
