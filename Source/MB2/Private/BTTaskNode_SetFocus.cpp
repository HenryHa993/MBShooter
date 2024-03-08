// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_SetFocus.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTaskNode_SetFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	AActor* FocusActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(InputActorKey.SelectedKeyName));

	if(!(AIController && FocusActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController or FocusActor NULL"));
		return EBTNodeResult::Failed;
	}

	AIController->SetFocus(FocusActor);
	return EBTNodeResult::Succeeded;
}
