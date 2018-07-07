// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UENUM()
enum class EFiringState :uint8 {
	Reloading,
	Aiming,
	Ready
};


class UTankBarrel; //Forward Declaration
class UTankTurret;
class AProjectile;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
		EFiringState FiringState = EFiringState::Ready;


private:	
	
	void MoveBarrelTowards(FVector AimDirection);
		
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
		
	UPROPERTY(EditAnywhere, Category = "Firing")
		float LaunchSpeed = 4000.F;


	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;


};
