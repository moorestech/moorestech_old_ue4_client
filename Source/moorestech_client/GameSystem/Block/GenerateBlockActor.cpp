// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerateBlockActor.h"

#include "AirBlock.h"


// Sets default values
AGenerateBlockActor::AGenerateBlockActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

moorestechBlockBase* AGenerateBlockActor::GenerateBlock(int32 X, int32 Y, int32 BlockId)
{
	//TODO ここ実装する
	moorestechBlockBase* air = new AirBlock();
	return air;
}

// Called when the game starts or when spawned
void AGenerateBlockActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGenerateBlockActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

