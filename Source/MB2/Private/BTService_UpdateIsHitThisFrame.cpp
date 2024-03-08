// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_UpdateIsHitThisFrame.h"

#include "AlienAIController.h"
#include "BaseAlienCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

void UBTService_UpdateIsHitThisFrame::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* AIPawn = AIController->GetPawn();

	if(!(AIController && AIPawn))
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController or AIPawn NULL"))
		return;
	}

	ABaseAlienCharacter* AICharacter = Cast<ABaseAlienCharacter>(AIPawn);
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(OutputBoolKey.SelectedKeyName, AICharacter->IsHitThisFrame);
	AICharacter->IsHitThisFrame = false;
}
