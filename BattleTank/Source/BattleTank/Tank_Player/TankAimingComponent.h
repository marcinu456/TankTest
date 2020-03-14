// Copyright Cookie Core

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};


//Forward Declaration
class UTankBarrel;
class UTankTurret;

//Hold parameters for barrel's
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = SetUp)
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);


public:	

	
	//TODO add SetTurrentReference

	void AimAt(FVector HitLocation, float LaunchSpeed);
	
	void MoveBarrelTowards(FVector AimDirection);

protected:
	UPROPERTY(BlueprintReadOnly, Category = State)
		EFiringState FiringState = EFiringState::Reloading;


private:
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;
};
