// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include "InventoryWidget.h"

UMyGameInstance::UMyGameInstance()
{
	MonsterArrayID.Init(0, 3);
	InventorySoulsButtonsSave.Init(FSoul(),20);
	InventorybHidden.Init(false,20);
}

void UMyGameInstance::OnGameWidgetQuit(TArray<uint8> MonsterArray)
{
	for(int i = 0; i < MonsterArray.Num(); i++)
	{
		MonsterArrayID[i] = MonsterArray[i];
	}
}

void UMyGameInstance::OnInventoryQuit(TArray<FSoul>InventorySoulsButtonsArray)
{
	for(int i = 0; i < InventorySoulsButtonsArray.Num(); i++)
	{
		InventorySoulsButtonsSave[i] = InventorySoulsButtonsArray[i];
	}
}
