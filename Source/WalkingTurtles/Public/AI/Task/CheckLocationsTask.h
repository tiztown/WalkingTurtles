// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CheckLocationsTask.generated.h"

/**
 * 
 */
UCLASS()
class WALKINGTURTLES_API UCheckLocationsTask : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UCheckLocationsTask();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector StartLocationKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector EndLocationKey;
};
