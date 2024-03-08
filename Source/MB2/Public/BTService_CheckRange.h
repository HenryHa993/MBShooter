// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_CheckRange.generated.h"

/**
 *Given a vector blackboard key and range, output a boolean to given blackboard to determine if it is within range
 **/
UCLASS()
class MB2_API UBTService_CheckRange : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_CheckRange();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, DisplayName = "Input Vector Key", Category = "Blackboard")
		FBlackboardKeySelector InputVectorKey;


	UPROPERTY(EditAnywhere, DisplayName="Output Boolean Key", Category = "Blackboard")
		FBlackboardKeySelector OutputBoolKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		float Range = 1000.0f;
};
