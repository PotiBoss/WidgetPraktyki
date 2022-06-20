// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonsterSpawner.generated.h"

UCLASS()
class WIDGETPRAKTYKI_API AMonsterSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonsterSpawner();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TArray<class AMonsterBase*> MonsterArray;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AMonsterBase> MonsterBase;
	
	UPROPERTY(EditAnywhere)
	FVector LeftMonsterPos;
	UPROPERTY(EditAnywhere)
	FRotator LeftMonsterRot;
	
	UPROPERTY(EditAnywhere)
	FVector MidMonsterPos;
	UPROPERTY(EditAnywhere)
	FRotator MidMonsterRot;
	
	UPROPERTY(EditAnywhere)
	FVector RightMonsterPos;
	UPROPERTY(EditAnywhere)
	FRotator RightMonsterRot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
