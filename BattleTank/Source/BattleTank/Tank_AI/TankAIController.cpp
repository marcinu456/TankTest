// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/Engine.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController can't find player tank"));
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("TankAIController can't find player tank "));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController found: %s"), *(PlayerTank->GetName()));
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("TankAIController found playertank "));
	}

}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {
		return nullptr;
	}
	else {
		return Cast<ATank>(PlayerPawn);
	}
}
