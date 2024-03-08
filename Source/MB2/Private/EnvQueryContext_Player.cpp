// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvQueryContext_Player.h"

#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"

void UEnvQueryContext_Player::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	Super::ProvideContext(QueryInstance, ContextData);

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if(!PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController NULL"));
		return;
	}

	APawn* PlayerPawn = PlayerController->GetPawn();
	UEnvQueryItemType_Actor::SetContextHelper(ContextData, PlayerPawn);
}
