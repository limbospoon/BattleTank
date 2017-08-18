// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Speed)
{
	auto Name = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttling: %f"), *Name, Speed);
	auto ForceApplied = GetForwardVector() * Speed * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
