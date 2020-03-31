// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank_Player/TankAimingComponent.h"
#include "Tank_Player/Tank.h"
#include "Engine/Engine.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//auto PlayerTank = GetPlayerTank();
	//if (!PlayerTank) {
	//	UE_LOG(LogTemp, Warning, TEXT("TankAIController can't find player tank"));
	//	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("TankAIController can't find player tank "));
	//}
	//else {
	//	UE_LOG(LogTemp, Warning, TEXT("TankAIController found: %s"), *(PlayerTank->GetName()));
	//	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("TankAIController found playertank "));
	//}

}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm
	//Aim towards to player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked) {
		AimingComponent->Fire();
	}
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn) {
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
	}
}

void ATankAIController::OnPossedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Work"))
}




