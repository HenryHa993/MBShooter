// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AlienAIController.generated.h"

/**
 * 
 */
UCLASS()
class MB2_API AAlienAIController : public AAIController
{
	GENERATED_BODY()
public:
	AAlienAIController();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
		UBehaviorTree* BehaviourTree;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
		UBehaviorTreeComponent* BehaviourTreeComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
		UBlackboardComponent* BlackboardComponent;

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

	void RunBT();

	UFUNCTION()
	void AwakeAlien(int NewStage);
};
