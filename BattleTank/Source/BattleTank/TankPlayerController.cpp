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
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s : Reporting for duty"), *t->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

	UE_LOG(LogTemp, Warning, TEXT("Ticking"));
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
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& v) const
{
	//Get crosshair location
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	FVector2D CrosshairLocation = FVector2D(ViewportSizeX * CrosshairLocationX, ViewportSizeY * CrosshairLocationY);

	//translate crosshair location from screenspace to worldspace
	//shoot linetrace from crosshair to world
	//check if hit anything
	//if hit something set hitlocation as that
	//else do nothing
	
	return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

