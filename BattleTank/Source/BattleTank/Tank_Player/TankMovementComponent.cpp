// Copyright Cookie Core

#include"TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//auto TankName = GetOwner()->GetName();
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardDirection = MoveVelocity.GetSafeNormal();// .ToString();
	
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardDirection);
	IntendMoveForward(ForwardThrow);
	//UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *TankName, *AIForwardDirection);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardDirection).Z;
	IntendTurnRight(RightThrow);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT(" Indend move throw: %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}
void UTankMovementComponent::IntendTurnRight(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT(" Indend move right throw: %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}


