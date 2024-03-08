// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_FindRandomLocationCPP.generated.h"

/**
 * 
 */
UCLASS()
class MB2_API UMyBTTask_FindRandomLocationCPP : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

private:
	// Runs when it gets hit with a pin in the BT
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Search")
	float SearchRadius = 1000.0f;
};
