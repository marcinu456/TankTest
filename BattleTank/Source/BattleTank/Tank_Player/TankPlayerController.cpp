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


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController ticking"));
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("TankPlayerController ticking "));
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{

	if (!GetControlledTank()) {
		return;
	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {//has "side effect" is going to linetrace
		//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possesing: %s"), (*HitLocation.ToString()));
	}
}

//Get world location of linetrace trought crosshair, true if hit landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find the crosshair position in pixel coordinates
	int32 VieportSizeX, VieportSizeY;
	GetViewportSize(VieportSizeX, VieportSizeY);
	auto ScreenLocation = FVector2D(VieportSizeX* CrosshairXLocation, VieportSizeY* CrosshairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possesing: %s"), (*LookDirection.ToString()));
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{	
	//"De-Project" the screen position of the crosshair to a world direction
	FVector CameraWorldLocation; //To be discared
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}
