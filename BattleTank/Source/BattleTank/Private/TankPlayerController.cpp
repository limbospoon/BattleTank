// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto t = GetControlledTank();

	if (!t)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not poscessing a tank"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Get crosshair location
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairLocationX, ViewportSizeY * CrosshairLocationY);
	
	//translate crosshair location from screenspace to worldspace
	FVector LookDir;
	if (GetLookDirection(ScreenLocation, LookDir))
	{
		if (GetHitLocationVector(LookDir, HitLocation))
		{
			return true;
		}

	}
	
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLoc, FVector& LookDirection) const
{
	FVector CameraLocation;
	return DeprojectScreenPositionToWorld(ScreenLoc.X, ScreenLoc.Y, CameraLocation, LookDirection);
}

bool ATankPlayerController::GetHitLocationVector(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(GetControlledTank());

	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility,
		CollisionQueryParams
		))
	{
		HitLocation = HitResult.Location;
		DrawDebugPoint(GetWorld(), HitLocation, 100.0f, FColor::Emerald);
		return true;
	}

	HitLocation = FVector(0);

	return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

