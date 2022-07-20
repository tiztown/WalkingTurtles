// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "WTDestroyActorTask.generated.h"

/**
 * 
 */
UCLASS()
class WALKINGTURTLES_API UWTDestroyActorTask : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UWTDestroyActorTask();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
