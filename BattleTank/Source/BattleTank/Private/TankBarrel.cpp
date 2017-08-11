// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float RotateSpeed)
{
	RotateSpeed = FMath::Clamp<float>(RotateSpeed, -1, 1);
	auto ElevationChange = RotateSpeed * MaxRotationSpeed * GetWorld()->DeltaTimeSeconds;
	auto RawElevation = FMath::Clamp<float>(RelativeRotation.Pitch + ElevationChange, MinElevation, MaxElevation);
	
	SetRelativeRotation(FRotator(RawElevation,0,0));
}