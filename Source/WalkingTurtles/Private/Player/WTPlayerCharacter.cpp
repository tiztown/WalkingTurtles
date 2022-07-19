// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/WTPlayerCharacter.h"

#include "Camera/CameraComponent.h"

// Sets default values
AWTPlayerCharacter::AWTPlayerCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComp->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AWTPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame

void AWTPlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input

void AWTPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("LookUp", this, &AWTPlayerCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("Turn", this, &AWTPlayerCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAxis("MoveForward", this, &AWTPlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AWTPlayerCharacter::MoveRight);
    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AWTPlayerCharacter::Interact);
}

void AWTPlayerCharacter::MoveForward(float Value)
{
    if (Value == 0.0f) return;
    AddMovementInput(GetActorForwardVector(), Value);
}

void AWTPlayerCharacter::MoveRight(float Value)
{
    if (Value == 0.0f) return;
    AddMovementInput(GetActorRightVector(), Value);
}

void AWTPlayerCharacter::Interact()
{
}
