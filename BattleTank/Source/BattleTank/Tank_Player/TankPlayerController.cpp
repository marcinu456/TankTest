// Copyright Cookie Core


#include "TankPlayerController.h"
#include "Tank.h"
#include "TankAimingComponent.h"
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
	auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimingComponent)) {
		FoundAimingComponent(AimingComponent);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player controller can't find aiming component at Begin play"));
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

//void ATankPlayerController::FoundAimingComponent(UTankAimingComponent* AimCompRef)
//{
//}

void ATankPlayerController::AimTowardsCrosshair()
{

	if (!ensure(GetControlledTank())) {
		return;
	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {//has "side effect" is going to linetrace
		GetControlledTank()->AimAt(HitLocation);
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
		//Line trace along that LookDirection and see what we hit(up to max range)
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possesing: %s"), (*LookDirection.ToString()));
	}

	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection* LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult,StartLocation,EndLocation,ECollisionChannel::ECC_Visibility)) {
		HitLocation = HitResult.Location;
		return true;
	}
	else {
		HitLocation = FVector(0);
		return false;//Line trace didn't succesed
	}
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{	
	//"De-Project" the screen position of the crosshair to a world direction
	FVector CameraWorldLocation; //To be discared
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}
