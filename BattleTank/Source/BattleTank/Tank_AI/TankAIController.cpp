// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/Engine.h"
#include "Tank_Player/Tank.h"

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

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank) {
		MoveToActor(PlayerTank, AcceptanceRadius);
		//Aim towards to player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//ControlledTank->Fire();
	}
}




