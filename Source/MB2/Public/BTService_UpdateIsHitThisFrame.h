// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_UpdateIsHitThisFrame.generated.h"

/**
 * 
 */
UCLASS()
class MB2_API UBTService_UpdateIsHitThisFrame : public UBTService
{
	GENERATED_BODY()

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, DisplayName = "Output Boolean Key", Category = "Blackboard")
		FBlackboardKeySelector OutputBoolKey;
};
