// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
    virtual void BeginPlay() override;
    UFUNCTION(BlueprintCallable, Category = Setup)
        ATank* GetControlledTank() const;

public:
    virtual void Tick(float DeltaTime) override;


    void AimTowardsCrosshair();//Start the tank moving the barrel so that a shot would hit where the crosshair intersect the world
    bool GetSightRayHitLocation(FVector& OutHitLocation) const;//returna an OUT parameter, true if hit landscape 
    bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation ) const;
    bool GetLookDirection(FVector2D ScreenLocation,FVector& LookDirection) const;
    UPROPERTY(EditAnywhere)
        float CrosshairXLocation = 0.5;
    UPROPERTY(EditAnywhere)
        float CrosshairYLocation = 0.3333;
    UPROPERTY(EditAnywhere)
        float LineTraceRange = 1000000;

};
