// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkBlockManager.h"
#include "map"
#include "moorestech_client/GameSystem/moorestechBlockBase.h"
constexpr int CHUNK_SIZE = 20;

// Sets default values
AChunkBlockManager::AChunkBlockManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AChunkBlockManager::AddChunk(int x, int y, TArray<int>& chunkIds)
{
	for (int i = 0; i < chunks.Num(); ++i)
	{
		if (chunks[i].X != x || chunks[i].Y != y)
			continue;
		
		chunks[i].chunkIds = chunkIds;
		for (int j = 0; j < chunkIds.Num(); ++j)
		{
			//そのブロックIDが違うときに、そのブロックに置き換える
			if (chunks[i].chunkBlockBases[j]->GetBlockId() != chunkIds[j])
			{
				chunks[i].chunkBlockBases[j]->DeleteBlock();
				delete chunks[i].chunkBlockBases[j];

				const int blockX = x * CHUNK_SIZE + j % CHUNK_SIZE;
				const int blockY = y * CHUNK_SIZE + j / CHUNK_SIZE;
				
				chunks[i].chunkBlockBases[j] = GenerateBlockActor->GenerateBlock(blockX,blockY,chunkIds[j]);
			}
		}	
		return;
	}
	TArray<AMoorestechBlockBase*> chunkBlockBases;
	//まだ存在していないチャンクなので、新しく生成する
	for (int i = 0; i < chunkIds.Num(); ++i)
	{
		const int blockX = x * CHUNK_SIZE + i % CHUNK_SIZE;
		const int blockY = y * CHUNK_SIZE + i / CHUNK_SIZE;
		chunkBlockBases.Add(GenerateBlockActor->GenerateBlock(blockX,blockY,chunkIds[i]));
	}
	ChunkData ChunkData = { x,y,chunkIds,chunkBlockBases };
	chunks.Add(ChunkData);
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

