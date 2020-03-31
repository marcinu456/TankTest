// Copyright Cookie Core

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
public:
	virtual float TakeDamage(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator,
		AActor* DamageCauser
	)override;
	// Sets default values for this pawn's properties

	//Return Current Healt between 0-1
	UFUNCTION(BlueprintPure, Category = Health)
		float GetHealthPercent() const;

private:
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = Health)
		int32 CurrentHealth = StartingHealth;

};
