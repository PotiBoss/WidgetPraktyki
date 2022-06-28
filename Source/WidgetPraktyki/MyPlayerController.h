// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

UENUM()
enum EUIState
{
	UI_InGame,
	UI_Pause,
	UI_Inventory,
	UI_Options,
	UI_OptionsExtended,
	UI_ReadMe,
	UI_Credits
};

UCLASS()


class WIDGETPRAKTYKI_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:


	UPROPERTY(BlueprintReadWrite)
	TEnumAsByte<EUIState> UIStateEnum;

	AMyPlayerController();

	void UpdateUI();
	
	void HideInventory();

	uint8 GetUIState();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void ChangeUIState(TEnumAsByte<EUIState> EnumUIState);

	void ApplyUIChange(TSubclassOf<class UUserWidget> Widget);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UUserWidget* InGameWidget;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UUserWidget* InventoryWidget;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UUserWidget* PauseWidget;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> GameHUDClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> InventoryClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> PauseClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> OptionsClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> OptionsExtendedClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> ReadMeClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> CreditsClass;
	

	UPROPERTY()
	class UUserWidget* CurrentWidget;
};

