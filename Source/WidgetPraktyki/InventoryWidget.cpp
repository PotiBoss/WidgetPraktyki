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

void UInventoryWidget::SelectSoul(FSoul Soul)
{
	ImageSoulDescription->SetBrushFromTexture(Soul.Image);
	TextSoulName->SetText(Soul.Name);
	TextSoulDescription->SetText(Soul.Name);

	ImageSoulDescription->SetVisibility(ESlateVisibility::Visible);
	TextSoulName->SetVisibility(ESlateVisibility::Visible);
	TextSoulDescription->SetVisibility(ESlateVisibility::Visible);
}

void UInventoryWidget::SetSoul(uint8 SoulIndex, uint8 RandomNumber)
{
	InventorySoulsButtons[SoulIndex].Image = InventorySoulsSprites[RandomNumber].Image;
	InventorySoulsButtons[SoulIndex].Name = InventorySoulsSprites[RandomNumber].Name;
	InventorySoulsButtons[SoulIndex].Description = InventorySoulsSprites[RandomNumber].Description;

	UImage* Image = Cast<UImage>(InventorySoulsButtons[SoulIndex].Button->GetChildAt(0));
	Image->SetBrushFromTexture(InventorySoulsButtons[SoulIndex].Image);
}

void UInventoryWidget::InitButtons()
{
	InventorySoulsButtons.Init(FSoul(),20);
	
	InventorySoulsButtons[0].Button = ButtonSoul0;
	InventorySoulsButtons[1].Button = ButtonSoul1;
	InventorySoulsButtons[2].Button = ButtonSoul2;
	InventorySoulsButtons[3].Button = ButtonSoul3;
	InventorySoulsButtons[4].Button = ButtonSoul4;
	InventorySoulsButtons[5].Button = ButtonSoul5;
	InventorySoulsButtons[6].Button = ButtonSoul6;
	InventorySoulsButtons[7].Button = ButtonSoul7;
	InventorySoulsButtons[8].Button = ButtonSoul8;
	InventorySoulsButtons[9].Button = ButtonSoul9;
	InventorySoulsButtons[10].Button = ButtonSoul10;
	InventorySoulsButtons[11].Button = ButtonSoul11;
	InventorySoulsButtons[12].Button = ButtonSoul12;
	InventorySoulsButtons[13].Button = ButtonSoul13;
	InventorySoulsButtons[14].Button = ButtonSoul14;
	InventorySoulsButtons[15].Button = ButtonSoul15;
	InventorySoulsButtons[16].Button = ButtonSoul16;
	InventorySoulsButtons[17].Button = ButtonSoul17;
	InventorySoulsButtons[18].Button = ButtonSoul18;
	InventorySoulsButtons[19].Button = ButtonSoul19;
	
	int8 SoulIndex = 0;
	
	for(int i = 0; i < InventorySoulsButtons.Num(); i++)
	{
		int8 RandomSoul = FMath::RandRange(0,InventorySoulsSprites.Num() - 1);
		SetSoul(SoulIndex, RandomSoul);
		SoulIndex++;
	}
}
