// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkBlockManager.h"
#include "moorestech_client/GameSystem/Blocks/Base/moorestechBlockBase.h"


void AChunkBlockManager::SetChunk(int chunkX,int chunky,TArray<int>& chunkData)
{
	SetChunkEvent(chunkX,chunky,chunkData);
}

void AChunkBlockManager::SetBlock(int blockX, int blockY, int blockId)
{
	//BP側で扱いやすいデータに変換する
	int ChunkSize = CHUNK_SIZE;
	
	int chunkX = blockX -  (blockX % ChunkSize);
	int chunkY = blockY -  (blockY % ChunkSize);
	int blockIndex = (blockY % ChunkSize) + (blockX - chunkX) * ChunkSize;
	
	SetBlockEvent(chunkX, chunkY,blockX,blockY, blockIndex, blockId);
}

