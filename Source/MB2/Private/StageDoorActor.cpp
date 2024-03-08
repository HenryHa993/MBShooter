// Fill out your copyright notice in the Description page of Project Settings.


#include "StageDoorActor.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AStageDoorActor::AStageDoorActor() : StageNumber(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AStageDoorActor::PlayerFocusDoor()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if(!PlayerController)
	{
		UE_LOG(LogTemp,Warning,TEXT("PlayerController NULL"));
		return;
	}

	FVector PlayerLocation = PlayerController->GetPawn()->GetActorLocation();

	FRotator ControllerRotation = PlayerController->GetControlRotation();
	FRotator TargetControllerRotation = UKismetMathLibrary::FindLookAtRotation(PlayerLocation, GetActorLocation());

	float OriginalPitch = ControllerRotation.Pitch;
	float OriginalRoll = ControllerRotation.Roll;

	FQuat CurrentQuat = FQuat(ControllerRotation);
	FQuat TargetQuat = FQuat(TargetControllerRotation);

	FQuat InterpQuat = FQuat::Slerp(CurrentQuat, TargetQuat, GetWorld()->GetDeltaSeconds() * 3.0f);

	FRotator InterpRotation = FRotator(InterpQuat);

	InterpRotation.Pitch = OriginalPitch;
	InterpRotation.Roll = OriginalRoll;

	PlayerController->SetControlRotation(InterpRotation);

}

// Called when the game starts or when spawned
void AStageDoorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStageDoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

