// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameWidget.generated.h"

class UButton;
class UImage;
class UTexture2D;
class UTextBlock;

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

	UFUNCTION(BlueprintCallable)
	void OnWidgetFocusAgain(TArray<uint8> MonsterArrayCopy);

	UFUNCTION(BlueprintCallable)
	void ChangeFocus(UButton* Button);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<uint8> MonsterArrayID;
		
	UPROPERTY(EditAnywhere)
	TArray<UTexture2D*> MonsterArray;

protected:
	UFUNCTION(BlueprintCallable)
	void SpawnNewMonster(uint8 MonsterIndex);

	UFUNCTION(BlueprintCallable)
	void RespawnNewMonster();

	UPROPERTY(EditAnywhere)
	float RespawnTime = 1.0f;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* MonsterImageLeft;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* MonsterImageMid;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* MonsterImageRight;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* BackgroundCave;

	// WIDGET BUTTONS
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonBowLeft;
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
	UTextBlock* TextCombatMid;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextCombatRight;
	

	FTimerHandle TimerHandleLeft;
	FTimerHandle TimerHandleMid;
	FTimerHandle TimerHandleRight;
	FTimerDelegate TimerDelegate;
};

