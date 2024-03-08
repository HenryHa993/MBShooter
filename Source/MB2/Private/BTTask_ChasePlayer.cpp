// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ChasePlayer.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Navigation/PathFollowingComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

EBTNodeResult::Type UBTTask_ChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get controllers
	AAIController* AIController = OwnerComp.GetAIOwner();
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	//if(AIController && PlayerController)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AI or Player Controller NULL"))
	//	return EBTNodeResult::Failed;
	//}

	FVector End = PlayerController->GetPawn()->GetActorLocation();

	FAIMoveRequest MoveRequest;
	MoveRequest.SetGoalLocation(End);
	MoveRequest.SetAcceptanceRadius(100.f);

	AIController->MoveTo(MoveRequest);

	//FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;

}
