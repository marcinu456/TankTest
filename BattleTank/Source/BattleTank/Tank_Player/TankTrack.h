// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and apply forces to tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
private:
    UTankTrack();
    virtual void BeginPlay() override;

    void ApplySidewaysForce();

    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

public:
    //Set a throttle between -1 and +1
    UFUNCTION(BlueprintCallable, Category = Input)
        void SetThrottle(float Throttle);
    
    void DriveTrack();

    float CurrentThrottle = 0;

    //Max force per tracks in Newtons
    UPROPERTY(EditDefaultsOnly, Category = Setup)
        float TrackMaxDrivingForce = 400000;// Assume 40 tonne tank, and 1g acceleration
};
