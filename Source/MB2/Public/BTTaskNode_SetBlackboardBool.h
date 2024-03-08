// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_SetBlackboardBool.generated.h"

/**
 * 
 */
UCLASS()
class MB2_API UBTTaskNode_SetBlackboardBool : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, DisplayName = "Boolean Key", Category = "Blackboard")
		FBlackboardKeySelector BoolKey;

public:
	UPROPERTY(EditAnywhere, DisplayName = "Bool Value", Category = "Blackboard")
		bool BoolValue;
};
