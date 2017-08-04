// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto t = GetControlledPawn();
	auto pt = GetPlayerTank();

	if (!t)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not poscessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is ready"), *t->GetName());
	}
	
	if (!pt)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cant find player"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found: %s"), *pt->GetName());
	}
}

ATank* ATankAIController::GetControlledPawn() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
