// Fill out your copyright notice in the Description page of Project Settings.


#include "Slayer/Slayer.h"

#include <Camera/CameraComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include <Components/InputComponent.h>
#include <Kismet/KismetMathLibrary.h>

// Sets default values
ASlayer::ASlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(FName("CameraComponent"));
	CameraComponent->SetupAttachment(GetRootComponent());

	Arms = CreateDefaultSubobject<USkeletalMeshComponent>(FName("Arms"));
	Arms->SetupAttachment(CameraComponent);
}

// Called when the game starts or when spawned
void ASlayer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASlayer::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ASlayer::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ASlayer::MoveRight);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ASlayer::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(FName("Roll"), this, &ASlayer::AddControllerYawInput);
}

void ASlayer::MoveForward(const float Value)
{
	const FRotator CR {0.0f, GetControlRotation().Yaw, 0.0f};
	const FVector Fwr = UKismetMathLibrary::GetForwardVector(CR);
	AddMovementInput(Fwr, Value);
}

void ASlayer::MoveRight(const float Value)
{
	const FRotator CR {0.0f, GetControlRotation().Yaw, 0.0f};
	const FVector Rwd = UKismetMathLibrary::GetRightVector(CR);
	AddMovementInput(Rwd, Value);
}