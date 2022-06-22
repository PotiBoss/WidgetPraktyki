// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameWidget.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"


void UInGameWidget::MonsterKilled(uint8 MonsterIndex)
{
	switch(MonsterIndex)
	{
	case 0:
		MonsterImageLeft->SetVisibility(ESlateVisibility::Collapsed);
		TimerDelegate.BindUFunction(this, "SpawnNewMonsterBP", MonsterIndex);
		GetWorld()->GetTimerManager().SetTimer(TimerHandleLeft, TimerDelegate, RespawnTime, false);
		break;
	case 1:
		MonsterImageMid->SetVisibility(ESlateVisibility::Collapsed);
		TimerDelegate.BindUFunction(this, "SpawnNewMonsterBP", MonsterIndex);
		GetWorld()->GetTimerManager().SetTimer(TimerHandleMid, TimerDelegate, RespawnTime, false);
		break;
	case 2:
		MonsterImageRight->SetVisibility(ESlateVisibility::Collapsed);
		TimerDelegate.BindUFunction(this, "SpawnNewMonsterBP", MonsterIndex);
		GetWorld()->GetTimerManager().SetTimer(TimerHandleRight, TimerDelegate, RespawnTime, false);
		break;
	default:
		MonsterImageLeft->SetVisibility(ESlateVisibility::Collapsed);
		break;
	}

}

void UInGameWidget::OnWidgetFocus()
{
	SpawnNewMonster(0);
	SpawnNewMonster(1);
	SpawnNewMonster(2);
}

void UInGameWidget::OnWidgetFocusAgain(TArray<uint8> MonsterArrayCopy)
{
	MonsterArrayID[0] = MonsterArrayCopy[0];
	MonsterArrayID[1] = MonsterArrayCopy[1];
	MonsterArrayID[2] = MonsterArrayCopy[2];
	
	RespawnNewMonster();
	RespawnNewMonster();
	RespawnNewMonster();
}

void UInGameWidget::SpawnNewMonster(uint8 MonsterIndex)
{
	if(MonsterArray.Num() < 1) {return;}
	const uint8 RandomMonsterIndex = FMath::RandRange(0, MonsterArray.Num() - 1);
	
	switch(MonsterIndex)
	{
	case 0:
		MonsterImageLeft->SetBrushFromTexture(MonsterArray[RandomMonsterIndex]);
		MonsterImageLeft->SetVisibility(ESlateVisibility::Visible);
		ButtonCombatLeft->SetIsEnabled(true);
		ButtonCombatLeft->SetVisibility(ESlateVisibility::Visible);
		ImageCombatLeft->SetVisibility(ESlateVisibility::Visible);
		TextCombatLeft->SetVisibility(ESlateVisibility::Visible);

		// for saving
		MonsterArrayID[0] = RandomMonsterIndex;
		
		break;
	case 1:
		MonsterImageMid->SetBrushFromTexture(MonsterArray[RandomMonsterIndex]);
		MonsterImageMid->SetVisibility(ESlateVisibility::Visible);
		ButtonCombatMid->SetIsEnabled(true);
		ButtonCombatMid->SetVisibility(ESlateVisibility::Visible);
		ImageCombatMid->SetVisibility(ESlateVisibility::Visible);
		TextCombatMid->SetVisibility(ESlateVisibility::Visible);

		// for saving
		MonsterArrayID[1] = RandomMonsterIndex;
		
		break;
	case 2:
		MonsterImageRight->SetBrushFromTexture(MonsterArray[RandomMonsterIndex]);
		MonsterImageRight->SetVisibility(ESlateVisibility::Visible);
		ButtonCombatRight->SetIsEnabled(true);
		ButtonCombatRight->SetVisibility(ESlateVisibility::Visible);
		ImageCombatRight->SetVisibility(ESlateVisibility::Visible);
		TextCombatRight->SetVisibility(ESlateVisibility::Visible);
		
		// for saving
		MonsterArrayID[2] = RandomMonsterIndex;
		
		break;
	default:
		MonsterImageLeft->SetBrushFromTexture(MonsterArray[RandomMonsterIndex]);
		MonsterImageLeft->SetVisibility(ESlateVisibility::Visible);
		ButtonCombatLeft->SetIsEnabled(true);
		ButtonCombatLeft->SetVisibility(ESlateVisibility::Visible);
		ImageCombatLeft->SetVisibility(ESlateVisibility::Visible);
		TextCombatLeft->SetVisibility(ESlateVisibility::Visible);

		// for saving
		MonsterArrayID[0] = RandomMonsterIndex;
		
		break;
	}
}

void UInGameWidget::RespawnNewMonster()
{
	if(MonsterArray.Num() < 1) {return;}
	
	MonsterImageLeft->SetBrushFromTexture(MonsterArray[MonsterArrayID[0]]);
	MonsterImageLeft->SetVisibility(ESlateVisibility::Visible);
	ButtonCombatLeft->SetIsEnabled(true);
	ButtonCombatLeft->SetVisibility(ESlateVisibility::Visible);
	ImageCombatLeft->SetVisibility(ESlateVisibility::Visible);
	TextCombatLeft->SetVisibility(ESlateVisibility::Visible);


	MonsterImageMid->SetBrushFromTexture(MonsterArray[MonsterArrayID[1]]);
	MonsterImageMid->SetVisibility(ESlateVisibility::Visible);
	ButtonCombatMid->SetIsEnabled(true);
	ButtonCombatMid->SetVisibility(ESlateVisibility::Visible);
	ImageCombatMid->SetVisibility(ESlateVisibility::Visible);
	TextCombatMid->SetVisibility(ESlateVisibility::Visible);
	

	MonsterImageRight->SetBrushFromTexture(MonsterArray[MonsterArrayID[2]]);
	MonsterImageRight->SetVisibility(ESlateVisibility::Visible);
	ButtonCombatRight->SetIsEnabled(true);
	ButtonCombatRight->SetVisibility(ESlateVisibility::Visible);
	ImageCombatRight->SetVisibility(ESlateVisibility::Visible);
	TextCombatRight->SetVisibility(ESlateVisibility::Visible);
	
}