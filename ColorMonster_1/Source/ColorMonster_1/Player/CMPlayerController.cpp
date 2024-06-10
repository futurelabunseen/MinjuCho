// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CMPlayerController.h"

#include "EnhancedInputSubsystems.h"

void ACMPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);

		//UE_LOG(LogTemp, Warning, TEXT("CMPlayerController BeginPlay"));
	}
	// 첫 화면은 UI이므로
	SetPlayerInputMode(false);
}

void ACMPlayerController::SetPlayerInputMode(bool bInputMode)
{
	FInputModeDataBase* InputMode = (bInputMode)
	? static_cast<FInputModeDataBase*>(new FInputModeGameOnly())
	: static_cast<FInputModeDataBase*>(new FInputModeUIOnly());

	SetInputMode(*InputMode);
	bShowMouseCursor = !bInputMode;
}
