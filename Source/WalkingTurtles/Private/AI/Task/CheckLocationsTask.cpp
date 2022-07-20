// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/CheckLocationsTask.h"

#include "AIController.h"
#include "WTAICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UCheckLocationsTask::UCheckLocationsTask()
{
    NodeName = "CheckLocations";
}

EBTNodeResult::Type UCheckLocationsTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const AAIController* AIController = OwnerComp.GetAIOwner();
    UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent();
    if (!AIController || !BBComp) return EBTNodeResult::Failed;

    const AWTAICharacter* AICharacter = AIController->GetPawn<AWTAICharacter>();
    if (!AICharacter) return EBTNodeResult::Failed;

    FVector EndLocation;
    FVector StartLocation;
    AICharacter->GetDestinations(StartLocation, EndLocation);

    BBComp->SetValueAsVector(StartLocationKey.SelectedKeyName, StartLocation);
    BBComp->SetValueAsVector(EndLocationKey.SelectedKeyName, EndLocation);

    return EBTNodeResult::Succeeded;
}
