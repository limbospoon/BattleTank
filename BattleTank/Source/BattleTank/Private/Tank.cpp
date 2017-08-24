// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("TANKY: Constructed"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TANKY: Begin play"));
}

void ATank::AimAt(FVector Target)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(Target, LaunchSpeed);
}

void ATank::Fire()
{
	if (!TankAimingComponent) { return; }

	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	FVector  MuzzleLocation = TankAimingComponent->Barrel->GetSocketLocation(FName("Muzzle"));
	FRotator MuzzleRotation = TankAimingComponent->Barrel->GetSocketRotation(FName("Muzzle"));

	if (TankAimingComponent->Barrel && bIsReloaded)
	{
		auto _Projectile = GetWorld()->SpawnActor<AProjectile>(Projectile, MuzzleLocation, MuzzleRotation);
		_Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}