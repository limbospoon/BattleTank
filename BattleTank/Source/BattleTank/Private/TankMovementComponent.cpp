// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* RightTrack, UTankTrack* LeftTrack)
{
	if (!RightTrack || !LeftTrack)
	{
		return;
	}

	TrackRight = RightTrack;
	TrackLeft = LeftTrack;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto AIMoveVelocity = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(AIMoveVelocity);

	auto RotationVector = FVector::CrossProduct(TankForward, AIForwardIntention);
	IntendTurnRight(RotationVector.Z);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	TrackRight->SetThrottle(Throw);
	TrackLeft->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	TrackRight->SetThrottle(-Throw);
	TrackLeft->SetThrottle(Throw);
}