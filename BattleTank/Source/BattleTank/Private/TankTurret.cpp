// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::YawTurret(float RotationSpeed)
{
	RotationSpeed = FMath::Clamp<float>(RotationSpeed, -1, 1);
	auto YawChange = RotationSpeed * MaxRotationSpeed * GetWorld()->DeltaTimeSeconds;
	auto RawYaw = RelativeRotation.Yaw + YawChange;

	SetRelativeRotation(FRotator(0, RawYaw, 0));
}

