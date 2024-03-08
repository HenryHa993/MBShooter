// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAlienCharacter.h"
#include "AlienAIController.h"
#include "MB2GameState.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABaseAlienCharacter::ABaseAlienCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	HealthComponent->OnDeathDelegate.AddDynamic(this, &ABaseAlienCharacter::Death);

	OnTakeAnyDamage.AddDynamic(this, &ABaseAlienCharacter::OnTakeAnyDamageFunc);

}


void ABaseAlienCharacter::Death()
{
	//UE_LOG(LogTemp,Warning,TEXT("Is this running?? 2"))
	IsDead = true;

	// Remove collisions with capsule component
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Turn off behaviour tree
	AAlienAIController* AIController = Cast<AAlienAIController>(GetController());
	if(AIController)
	{
		AIController->BehaviourTreeComponent->StopLogic("DEAD");
	}

	// Inform gamestate
	AMB2GameState* GameState = GetWorld()->GetGameState<AMB2GameState>();
	GameState->CheckStageComplete();
}

// Called when the game starts or when spawned
void ABaseAlienCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseAlienCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseAlienCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseAlienCharacter::OnTakeAnyDamageFunc(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Is this running?? 2"))
	IsHitThisFrame = true;
}

