// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	
	float AcceptanceRadius = 3000.f; //assuming cm right now

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 15000;

	UTankAimingComponent* AimingComponent = nullptr;
	
};
