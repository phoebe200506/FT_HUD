// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CannonGame.generated.h"

UENUM(BlueprintType)
enum class ShootingState : uint8 {
	Power UMETA(DisplayName = "POWER"),
	Angle UMETA(DisplayName = "ANGLE"),
	Shot UMETA(DisplayName = "SHOT")
};

UCLASS()
class FT_HUD_API ACannonGame : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACannonGame();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// shooting values
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float power = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float angle = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float speed = 10;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ShootingState CurrentState = ShootingState::Power;

};
