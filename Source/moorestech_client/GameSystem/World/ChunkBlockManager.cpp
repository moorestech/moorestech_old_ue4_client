// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkBlockManager.h"

// Sets default values
AChunkBlockManager::AChunkBlockManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AChunkBlockManager::AddChunk(int x, int y, TArray<int> chunkData)
{
	
}

// Called when the game starts or when spawned
void AChunkBlockManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChunkBlockManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

