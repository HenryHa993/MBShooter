// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_FindRandomNearPoint.generated.h"

/**
 * 
 */
UCLASS()
class MB2_API UBTTaskNode_FindRandomNearPoint : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, DisplayName = "Input Vector Key", Category = "Blackboard")
		FBlackboardKeySelector InputVectorKey;


	UPROPERTY(EditAnywhere, DisplayName = "Output Vector Key", Category = "Blackboard")
		FBlackboardKeySelector OutputVectorKey;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search")
		float SearchRadius = 1000.0f;
};
