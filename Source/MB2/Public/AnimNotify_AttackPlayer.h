// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_AttackPlayer.generated.h"

/**
 * 
 */
UCLASS()
class MB2_API UAnimNotify_AttackPlayer : public UAnimNotify
{
	GENERATED_BODY()

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:
	UPROPERTY(EditAnywhere, Category = "Damage")
		float AttackRange;

	UPROPERTY(EditAnywhere, Category = "Damage")
		float Damage = 10;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UDamageType> DamageType;

};
