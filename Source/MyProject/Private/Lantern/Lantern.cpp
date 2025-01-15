// Fill out your copyright notice in the Description page of Project Settings.


#include "Lantern/Lantern.h"

// Sets default values
ALantern::ALantern()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALantern::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALantern::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto Cr = GetActorRotation();
	Cr.Yaw += 45.0f * DeltaTime;
	SetActorRotation(Cr);
}

