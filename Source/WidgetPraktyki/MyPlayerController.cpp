// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

#include "Blueprint/UserWidget.h"

AMyPlayerController::AMyPlayerController()
{
	UIStateEnum = UI_InGame;
	
}

void AMyPlayerController::BeginPlay()
{
	UpdateUI();
}

void AMyPlayerController::UpdateUI()
{
	if(CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromParent();
	}

	switch(UIStateEnum)
	{
	case UI_InGame:
		ApplyUIChange(GameHUDClass);
		break;
	case UI_Pause:
		ApplyUIChange(PauseClass);
		break;
	case UI_Inventory:
		ApplyUIChange(InventoryClass);
		break;
	default:
		ApplyUIChange(GameHUDClass);
		break;
	}
}

uint8 AMyPlayerController::GetUIState()
{
	return UIStateEnum;
}

void AMyPlayerController::ChangeUIState(TEnumAsByte<EUIState> EnumUIState)
{
	UIStateEnum = EnumUIState;
	UpdateUI();
}

void AMyPlayerController::ApplyUIChange(TSubclassOf<UUserWidget> Widget)
{
	if(Widget != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), Widget);

		if(CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}