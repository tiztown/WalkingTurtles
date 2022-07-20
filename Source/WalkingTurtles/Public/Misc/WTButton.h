// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "WTButton.generated.h"


class USoundCue;
class UTextRenderComponent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractSignature);


class UNiagaraSystem;
class UBoxComponent;
UCLASS()
class WALKINGTURTLES_API AWTButton : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AWTButton();

    void Interact();

    FOnInteractSignature OnInteract;

    // Set text in TextComponent from given number
    void SetNumber(int32 Number) const { TextComponent->SetText(FText::AsNumber(Number)); }

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComp;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* ButtonMeshComp;

    UPROPERTY(VisibleAnywhere)
    UBoxComponent* BoxComp;

    UPROPERTY(VisibleAnywhere)
    UTextRenderComponent* TextComponent;

    UPROPERTY(EditAnywhere, Category = "FX")
    USoundCue* PressSound;
};
