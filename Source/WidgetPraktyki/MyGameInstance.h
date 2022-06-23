// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<uint8> MonsterArrayID;

	UPROPERTY(BlueprintReadWrite)
	bool bFirstInitGame = true;

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
