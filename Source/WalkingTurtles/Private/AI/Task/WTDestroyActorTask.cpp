// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/WTDestroyActorTask.h"

#include "AIController.h"
#include "WTAICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UWTDestroyActorTask::UWTDestroyActorTask()
{
    NodeName = "DestroyActor";
}

EBTNodeResult::Type UWTDestroyActorTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController) return EBTNodeResult::Failed;

    AWTAICharacter* AICharacter = AIController->GetPawn<AWTAICharacter>();
    if (!AICharacter) return EBTNodeResult::Failed;

    AICharacter->DestinationReached();

    return EBTNodeResult::Succeeded;
}
