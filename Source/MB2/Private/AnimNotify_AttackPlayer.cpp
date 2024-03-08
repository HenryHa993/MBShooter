// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_AttackPlayer.h"

#include "AlienAIController.h"
#include "Kismet/GameplayStatics.h"
#include "MB2/MB2Character.h"

void UAnimNotify_AttackPlayer::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (!(MeshComp))
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController or MeshComponent NULL"));
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	AMB2Character* PlayerCharacter = Cast<AMB2Character>(PlayerController->GetPawn());

	AActor* AIActor = MeshComp->GetOwner();

	FVector AILocation = AIActor->GetActorLocation();
	FVector PlayerLocation = PlayerCharacter->GetActorLocation();

	float Distance = FVector::Distance(AILocation, PlayerLocation);

	if(Distance <= AttackRange)
	{
		UGameplayStatics::ApplyDamage(PlayerCharacter, Damage, PlayerController, AIActor, DamageType);
		UE_LOG(LogTemp, Warning, TEXT("Hit, Health: %f"), PlayerCharacter->HealthComponent->GetHealth());
	}
}
