// Fill out your copyright notice in the Description page of Project Settings.


#include "MGCharacter.h"


// Sets default values
AMGCharacter::AMGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

void AMGCharacter::Pure_MoveCharacter(const FVector2D Axis)
{
	// Update the member axis
	pMoveAxis = Axis;

	// Move character based on Y axis
	AddMovementInput(GetControlRotation().Vector(), Axis.Y);

	// Move character based on X axis
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::Y), Axis.X);
}

void AMGCharacter::Pure_RotateController(const FVector2D Axis)
{
	// Rotate the controller Yaw based on X axis
	AddControllerYawInput(Axis.X);

	// Rotate the controller Pitch based on Y axis
	AddControllerPitchInput(-Axis.Y);
}

