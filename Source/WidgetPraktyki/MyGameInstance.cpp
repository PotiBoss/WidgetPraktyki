// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	MonsterArrayID = {0,0,0};
}

void UMyGameInstance::OnGameWidgetQuit(TArray<uint8> MonsterArray)
{
	for(int i = 0; i < MonsterArray.Num(); i++)
	{
		MonsterArrayID[i] = MonsterArray[i];
	}
}
