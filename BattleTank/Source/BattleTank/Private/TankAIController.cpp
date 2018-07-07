// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"


ATank * ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ensure(ControlledTank)) {
		UE_LOG(LogTemp, Error, TEXT("AI NOT POSSESSING A TANK"))
	}

	auto PlayerTank = GetPlayerTank();
	if (!ensure(PlayerTank)) {
		UE_LOG(LogTemp, Error, TEXT("AI CANNOT FIND THE TANK"))
	}
}

ATank * ATankAIController::GetPlayerTank() const
{	
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerPawn)) {
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());


	if (ensure(PlayerTank)) {

		MoveToActor(PlayerTank, 3000);

		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
}
