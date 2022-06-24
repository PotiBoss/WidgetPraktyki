// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionsWidgetExtended.h"

#include "MyGameInstance.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/Slider.h"


void UOptionsWidgetExtended::InitWidgetExtended()
{
	GameInstance = Cast<UMyGameInstance>(GetGameInstance());

	SliderEffects->SetValue(GameInstance->EffectsFloat);
	SliderMusic->SetValue(GameInstance->MusicFloat);
	ProgressBarEffects->SetPercent(SliderEffects->Value);
	ProgressBarMusic->SetPercent(SliderMusic->Value);

	InitButtonsExtended();
}

void UOptionsWidgetExtended::InitButtonsExtended()
{
	if(GameInstance)
	{
		bHDRumble = GameInstance->bHDRumble;
		bInverseY = GameInstance->bInverseY;
		bStrongVibrations = GameInstance->bHDRumbleStrong;
		bStrongerVibrations = GameInstance->bHDRumbleStronger;
	}

	if(bHDRumble)
	{
		UImage* ButtonImage = Cast<UImage>(ButtonHDRumble->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		UImage* ButtonImage = Cast<UImage>(ButtonHDRumble->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Collapsed);
	}

	if(bInverseY)
	{
		UImage* ButtonImage = Cast<UImage>(ButtonInverseY->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		UImage* ButtonImage = Cast<UImage>(ButtonInverseY->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Collapsed);
	}

	if(bStrongVibrations)
	{
		UImage* ButtonImage = Cast<UImage>(ButtonStrongVibrations->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		UImage* ButtonImage = Cast<UImage>(ButtonStrongVibrations->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Collapsed);
	}

	if(bStrongerVibrations)
	{
		UImage* ButtonImage = Cast<UImage>(ButtonStrongerVibrations->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		UImage* ButtonImage = Cast<UImage>(ButtonStrongerVibrations->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UOptionsWidgetExtended::StrongVibrationsClicked(UButton* Button)
{
	if(bStrongVibrations)
	{
		bStrongVibrations = false;
		UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		bStrongVibrations = true;
		UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Visible);
	}
	
	if(GameInstance)
	{
		GameInstance->bHDRumbleStrong = bStrongVibrations;
	}
}

void UOptionsWidgetExtended::StrongerVibrationsClicked(UButton* Button)
{
	if(bStrongerVibrations)
	{
		bStrongerVibrations = false;
		UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		bStrongerVibrations = true;
		UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Visible);
	}
	
	if(GameInstance)
	{
		GameInstance->bHDRumbleStronger = bStrongerVibrations;
	}
}
