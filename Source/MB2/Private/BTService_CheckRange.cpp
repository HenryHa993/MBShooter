// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_CheckRange.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include <BehaviorTree/BTTaskNode.h>

UBTService_CheckRange::UBTService_CheckRange()
{
}

void UBTService_CheckRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// AIController, AIPawn, PlayerController
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* AIPawn = AIController->GetPawn();

	if(!(AIController && AIPawn))
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller or Pawn NULL"));
		return;
	}

	// Get input vector and
	FVector AILocation = AIPawn->GetActorLocation();
	FVector TargetLocation = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(InputVectorKey.SelectedKeyName))->GetActorLocation();

	float DistanceToLocation = FVector::Distance(AILocation, TargetLocation);

	//UE_LOG(LogTemp, Warning, TEXT("Distance to player: %d"), DistanceToLocation);
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(OutputBoolKey.SelectedKeyName, DistanceToLocation < Range);
}
