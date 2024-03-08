// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_UpdateIsSeen.h"

#include "AIController.h"
#include "BaseAlienCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Camera/CameraComponent.h"
#include "MB2/MB2Character.h"

void UBTService_UpdateIsSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	//AMB2Character* PlayerCharacter = Cast<AMB2Character>(PlayerController->GetPawn());
	//UCameraComponent* PlayerCamera = PlayerCharacter->GetFirstPersonCameraComponent();

	FVector CameraLocation;
	FRotator CameraRotation;

	PlayerController->GetPlayerViewPoint(CameraLocation, CameraRotation);

	FVector TraceEndPoint = CameraLocation + (CameraRotation.Vector() * 3000.0f);

	FHitResult HitResult;

	if(GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, TraceEndPoint, ECC_Visibility))
	{
		AActor* HitActor = HitResult.GetActor();
		AAIController* AIController = OwnerComp.GetAIOwner();
		//FString Msg = HitActor->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);

		bool IsSeen = HitActor->IsA(ABaseAlienCharacter::StaticClass());
		AIController->GetBlackboardComponent()->SetValueAsBool(OuputBoolKey.SelectedKeyName, IsSeen);

		//if(!HitActor->IsA(ABaseAlienCharacter::StaticClass()))
		//{
		//	//UE_LOG(LogTemp, Warning, TEXT("No hit alien"));
		//	//DrawDebugLine(GetWorld(), CameraLocation, HitResult.ImpactPoint, FColor::Red, false, 2.0f);
		//	AIController->GetBlackboardComponent()->SetValueAsBool(OuputBoolKey.SelectedKeyName, IsSeen);
		//}
		//UE_LOG(LogTemp, Warning, TEXT("Alien"));
		//DrawDebugLine(GetWorld(), CameraLocation, TraceEndPoint, FColor::Green, false, 2.0f);

	}
}
