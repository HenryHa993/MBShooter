// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienAIController.h"

#include "BaseAlienCharacter.h"
#include "MB2GameState.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AAlienAIController::AAlienAIController()
{
	BehaviourTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviourTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

// This plays after
void AAlienAIController::BeginPlay()
{
	Super::BeginPlay();
	// Set player actor in BB
	AActor* PlayerActor = Cast<AActor>(GetWorld()->GetFirstPlayerController()->GetPawn());
	Blackboard->SetValueAsObject("PlayerActor", PlayerActor);

	// Listen for stage change
	AMB2GameState* GameState = GetWorld()->GetGameState<AMB2GameState>();
	if(!GameState)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameMode NULL"));
		return;
	}

	GameState->OnGameStageChangedDelegate.AddUniqueDynamic(this, &AAlienAIController::AwakeAlien);
}

// This runs before begin play
void AAlienAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (IsValid(Blackboard) && IsValid(BehaviourTree))
	{
		Blackboard->InitializeBlackboard(*(BehaviourTree->GetBlackboardAsset()));
	}

	ABaseAlienCharacter* AlienCharacter = Cast<ABaseAlienCharacter>(GetPawn());

	if (!AlienCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("AlienCharacter NULL"));
		return;
	}

	if (AlienCharacter->Stage == 0)
	{
		RunBT();
	}


}

void AAlienAIController::RunBT()
{
	if (IsValid(BehaviourTree))
	{
		RunBehaviorTree(BehaviourTree);
		BehaviourTreeComponent->StartTree(*BehaviourTree);
	}
}

void AAlienAIController::AwakeAlien(int NewStage)
{
	ABaseAlienCharacter* AlienCharacter = Cast<ABaseAlienCharacter>(GetPawn());

	if(!AlienCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("AlienCharacter NULL"));
		return;
	}

	if(AlienCharacter->Stage == NewStage)
	{
		RunBT();
	}
}
