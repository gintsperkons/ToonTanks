// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	void RotateTurretBarrel(FVector LookAtTarget);
	void Fire();
    
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Components", meta=(AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Components|Meshes", meta=(AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Components|Meshes", meta=(AllowPrivateAccess = "true"))
	class UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Components", meta=(AllowPrivateAccess = "true"))
	class USceneComponent* ProjectileSpawnPoint;

	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "TestCat", meta=(AllowPrivateAccess = "true"))
	int32 BulletSpeed = 69;

	UPROPERTY(EditDefaultsOnly,Category = "Shoot", meta=(AllowPrivateAccess = "true"))
	TSubclassOf<class AProjectile> ProjectileClass;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
