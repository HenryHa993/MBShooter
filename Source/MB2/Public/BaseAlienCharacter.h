// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "HealthComponent.h"
#include "GameFramework/Character.h"
#include "BaseAlienCharacter.generated.h"

UCLASS()
class MB2_API ABaseAlienCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseAlienCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	UHealthComponent* HealthComponent;

	UFUNCTION(BlueprintCallable)
		void Death();

	UPROPERTY(BlueprintReadWrite, Category = "Health")
		bool IsDead = false;

	UPROPERTY(VisibleAnywhere, Category = "Health")
		bool IsHitThisFrame;

	UPROPERTY(EditAnywhere, Category = "Stage")
		int Stage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void OnTakeAnyDamageFunc(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

};
