// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WTNest.generated.h"

class AWTAICharacter;
class AWTButton;
class UNiagaraEmitter;
class USphereComponent;
class UBoxComponent;
UCLASS()
class WALKINGTURTLES_API AWTNest : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AWTNest();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
    AWTButton* AssignedButton;

    TSubclassOf<AWTAICharacter> TurtleClass; 

    UPROPERTY(VisibleAnywhere)
    USceneComponent* RootComponent;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* BaseMeshComponent;

    UPROPERTY(VisibleAnywhere)
    USceneComponent* TurtleSpawnPoint;

    UPROPERTY(VisibleAnywhere)
    UBoxComponent* BoxCollisionComp;

    UPROPERTY(VisibleAnywhere)
    USphereComponent* DestroySphereComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
    USoundBase* SpawnSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
    USoundBase* DestroySound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
    UNiagaraEmitter* SpawnNiagaraEmitter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
    UNiagaraEmitter* DestroyNiagaraEmitter;

private:
    UFUNCTION()
    void OnNestActivated();
};
