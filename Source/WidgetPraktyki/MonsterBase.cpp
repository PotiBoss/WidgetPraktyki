// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterBase.h"
#include "PaperSpriteComponent.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AMonsterBase::AMonsterBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Enemy Sprite Component"));

	SetRootComponent(SpriteComponent);
}
// Called when the game starts or when spawned
void AMonsterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonsterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

