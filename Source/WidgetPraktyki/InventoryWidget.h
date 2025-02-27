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
class UCanvasPanel;

UENUM()
enum ESoulOptions
{
	Use,
	Destroy,
	UseAndDestroy
};

UENUM()
enum ESoulLocation
{
	SWAMPS,
	DUNGEON,
	CASTLE,
	CITY,
	TOWER
};

USTRUCT(BlueprintType)
struct FSoul
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Image = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* Button = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ESoulOptions> Option;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ESoulLocation> Location;
};


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

	UFUNCTION(BlueprintCallable)	
	void SelectSoul(FSoul Soul);

	UFUNCTION(BlueprintCallable)	
	void SetSoul(uint8 SoulIndex, uint8 RandomNumber);

	UFUNCTION()
	void InitButtons();

	UFUNCTION(BlueprintCallable)
	void ButtonHovered(UImage* Image);

	UFUNCTION(BlueprintCallable)
	void ButtonUnhovered(UImage* Image);

	UFUNCTION(BlueprintCallable)
	void UseClicked();
	
	UFUNCTION(BlueprintCallable)
	void DestroyClicked();
	
	UFUNCTION(BlueprintCallable)
	void CantUse();

	UFUNCTION(BlueprintCallable)
	void CantOkUse();

	UFUNCTION(BlueprintCallable)
	void NoClicked();

	UFUNCTION(BlueprintCallable)
	void YesClicked();

	UFUNCTION(BlueprintCallable)
	void FocusAgain();

	UFUNCTION(BlueprintCallable)
	void RandomizeSouls();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSoul> InventorySoulsButtons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSoul> InventorySoulsSprites;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 SelectedSoulIndex = NULL;

	UPROPERTY()
	class UMyGameInstance* GameInstance;
	
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

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonUse;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonDestroy;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonUseSolo;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonDestroySolo;

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
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextUseSoulVariable;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextDestroySoulVariable;

	// CANVAS
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* CanvasDestroy;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* CanvasUse;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* CanvasCantUse;
};
