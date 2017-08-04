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

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

