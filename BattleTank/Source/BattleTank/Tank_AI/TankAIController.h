// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
protected:
    void BeginPlay() override;
public:
    virtual void Tick(float DeltaTime) override;

protected:
    //How close AI tank get to the player
    UPROPERTY(EditDefaultsOnly, Category=Setup)
    float AcceptanceRadius = 8000;
};
