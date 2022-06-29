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
	case UI_Options:
		ApplyUIChange(OptionsClass);
		break;
	case UI_OptionsExtended:
		ApplyUIChange(OptionsExtendedClass);
		break;
	case UI_ReadMe:
		ApplyUIChange(ReadMeClass);
		break;
	case UI_Credits:
		ApplyUIChange(CreditsClass);
		break;
	default:
		ApplyUIChange(GameHUDClass);
		break;
	}
}

void AMyPlayerController::HideInventory(TEnumAsByte<EUIState> EnumUIState)
{
	UIStateEnum = EnumUIState;

	if(CurrentWidget != nullptr)
	{
		CurrentWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

uint8 AMyPlayerController::GetUIState()
{
	return UIStateEnum;
}

uint8 AMyPlayerController::GetUIStateCheck(TEnumAsByte<EUIState> EnumUIState)
{
	return EnumUIState;
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