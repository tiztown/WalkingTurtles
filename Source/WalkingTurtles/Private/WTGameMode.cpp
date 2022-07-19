// Fill out your copyright notice in the Description page of Project Settings.


#include "WTGameMode.h"

#include "Player/WTPlayerCharacter.h"
#include "Player/WTPlayerController.h"

AWTGameMode::AWTGameMode()
{
    DefaultPawnClass = AWTPlayerCharacter::StaticClass();
    PlayerControllerClass = AWTPlayerController::StaticClass();
}
