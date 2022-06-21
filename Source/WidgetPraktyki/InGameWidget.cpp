// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameWidget.h"
#include "Components/Image.h"


void UInGameWidget::MonsterKilled(uint8 MonsterIndex)
{
	switch(MonsterIndex)
	{
	case 0:
		MonsterImageLeft->SetVisibility(ESlateVisibility::Collapsed);
		break;
	case 1:
		MonsterImageMid->SetVisibility(ESlateVisibility::Collapsed);
		break;
	case 2:
		MonsterImageRight->SetVisibility(ESlateVisibility::Collapsed);
		break;
	default:
		MonsterImageLeft->SetVisibility(ESlateVisibility::Collapsed);
		break;
	}
	TimerDelegate.BindUFunction(this, "SpawnNewMonsterBP", MonsterIndex);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 3.0f, false);
}

void UInGameWidget::OnWidgetFocus()
{
	SpawnNewMonster(0);
	SpawnNewMonster(1);
	SpawnNewMonster(2);
}

void UInGameWidget::SpawnNewMonster(uint8 MonsterIndex)
{
	//MonsterArray[MonsterIndex] = true;
	
	switch(MonsterIndex)
	{
	case 0:
		MonsterImageLeft->SetBrushFromTexture(MonsterBase);
		MonsterImageLeft->SetVisibility(ESlateVisibility::Visible);
		break;
	case 1:
		MonsterImageMid->SetBrushFromTexture(MonsterBase);
		MonsterImageMid->SetVisibility(ESlateVisibility::Visible);
		break;
	case 2:
		MonsterImageRight->SetBrushFromTexture(MonsterBase);
		MonsterImageRight->SetVisibility(ESlateVisibility::Visible);
		break;
	default:
		MonsterImageLeft->SetBrushFromTexture(MonsterBase);
		MonsterImageLeft->SetVisibility(ESlateVisibility::Visible);
		break;
	}
}
