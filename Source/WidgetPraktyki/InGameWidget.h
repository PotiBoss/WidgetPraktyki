// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class WIDGETPRAKTYKI_API UInGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void MonsterKilled(uint8 MonsterIndex);

	UFUNCTION(BlueprintCallable)
	void OnWidgetFocus();

protected:
	UFUNCTION(BlueprintCallable)
	void SpawnNewMonster(uint8 MonsterIndex);
	
	TArray<bool> MonsterArray = {false, false, false};

	UPROPERTY(EditAnywhere)
	class UTexture2D* MonsterBase;

	UPROPERTY(meta = (BindWidget))
	class UImage* MonsterImageLeft;
	UPROPERTY(meta = (BindWidget))
	class UImage* MonsterImageMid;
	UPROPERTY(meta = (BindWidget))
	class UImage* MonsterImageRight;

	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;
};
