// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkBlockManager.h"
#include "map"
constexpr int CHUNK_SIZE = 20;

// Sets default values
AChunkBlockManager::AChunkBlockManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AChunkBlockManager::AddChunk(int x, int y, TArray<int> chunkIds)
{
	for (int i = 0; i < chunks.Num(); ++i)
	{
		if (chunks[i].X != x || chunks[i].Y != y)
			continue;
		
		chunks[i].chunkIds = chunkIds;
		for (int j = 0; j < chunks.Num(); ++j)
		{
			//TODO Get block id to re generate chunk
		}	

		return;
	}
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

