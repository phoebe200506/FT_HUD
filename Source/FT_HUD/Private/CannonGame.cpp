// Fill out your copyright notice in the Description page of Project Settings.


#include "CannonGame.h"

// Sets default values
ACannonGame::ACannonGame()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACannonGame::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACannonGame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	switch (CurrentState)
	{
	case ShootingState::Power:
		// POWER!!!!
		break;
	case ShootingState::Angle:
		// TRIGONOMETRY
		break;
	case ShootingState::Shot:
		// pew pew
		break;
	}

}

