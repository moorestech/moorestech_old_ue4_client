// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkBlockManager.h"
#include "map"
#include "moorestech_client/GameSystem/Blocks/Base/moorestechBlockBase.h"


void AChunkBlockManager::SetChunk(int chunkX,int chunky,TArray<int>& chunkData)
{
	SetChunkEvent(chunkX,chunky,chunkData);
}

void AChunkBlockManager::SetBlock(int blockX, int blockY, int blockId)
{
	SetBlockEvent(blockX, blockY, blockId);
}

