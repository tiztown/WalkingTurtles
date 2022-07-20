// Fill out your copyright notice in the Description page of Project Settings.


#include "Misc/WTNest.h"

#include "AIController.h"
#include "NiagaraFunctionLibrary.h"
#include "WTAICharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/WTButton.h"
#include "Sound/SoundCue.h"

// Sets default values
AWTNest::AWTNest()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    BaseComponent = CreateDefaultSubobject<USceneComponent>("BaseComponent");
    SetRootComponent(BaseComponent);

    BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
    BaseMeshComponent->SetupAttachment(GetRootComponent());

    BaseMeshTextComponent = CreateDefaultSubobject<UTextRenderComponent>("BaseMeshTextComponent");
    BaseMeshTextComponent->SetupAttachment(BaseMeshComponent);

    TurtleSpawnArrow = CreateDefaultSubobject<UArrowComponent>("TurtleSpawnArrow");
    TurtleSpawnArrow->SetupAttachment(BaseMeshComponent);

    BoxCollisionComp = CreateDefaultSubobject<UBoxComponent>("BoxCollisionComponent");
    BoxCollisionComp->SetupAttachment(BaseMeshComponent);

    FinishTextComponent = CreateDefaultSubobject<UTextRenderComponent>("FinishTextComponent");
    FinishTextComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AWTNest::BeginPlay()
{
    Super::BeginPlay();

    if (!DestinationActor || !AssignedButton || !BehaviorTreeToUse) return;

    AssignedButton->OnInteract.AddDynamic(this, &AWTNest::OnNestActivated);
    AssignedButton->SetNumber(NestNumber);

    const FText NumberText = FText::FromString("Nest " + FString::FromInt(NestNumber));

    FVector FinishTextLocation = DestinationActor->GetActorLocation();
    FinishTextLocation.Z += 200;

    FinishTextComponent->SetWorldLocation(FinishTextLocation);

    BaseMeshTextComponent->SetText(NumberText);
    FinishTextComponent->SetText(NumberText);
}

void AWTNest::OnNestActivated()
{
    if (!BehaviorTreeToUse) return;
    UE_LOG(LogTemp, Warning, TEXT("TurtleSpawned"));

    AWTAICharacter* Turtle = GetWorld()->SpawnActor<AWTAICharacter>(TurtleClass, TurtleSpawnArrow->GetComponentLocation(), TurtleSpawnArrow->GetComponentRotation());
    if (Turtle)
    {
        Turtle->SetDestinations(BaseMeshComponent->GetComponentLocation(), DestinationActor->GetActorLocation());

        UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, SpawnVFX, Turtle->GetActorLocation());
        UGameplayStatics::PlaySound2D(this, SpawnSound);

        AAIController* TurtleController = Turtle->GetController<AAIController>();
        if (TurtleController)
        {
            TurtleController->RunBehaviorTree(BehaviorTreeToUse);
        }
    }
}
