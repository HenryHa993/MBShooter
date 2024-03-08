// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_PlayMontage.h"

#include "AIController.h"
#include "GameFramework/Character.h"

EBTNodeResult::Type UBTTaskNode_PlayMontage::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* AIPawn = AIController->GetPawn();
	ACharacter* AICharacter = Cast<ACharacter>(AIPawn);

	if(!(AIPawn && AIController && AICharacter))
	{
		UE_LOG(LogTemp, Warning, TEXT("AIPawn or AIController NULL"));
		return EBTNodeResult::Failed;
	}

	UAnimInstance* AIAnimInstance = AICharacter->GetMesh()->GetAnimInstance();
	AIAnimInstance->Montage_Play(AnimationMontage);

	return EBTNodeResult::Type();
}
