// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector Target, float LaunchSpeed)
{
	if (!Barrel)
	{
		return;
	}

	FVector LaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Muzzle"));
	bool bHaveLaunchVelocity = UGameplayStatics::SuggestProjectileVelocity(
		this,
		LaunchVelocity,
		StartLocation,
		Target,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		);
	if (bHaveLaunchVelocity)
	{
		auto AimDirection = LaunchVelocity.GetSafeNormal();
		AimBarrel(AimDirection);
		AimTurret(AimDirection);
	}
}

void UTankAimingComponent::AimBarrel(FVector RotateTo)
{
	if (!Barrel) { return; }
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = RotateTo.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->ElevateBarrel(DeltaRotator.Pitch);
}

void UTankAimingComponent::AimTurret(FVector RotateTo)
{
	if (!Turret) { return; }
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = RotateTo.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;

	Turret->YawTurret(DeltaRotator.Yaw);
}