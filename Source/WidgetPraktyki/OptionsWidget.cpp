// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionsWidget.h"

#include "Components/Button.h"
#include "Components/Image.h"

void UOptionsWidget::OnHoverButton(UImage* ButtonFrame, UButton* Button)
{
	ButtonFrame->SetColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f)); // black

	UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
	ButtonImage->SetVisibility(ESlateVisibility::Visible);
}

void UOptionsWidget::OnUnhoverButton(UImage* ButtonFrame, UButton* Button)
{
	ButtonFrame->SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f)); // normal

	if(!bHDRumble)
	{
		UImage* ButtonImage = Cast<UImage>(Button->GetChildAt(0));
		ButtonImage->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UOptionsWidget::HDRumbleClicked()
{
	if(bHDRumble)
	{
		bHDRumble = false;
	}
	else
	{
		bHDRumble = true;
	}
}
