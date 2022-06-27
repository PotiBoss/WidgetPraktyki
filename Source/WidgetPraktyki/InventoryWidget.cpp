// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

#include "MyPlayerController.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"


void UInventoryWidget::InitWidget()
{
	InitButtons();
	HideSoulInfo();
}

void UInventoryWidget::QuitInventory()
{
	AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());

	PlayerController->ChangeUIState(UI_InGame);
}

void UInventoryWidget::HideSoulInfo()
{
	ImageSoulDescription->SetVisibility(ESlateVisibility::Collapsed);
	ImageUseBgn->SetVisibility(ESlateVisibility::Collapsed);
	ImageUseFrame->SetVisibility(ESlateVisibility::Collapsed);
	ImageUseBgnSolo->SetVisibility(ESlateVisibility::Collapsed);
	ImageUseFrameSolo->SetVisibility(ESlateVisibility::Collapsed);
	ImageDestroyBgn->SetVisibility(ESlateVisibility::Collapsed);
	ImageDestroyFrame->SetVisibility(ESlateVisibility::Collapsed);
	ImageDestroyBgnSolo->SetVisibility(ESlateVisibility::Collapsed);
	ImageDestroyFrameSolo->SetVisibility(ESlateVisibility::Collapsed);

	TextSoulName->SetVisibility(ESlateVisibility::Collapsed);
	TextSoulDescription->SetVisibility(ESlateVisibility::Collapsed);
	TextUse->SetVisibility(ESlateVisibility::Collapsed);
	TextUseSolo->SetVisibility(ESlateVisibility::Collapsed);
	TextDestroy->SetVisibility(ESlateVisibility::Collapsed);
	TextDestroySolo->SetVisibility(ESlateVisibility::Collapsed);
}

void UInventoryWidget::InitButtons()
{
	for(int i = 0; i < 19; i++)
	{
		InventorySoulsButtons.Add(ButtonSoul0);
		InventorySoulsButtons.Add(ButtonSoul1);
		InventorySoulsButtons.Add(ButtonSoul2);
		InventorySoulsButtons.Add(ButtonSoul3);
		InventorySoulsButtons.Add(ButtonSoul4);
		InventorySoulsButtons.Add(ButtonSoul5);
		InventorySoulsButtons.Add(ButtonSoul6);
		InventorySoulsButtons.Add(ButtonSoul7);
		InventorySoulsButtons.Add(ButtonSoul8);
		InventorySoulsButtons.Add(ButtonSoul9);
		InventorySoulsButtons.Add(ButtonSoul10);
		InventorySoulsButtons.Add(ButtonSoul11);
		InventorySoulsButtons.Add(ButtonSoul12);
		InventorySoulsButtons.Add(ButtonSoul13);
		InventorySoulsButtons.Add(ButtonSoul14);
		InventorySoulsButtons.Add(ButtonSoul15);
		InventorySoulsButtons.Add(ButtonSoul16);
		InventorySoulsButtons.Add(ButtonSoul17);
		InventorySoulsButtons.Add(ButtonSoul18);
		InventorySoulsButtons.Add(ButtonSoul19);
	}
	
	for(int i = 0; i < InventorySoulsButtons.Num(); i++)
	{
		for (auto Button : InventorySoulsButtons)
		{
			int8 RandomSoul = FMath::RandRange(0,InventorySoulsSprites.Num() - 1);

			UImage* Image = Cast<UImage>(Button->GetChildAt(0));
			Image->SetBrushFromTexture(InventorySoulsSprites[RandomSoul]);
		}
	}
}
