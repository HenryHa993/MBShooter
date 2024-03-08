// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_SetBlackboardBool.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTaskNode_SetBlackboardBool::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();

	if(!AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController NULL"));
		return EBTNodeResult::Failed;
	}

	AIController->GetBlackboardComponent()->SetValueAsBool(BoolKey.SelectedKeyName, BoolValue);
	return EBTNodeResult::Succeeded;
}
