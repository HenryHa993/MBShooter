// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MB2GameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameStageChangedSignature, int, NewStage);

/**
 * 
 */
UCLASS()
class MB2_API AMB2GameState : public AGameStateBase
{
	GENERATED_BODY()

protected:
	AMB2GameState();

	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	int GetGameStage();

	UFUNCTION(BlueprintCallable)
	void SetGameStage(int NewStage);

	UFUNCTION(BlueprintCallable)
	void IncrementGameStage();

	UFUNCTION()
	void CheckStageComplete();

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FOnGameStageChangedSignature OnGameStageChangedDelegate;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
		TSubclassOf<UUserWidget> GameStartWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
		TSubclassOf<UUserWidget> GameEndWidget;

	UPROPERTY(EditAnywhere, Category = Stage)
		float StageChangeDuration = 5.0f;

private:
	UPROPERTY(EditAnywhere, Category = Stage)
	int GameStage = 0;
	FTimerHandle StageTimerManager;

};
