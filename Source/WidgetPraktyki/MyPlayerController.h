// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class WIDGETPRAKTYKI_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	enum EUIState : uint8
	{
		UI_InGame,
		UI_Pause,
		UI_Inventory
	};

	AMyPlayerController();

	void UpdateUI();

	uint8 GetUIState();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void ChangeUIState(uint8 NewUIState);

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

	uint8 UIState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> GameHUDClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> InventoryClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> PauseClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	class UOverlay* MyOverlay;

	UPROPERTY()
	class UUserWidget* CurrentWidget;
};

