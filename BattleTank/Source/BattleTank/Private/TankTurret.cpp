// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Turn(float RelativeSpeed)
{
	auto TurnChange = RelativeSpeed * MaxTurnDegrees * GetWorld()->DeltaTimeSeconds;
	auto NewTurn = RelativeRotation.Yaw + TurnChange;

	SetRelativeRotation(FRotator(0, NewTurn, 0));
}