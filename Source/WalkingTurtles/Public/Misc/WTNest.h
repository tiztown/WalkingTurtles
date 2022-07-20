// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WTNest.generated.h"

class UNiagaraSystem;
class UArrowComponent;
class USoundCue;
class UBehaviorTree;
class UTextRenderComponent;
class AWTAICharacter;
class AWTButton;
class UBoxComponent;


UCLASS(HideCategories = ("Variable", "Transform", "Sockets", "Shape", "Navigation", "ComponentTick", "Physics", "Tags", "Cooking", "HLOD",
        "Mobile", "Activation", "Component Replication", "Events", "Asset User Data", "Collision", "Rendering", "Input", "Actor", "LOD"))
class WALKINGTURTLES_API AWTNest : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AWTNest();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config", meta = (ClampMin = 0))
    int32 NestNumber = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    AWTButton* AssignedButton;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    TSubclassOf<AWTAICharacter> TurtleClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    UBehaviorTree* BehaviorTreeToUse;

    UPROPERTY(VisibleAnywhere)
    USceneComponent* BaseComponent;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* BaseMeshComponent;

    UPROPERTY(VisibleAnywhere)
    UTextRenderComponent* BaseMeshTextComponent;

    UPROPERTY(VisibleAnywhere)
    UArrowComponent* TurtleSpawnArrow;

    UPROPERTY(VisibleAnywhere)
    UBoxComponent* BoxCollisionComp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    AActor* DestinationActor;

    UPROPERTY(VisibleAnywhere)
    UTextRenderComponent* FinishTextComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
    USoundCue* SpawnSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
    UNiagaraSystem* SpawnVFX;

private:
    UFUNCTION()
    void OnNestActivated();
};
