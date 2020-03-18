// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
<<<<<<< HEAD
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0;
}

void UTankTrack::ApplySidewaysForce()
=======
	UE_LOG(LogTemp, Warning, TEXT("hit"));
}


void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
>>>>>>> master
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//Work-out the required acceleration this frame to correct
<<<<<<< HEAD
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
=======
>>>>>>> master
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	//calculate and apply sideways (F=ma)
	auto TankRoot = Cast<UMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; //2 Tracks
	TankRoot->AddForce(CorrectionForce);
}

<<<<<<< HEAD
=======


>>>>>>> master
void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT(" %s Throttle %f"), *Name, Throttle);

	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
