// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterSpawner.h"
#include "MonsterBase.h"

// Sets default values
AMonsterSpawner::AMonsterSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterSpawner::BeginPlay()
{
	Super::BeginPlay();

	// checks if we setup 3 monsters
	if(MonsterArray.Num() < 3) {return;}

	FActorSpawnParameters SpawnParams;

	MonsterArray[0] = GetWorld()->SpawnActor<AMonsterBase>(LeftMonsterPos + GetTransform().GetLocation(), LeftMonsterRot, SpawnParams);
	MonsterArray[1] = GetWorld()->SpawnActor<AMonsterBase>(MidMonsterPos + GetTransform().GetLocation(), MidMonsterRot, SpawnParams);
	MonsterArray[2] = GetWorld()->SpawnActor<AMonsterBase>(RightMonsterPos + GetTransform().GetLocation(), RightMonsterRot, SpawnParams);
}

// Called every frame
void AMonsterSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

