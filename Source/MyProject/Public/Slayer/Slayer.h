// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Slayer.generated.h"

UCLASS()
class MYPROJECT_API ASlayer : public ACharacter
{
	GENERATED_BODY()

	void MoveForward(float Value);
	void MoveRight(float Value);

public:
	// Sets default values for this character's properties
	ASlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = Components)
	class UCameraComponent* CameraComponent = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Components)
	class USkeletalMeshComponent* Arms = nullptr;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
