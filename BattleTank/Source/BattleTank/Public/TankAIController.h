// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
		float AccceptanceRadius = 3000;
		
public:
	ATank * GetControlledTank() const;

	void BeginPlay() override;

	ATank* GetPlayerTank() const;

	void Tick(float DeltaTime) override;

};
