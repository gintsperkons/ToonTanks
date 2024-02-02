// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	ProjectileMovmentComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement Component"));
	RootComponent = ProjectileMesh;

	
	ProjectileMovmentComponent->MaxSpeed = 3000.f;
	ProjectileMovmentComponent->InitialSpeed = 3000.f;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	auto MyOwner = GetOwner();
	if (!MyOwner) return;


	if (OtherActor == nullptr || OtherActor == this || OtherActor == MyOwner) return;

	UGameplayStatics::ApplyDamage(OtherActor,
								  Damage,
								  MyOwner->GetInstigatorController(),
								  this,
								  UDamageType::StaticClass());
	Destroy();
}

