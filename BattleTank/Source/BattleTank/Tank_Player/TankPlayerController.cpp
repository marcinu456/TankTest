// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Engine/Engine.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if(!ControlledTank){
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController not possesing a tank"));
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("TankPlayerController not possesing a tank "));
	}
	else{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possesing: %s"), *(ControlledTank->GetName()));
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("TankPlayerController possesing a tank "));
	}

}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}