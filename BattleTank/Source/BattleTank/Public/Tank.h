// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankMovementComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:

	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

public:	

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

private:
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 100000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTime = 5;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint; 

	UTankBarrel* Barrel = nullptr; //Local barrel reference

	double LastFireTime = 0;

};
