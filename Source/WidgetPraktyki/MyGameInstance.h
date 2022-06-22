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


};
