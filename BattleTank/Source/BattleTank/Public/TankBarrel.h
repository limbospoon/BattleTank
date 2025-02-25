// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void ElevateBarrel(float RotateSpeed);

private:

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxRotationSpeed = 20;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxElevation = 60;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MinElevation = 0;

};
