// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank/Public/Tank.h"
#include "BattleTank/Public/TankBarrel.h"
#include "BattleTank/Public/TankTurret.h"
#include "BattleTank/Public/Projectile.h"
#include "BattleTank/Public/TankMovementComponent.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
	if (Barrel && bIsReloaded) 
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			TankAimingComponent->Barrel->GetSocketLocation(FName("Projectile")),
			TankAimingComponent->Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
