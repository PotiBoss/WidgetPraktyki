// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "OptionsWidget.generated.h"

/**
 *
 *
 */
class UButton;
class UImage;
class USlider;
class UProgressBar;
UCLASS()
class WIDGETPRAKTYKI_API UOptionsWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void OnHoverButton(UImage* ButtonFrame, UButton* Button, bool bCheck);

	UFUNCTION(BlueprintCallable)
	void OnUnhoverButton(UImage* ButtonFrame, UButton* Button, bool bCheck);

	UFUNCTION(BlueprintCallable)
	void HDRumbleClicked(UButton* Button);

	UFUNCTION(BlueprintCallable)
	void InverseYClicked(UButton* Button);

	
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

	// IMAGES/BACKGROUNDS
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageButtonHDRumble;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageCheckmarkHDRumble;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageButtonInverseY;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageCheckmarkInverseY;
};
