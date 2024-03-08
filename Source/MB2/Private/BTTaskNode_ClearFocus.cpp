// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_ClearFocus.h"

#include "AIController.h"

EBTNodeResult::Type UBTTaskNode_ClearFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();

	if(!AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController NULL"));
		return EBTNodeResult::Failed;
	}

	AIController->ClearFocus(EAIFocusPriority::LastFocusPriority);
	return EBTNodeResult::Succeeded;
}
