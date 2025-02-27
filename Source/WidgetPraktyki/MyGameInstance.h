// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "InventoryWidget.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */

UCLASS()
class WIDGETPRAKTYKI_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMyGameInstance();
	
	UFUNCTION(BlueprintCallable)
	void OnGameWidgetQuit(TArray<uint8> MonsterArray);

	UFUNCTION(BlueprintCallable)
	void OnInventoryQuit(TArray<FSoul>InventorySoulsButtonsArray);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<uint8> MonsterArrayID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSoul> InventorySoulsButtonsSave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<uint8> InventoryIndexes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<bool> InventorybHidden;

	UPROPERTY(BlueprintReadWrite)
	bool bFirstInitGame = true;

	UPROPERTY(BlueprintReadWrite)
	bool bFirstInitInventory = true;

	UPROPERTY(BlueprintReadWrite)
	TEnumAsByte<ESoulLocation> Location = CITY;

	// OPTIONS
	UPROPERTY(BlueprintReadWrite)
	float EffectsFloat = 0.0f;

	UPROPERTY(BlueprintReadWrite)
	float MusicFloat = 0.0f;

	UPROPERTY(BlueprintReadWrite)
	bool bHDRumble = false;

	UPROPERTY(BlueprintReadWrite)
	bool bHDRumbleStrong = false;
	
	UPROPERTY(BlueprintReadWrite)
	bool bHDRumbleStronger = false;
	
	UPROPERTY(BlueprintReadWrite)
	bool bInverseY = false;
	
};