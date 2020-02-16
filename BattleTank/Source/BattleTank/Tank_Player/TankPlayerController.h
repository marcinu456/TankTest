// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
    virtual void BeginPlay() override;
    
public:
    virtual void Tick(float DeltaTime) override;
    ATank* GetControlledTank() const;
    void AimTowardsCrosshair();//Start the tank moving the barrel so that a shot would hit where the crosshair intersect the world
    bool GetSightRayHitLocation(FVector& OutHitLocation) const;//returna an OUT parameter, true if hit landscape 
};
