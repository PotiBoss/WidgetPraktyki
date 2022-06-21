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

	UPROPERTY(EditAnywhere)
	TArray<class UTexture2D*> MonsterArray;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* MonsterImageLeft;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* MonsterImageMid;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* MonsterImageRight;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* BackgroundCave;

	// WIDGET BUTTONS
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* ButtonBowLeft;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonBowMid;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonBowRight;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonCombatLeft;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonCombatMid;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonCombatRight;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonInventory;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonPause;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSwordLeft;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSwordMid;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSwordRight;

	// IMAGES/BACKGROUNDS
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageBowLeft;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageBowLeftbgn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageBowMid;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageBowMidBgn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageBowRight;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageBowRightBgn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageCombatLeft;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageCombatMid;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageCombatRight;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageInventory;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImagePause;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageSwordLeft;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageSwordLeftbgn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageSwordMid;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageSwordMidBgn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageSwordRight;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageSwordRightBgn;

	// TEXT
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextCombatLeft;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextCombatMid;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextCombatRight;
	

	FTimerHandle TimerHandleLeft;
	FTimerHandle TimerHandleMid;
	FTimerHandle TimerHandleRight;
	FTimerDelegate TimerDelegate;
};
