// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/ProgressBar.h"
#include "OptionsWidget.generated.h"

/**
 *
 *
 */

class UButton;
class UImage;
class USlider;
class UProgressBar;
class UMyGameInstance;
UCLASS()
class WIDGETPRAKTYKI_API UOptionsWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void InitWidget();
	
	UFUNCTION(BlueprintCallable)
	void OnHoverButton(UImage* ButtonFrame, UButton* Button, bool bCheck);

	UFUNCTION(BlueprintCallable)
	void OnUnhoverButton(UImage* ButtonFrame, UButton* Button, bool bCheck);

	UFUNCTION(BlueprintCallable)
	void OnHoverBack(UImage* ButtonBgn);

	UFUNCTION(BlueprintCallable)
	void OnUnhoverBack(UImage* ButtonBgn);

	UFUNCTION(BlueprintCallable)
	void ClickedBack();

	UFUNCTION(BlueprintCallable)
	void HDRumbleClicked(UButton* Button);

	UFUNCTION(BlueprintCallable)
	void InverseYClicked(UButton* Button);

	UFUNCTION(BlueprintCallable)
	void SliderChange(UProgressBar* ProgressBar, float SliderValue);

	UFUNCTION(BlueprintCallable)
	void SliderSave();

	UPROPERTY()
	UMyGameInstance* GameInstance;
	
	UPROPERTY(BlueprintReadWrite)
	bool bHDRumble = false;

	UPROPERTY(BlueprintReadWrite)
	bool bInverseY = false;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageBackgroundCave;

	// WIDGET BUTTONS
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonHDRumble;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonInverseY;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonBack;

	// IMAGES/BACKGROUNDS
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageButtonHDRumble;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageCheckmarkHDRumble;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageButtonInverseY;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageCheckmarkInverseY;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageBackBgn;

	// SLIDERS/BARS
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	USlider* SliderEffects;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	USlider* SliderMusic;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* ProgressBarEffects;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* ProgressBarMusic;
};
