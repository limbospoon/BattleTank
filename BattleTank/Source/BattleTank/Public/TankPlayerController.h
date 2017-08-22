// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be last include

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLoc, FVector& LookDirection) const;
	bool GetHitLocationVector(FVector LookDirection, FVector& HitLocation) const;

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

private:

	UPROPERTY(EditAnywhere)
	float CrosshairLocationX = 0.5f;
	
	UPROPERTY(EditAnywhere)
	float CrosshairLocationY = 0.333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;
};
