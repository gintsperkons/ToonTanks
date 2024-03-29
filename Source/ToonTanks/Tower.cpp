// Fill out your copyright notice in the Description page of Project Settings.

#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (InFireRange())
        RotateTurretBarrel(Tank->GetActorLocation());
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
    if (!InFireRange())
        return;

    Fire();
}

bool ATower::InFireRange()
{
    if (!Tank && FVector::Dist(GetActorLocation(), Tank->GetActorLocation()) > FireRange)
        return false;
    return true;
}
