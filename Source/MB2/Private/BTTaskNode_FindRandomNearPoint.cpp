// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_FindRandomNearPoint.h"
#include "NavigationSystem.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTaskNode_FindRandomNearPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* AIPawn = AIController->GetPawn();

	if (!AIPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Pawn NULL"));
		return EBTNodeResult::Failed;
	}

	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(InputVectorKey.SelectedKeyName);

	// Nav mesh stuff
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(AIPawn->GetWorld());
	FNavLocation RandomLocation;

	// If both are valid then assign blackboard 
	if (IsValid(NavSystem) && NavSystem->GetRandomPointInNavigableRadius(Origin, SearchRadius, RandomLocation))
	{
		AIController->GetBlackboardComponent()->SetValueAsVector(OutputVectorKey.SelectedKeyName, RandomLocation.Location);
	}

	return EBTNodeResult::Succeeded;
}
