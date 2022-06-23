// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionsWidget.h"

#include "MyGameInstance.h"
#include "MyPlayerController.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/Slider.h"

void UOptionsWidget::InitWidget()
{
	GameInstance = Cast<UMyGameInstance>(GetGameInstance());

	SliderEffects->SetValue(GameInstance->EffectsFloat);
	SliderMusic->SetValue(GameInstance->MusicFloat);
	ProgressBarEffects->SetPercent(SliderEffects->Value);
	ProgressBarMusic->SetPercent(SliderMusic->Value);

	InitButtons();
	
}

void UOptionsWidget::InitButtons()
{
	if(GameInstance)
	{
		bHDRumble = GameInstance->bHDRumble;
		bInverseY = GameInstance->bInverseY;
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
}

void UOptionsWidget::OnHoverButton(UImage* ButtonFrame, UButton* Button, bool bCheck)
{
	ButtonFrame->SetColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f)); // black

	UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
	ButtonImage->SetVisibility(ESlateVisibility::Visible);
}

void UOptionsWidget::OnHoverBack(UImage* ButtonBgn)
{
	ButtonBgn->SetColorAndOpacity(FLinearColor(0.8f, 0.8f, 0.8f)); // tinted
}

void UOptionsWidget::OnUnhoverBack(UImage* ButtonBgn)
{
	ButtonBgn->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f)); // normal
}

void UOptionsWidget::ClickedBack()
{
	Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController())->ChangeUIState(UI_Pause);
}

void UOptionsWidget::OnUnhoverButton(UImage* ButtonFrame, UButton* Button, bool bCheck)
{
	ButtonFrame->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f)); // normal

	if(!bCheck)
	{
		UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UOptionsWidget::HDRumbleClicked(UButton* Button)
{
	if(bHDRumble)
	{
		bHDRumble = false;
		UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		bHDRumble = true;
		UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Visible);
	}

	if(GameInstance)
	{
		GameInstance->bHDRumble = bHDRumble;
	}
}

void UOptionsWidget::InverseYClicked(UButton* Button)
{
	if(bInverseY)
	{
		bInverseY = false;
		UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		bInverseY = true;
		UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Visible);
	}

	if(GameInstance)
	{
		GameInstance->bInverseY = bInverseY;
	}
}

void UOptionsWidget::SliderChange(UProgressBar* ProgressBar, float SliderValue)
{
	ProgressBar->SetPercent(SliderValue);
}

void UOptionsWidget::SliderSave()
{
	if(GameInstance)
	{
		GameInstance->EffectsFloat = SliderEffects->GetValue();
		GameInstance->MusicFloat = SliderMusic->GetValue();
	}
}
