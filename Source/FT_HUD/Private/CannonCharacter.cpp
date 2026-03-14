// Fill out your copyright notice in the Description page of Project Settings.


#include "CannonCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
// Sets default values
ACannonCharacter::ACannonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// create a capsule component and set it as the root component
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(1.f, 1.f);
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-20.f, 0.f, 0.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = false; // we will control the rotation of the camera ourselves
}

// Called when the game starts or when spawned
void ACannonCharacter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Hello from cannon"));
	// do we have a valid hud 
	if (HUDType)
	{
		// create our hud
		HUD = CreateWidget<UUserWidget>(GetWorld(), HUDType);
		// if we successfuly created the widget
		if (HUD)
		{
			HUD->AddToViewport();
		}
	}
}

// Called every frame
void ACannonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACannonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// notice now i use a pointer and update the values in one function
// this is a form of passing by reference, as i know i do this to muliple values
// i also want to avoid copying as that is expensive
void ACannonCharacter::UpdateValue(float* value, float DeltaTime)
{
	// the *value means dereference 
	if (*value < 0 || *value > 90)
	{
		// flip speed from positive to negative
		speed = -speed;
	}
	*value += speed * DeltaTime;
}