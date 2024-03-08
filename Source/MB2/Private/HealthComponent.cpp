// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	DefaultHealth = 100;
	CurrentHealth = DefaultHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// Get owner and bind the damage function to the delegate
	AActor* OwnerActor = GetOwner();

	if(!OwnerActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("UHealthComponent: OwnerActor NULL"));
		return;
	}

	OwnerActor->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnTakeAnyDamage);

}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UHealthComponent::GetHealth()
{
	return CurrentHealth;
}

void UHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0 || CurrentHealth <= 0)
		return;

	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0, DefaultHealth);
	//UE_LOG(LogTemp,Warning,TEXT("%f"), CurrentHealth)

	if (CurrentHealth <= 0)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Is this running?? 1"))
		OnDeathDelegate.Broadcast();
	}

}

