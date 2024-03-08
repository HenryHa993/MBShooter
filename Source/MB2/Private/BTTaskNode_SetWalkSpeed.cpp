// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_SetWalkSpeed.h"
#include "AIController.h"
#include "BaseAlienCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

EBTNodeResult::Type UBTTaskNode_SetWalkSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* AIPawn = AIController->GetPawn();
	//ABaseAlienCharacter* AICharacter = Cast<ABaseAlienCharacter>(AIPawn);
	ACharacter* AICharacter = Cast<ACharacter>(AIPawn);

	if(!(AIController && AIPawn && AICharacter))
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller or Pawn or Character NULL"))
		return EBTNodeResult::Failed;
	}

	UCharacterMovementComponent* MovementComponent = AICharacter->GetCharacterMovement();
	MovementComponent->MaxWalkSpeed = Speed;
	return EBTNodeResult::Succeeded;
}
