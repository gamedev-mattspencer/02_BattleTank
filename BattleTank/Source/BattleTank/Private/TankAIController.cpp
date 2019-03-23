// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "BattleTank/Public/TankAimingComponent.h"
#include "BattleTank/Public/Tank.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	AimingComponent = FindComponentByClass<UTankAimingComponent>();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!ensure(PlayerTank)) { return; }

	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check acceptance radius is cm
		AimingComponent->AimAt(PlayerTank->GetActorLocation(), LaunchSpeed);
		AimingComponent->Fire();
	}

}