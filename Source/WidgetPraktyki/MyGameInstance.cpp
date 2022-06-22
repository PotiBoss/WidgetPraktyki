// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
}

void UMyGameInstance::OnGameWidgetQuit(TArray<uint8> MonsterArray)
{
	MonsterArrayID = MonsterArray;
}
