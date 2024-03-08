// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_FindRandomLocationCPP.h"
#include "NavigationSystem.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UMyBTTask_FindRandomLocationCPP::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Need reference to AI Controller
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* AIPawn = AIController->GetPawn();

	if (!AIPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Pawn NULL"));
		return EBTNodeResult::Failed;
	}

	// Get AI location
	FVector Origin = AIPawn->GetActorLocation();

	// Nav mesh stuff
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(AIPawn->GetWorld());
	FNavLocation RandomLocation;

	// If both are valid then assign blackboard 
	if (IsValid(NavSystem) && NavSystem->GetRandomPointInNavigableRadius(Origin, SearchRadius, RandomLocation))
	{
		AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, RandomLocation.Location);
	}

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
