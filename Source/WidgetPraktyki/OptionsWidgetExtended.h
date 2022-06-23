// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OptionsWidget.h"
#include "OptionsWidgetExtended.generated.h"

/**
 * 
 */
UCLASS()
class WIDGETPRAKTYKI_API UOptionsWidgetExtended : public UOptionsWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void InitWidgetExtended();

	UFUNCTION()
	void InitButtonsExtended();

	UFUNCTION(BlueprintCallable)
	void StrongVibrationsClicked(UButton* Button);
	UFUNCTION(BlueprintCallable)
	void StrongerVibrationsClicked(UButton* Button);

	UPROPERTY(BlueprintReadWrite)
	bool bStrongVibrations = false;

	UPROPERTY(BlueprintReadWrite)
	bool bStrongerVibrations = false;
	
	// WIDGET BUTTONS
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonStrongVibrations;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonStrongerVibrations;
	// IMAGES/BACKGROUNDS
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageButtonStrongVibrations;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageCheckmarkStrongVibrations;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageButtonStrongerVibrations;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageCheckmarkStrongerVibrations;
};
