// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = SetUp)
		void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = SetUp)
		void SetTurretReference(UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable)
		void Fire();
protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 80000; //TODO find Sensible default

	UPROPERTY(EditAnywhere, Category = Firing)
		float ReloadTimePerSecond = 3;

	UPROPERTY(EditAnywhere, Category = SetUp)
		UClass* ProjectileBlueprint;


	double LastFireTime = 0;

	//local barrel reference for spawnig projectile
	UTankBarrel* Barrel = nullptr;
};
