// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_PlayMontage.generated.h"

/**
 * 
 */
UCLASS()
class MB2_API UBTTaskNode_PlayMontage : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
	UPROPERTY(EditAnywhere, DisplayName = "Animation Montage", Category = "Blackboard")
		UAnimMontage* AnimationMontage;
};
