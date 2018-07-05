// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) 
{
	if (!LeftTrackToSet || !RightTrackToSet) {
		return;
	}
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRIght(float Throw)
{
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
}

//Path Finding Logic calls this method
// https://imgur.com/a/B6Siqi1

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankName = GetOwner()->GetName();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal(); 
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();

	IntendMoveForward(FVector::DotProduct(TankForward, AIForwardIntention));
	IntendTurnRIght(FVector::CrossProduct(TankForward, AIForwardIntention).Z);
}
