// Fill out your copyright notice in the Description page of Project Settings.


#include "MB2GameState.h"

#include "BaseAlienCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

AMB2GameState::AMB2GameState() : GameStage(0)
{
}

void AMB2GameState::BeginPlay()
{
	Super::BeginPlay();

	// Set up the game start widget
	if(!GameStartWidget)
	{
		return;
	}

	if(UUserWidget* GameStartScreen = CreateWidget(GetWorld(), GameStartWidget))
	{
		GameStartScreen->AddToViewport();
	}
}

int AMB2GameState::GetGameStage()
{
	return GameStage;
}

void AMB2GameState::SetGameStage(int NewStage)
{
	GameStage = NewStage;
}

void AMB2GameState::IncrementGameStage()
{
	GameStage++;
	OnGameStageChangedDelegate.Broadcast(GameStage);

	// Check if game won
	if(GameStage >= 4)
	{
		if (!GameEndWidget)
		{
			return;
		}

		if(UUserWidget* GameEndScreen = CreateWidget(GetWorld(), GameEndWidget))
		{
			GameEndScreen->AddToViewport();
		}
	}
}

void AMB2GameState::CheckStageComplete()
{
	TArray<AActor*> AlienActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseAlienCharacter::StaticClass(), AlienActors);

	// Check if any aliens alive for given stage
	for(AActor* Actor : AlienActors)
	{
		ABaseAlienCharacter* AlienCharacter = Cast<ABaseAlienCharacter>(Actor);

		if((AlienCharacter->Stage == GameStage) && (!AlienCharacter->IsDead))
		{
			return;
		}
	}

	// Otherwise, they are all dead and the next stage should pursue
	GetWorld()->GetTimerManager().SetTimer(
		StageTimerManager,
		this,
		&AMB2GameState::IncrementGameStage,
		StageChangeDuration,
		false);
}
