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
		GetWorld()->GetTimerManager().SetTimer(TimerHandleLeft, TimerDelegate, 3.0f, false);
		break;
	case 1:
		MonsterImageMid->SetVisibility(ESlateVisibility::Collapsed);
		TimerDelegate.BindUFunction(this, "SpawnNewMonsterBP", MonsterIndex);
		GetWorld()->GetTimerManager().SetTimer(TimerHandleMid, TimerDelegate, 3.0f, false);
		break;
	case 2:
		MonsterImageRight->SetVisibility(ESlateVisibility::Collapsed);
		TimerDelegate.BindUFunction(this, "SpawnNewMonsterBP", MonsterIndex);
		GetWorld()->GetTimerManager().SetTimer(TimerHandleRight, TimerDelegate, 3.0f, false);
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
		break;
	case 1:
		MonsterImageMid->SetBrushFromTexture(MonsterArray[RandomMonsterIndex]);
		MonsterImageMid->SetVisibility(ESlateVisibility::Visible);
		ButtonCombatMid->SetIsEnabled(true);
		ButtonCombatMid->SetVisibility(ESlateVisibility::Visible);
		ImageCombatMid->SetVisibility(ESlateVisibility::Visible);
		TextCombatMid->SetVisibility(ESlateVisibility::Visible);
		break;
	case 2:
		MonsterImageRight->SetBrushFromTexture(MonsterArray[RandomMonsterIndex]);
		MonsterImageRight->SetVisibility(ESlateVisibility::Visible);
		ButtonCombatRight->SetIsEnabled(true);
		ButtonCombatRight->SetVisibility(ESlateVisibility::Visible);
		ImageCombatRight->SetVisibility(ESlateVisibility::Visible);
		TextCombatRight->SetVisibility(ESlateVisibility::Visible);
		break;
	default:
		MonsterImageLeft->SetBrushFromTexture(MonsterArray[RandomMonsterIndex]);
		MonsterImageLeft->SetVisibility(ESlateVisibility::Visible);
		ButtonCombatLeft->SetIsEnabled(true);
		ButtonCombatLeft->SetVisibility(ESlateVisibility::Visible);
		ImageCombatLeft->SetVisibility(ESlateVisibility::Visible);
		TextCombatLeft->SetVisibility(ESlateVisibility::Visible);
		break;
	}
}
