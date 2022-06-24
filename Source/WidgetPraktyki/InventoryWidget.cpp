// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

#include "Components/Button.h"
#include "Components/Image.h"


void UInventoryWidget::InitWidget()
{
	InitButtons();
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
