// Fill out yo// Copyright Cookie Core

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
		void Fire();
protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	

	//TODO remove once firing is move to aimingcomponent
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 80000; //TODO find Sensible default

	UPROPERTY(EditAnywhere, Category = Firing)
		float ReloadTimePerSecond = 3;

	UPROPERTY(EditAnywhere, Category = SetUp)
		UClass* ProjectileBlueprint;


	double LastFireTime = 0;

	//local barrel reference for spawnig projectile
	UTankBarrel* Barrel = nullptr; //TODO remove
};
