// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
class UButton;
class UImage;
class UMyGameInstance;
class UTexture2D;
class UTextBlock;
UCLASS()
class WIDGETPRAKTYKI_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintCallable)
	void InitWidget();
	
	UFUNCTION(BlueprintCallable)
	void QuitInventory();

	UFUNCTION(BlueprintCallable)
	void HideSoulInfo();

	UFUNCTION()
	void InitButtons();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<uint8> InventorySoulsID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UButton*> InventorySoulsButtons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UTexture2D*> InventorySoulsSprites;
	
	// WIDGET BUTTONS
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul0;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul1;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul2;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul3;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul4;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul5;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul6;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul7;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul8;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul9;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul10;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul11;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul12;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul13;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul14;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul15;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul16;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul17;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul18;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonSoul19;

	// WIDGET IMAGES
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageSoulDescription;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageUseBgn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageUseFrame;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageUseBgnSolo;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageUseFrameSolo;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageDestroyBgn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageDestroyFrame;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageDestroyBgnSolo;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageDestroyFrameSolo;

	// WIDGET TEXT
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextSoulName;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextSoulDescription;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextUse;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextUseSolo;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextDestroy;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextDestroySolo;
};
