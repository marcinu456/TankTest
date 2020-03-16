// Copyright Cookie Core

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"


// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Donkey: C++ Construct:"),*TankName);
}


void ATank::BeginPlay()
{
	Super::BeginPlay();
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Donkey: C++ BeginPlay:"), *TankName);
	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}


void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	//	UE_LOG(LogTemp, Warning, TEXT(" Fire"));

	if (!ensure(Barrel)) { return; }

	bool isReload = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimePerSecond;

	if (isReload) { 
		//Spawn projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}