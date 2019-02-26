// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	auto PlayerControlledTank = GetPlayerTank();

	if (!PlayerControlledTank) 
	{
		UE_LOG(LogTemp, Error, TEXT("There is no player controlled tank."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player Controlled Tank seen by the AI is: %s"), *(PlayerControlledTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
