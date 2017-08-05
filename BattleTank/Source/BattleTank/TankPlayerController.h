// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	ATank* GetControlledTank() const;
	
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& v) const;

private:

	UPROPERTY(EditAnywhere)
	float CrosshairLocationX = 0.5f;
	
	UPROPERTY(EditAnywhere)
	float CrosshairLocationY = 0.333f;
};
