// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto t = GetPawn();
	auto pt = GetPlayerTank();

	if (!t)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not poscessing a tank"));
	}
	
	if (!pt)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cant find player"));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!GetPlayerTank())
	{
		return;
	}

	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
