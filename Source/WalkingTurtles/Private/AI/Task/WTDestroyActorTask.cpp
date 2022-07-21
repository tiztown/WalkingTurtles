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
    UE_LOG(LogTemp, Warning, TEXT("Test1"));

    const AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController) return EBTNodeResult::Failed;

    UE_LOG(LogTemp, Warning, TEXT("Test2"));

    AWTAICharacter* AICharacter = AIController->GetPawn<AWTAICharacter>();
    if (!AICharacter) return EBTNodeResult::Failed;

    UE_LOG(LogTemp, Warning, TEXT("Test3"));

    
    AICharacter->DestinationReached();

    return EBTNodeResult::Succeeded;
}
