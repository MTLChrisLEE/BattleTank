// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"




void UTankBarrel::Elevate(float DegreesPerSecond) {

	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate() Called %f"), Time)

	return;
}