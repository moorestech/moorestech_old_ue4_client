// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkBlockManager.h"
#include "moorestech_client/GameSystem/Blocks/Base/moorestechBlockBase.h"


void AChunkBlockManager::SetChunk(int chunkX,int chunky,TArray<int>& chunkData)
{
	//SetChunkEvent(chunkX,chunky,chunkData);
}

//BP側で扱いやすいデータに変換する
void AChunkBlockManager::SetBlock(int blockX, int blockY, int blockId)
{
	int ChunkSize = CHUNK_SIZE;

	//C++は余剰の計算がちゃんとしてないのでif文でチャンク座標を求める
	int chunkX = 0;
	if(blockX < 0)
	{
		if(-blockX < ChunkSize)
		{
			chunkX = -ChunkSize;
		}
		else
		{
			chunkX = blockX - ChunkSize - (ChunkSize + blockX);
		}
	}else
	{
		if(blockX < ChunkSize)
		{
			chunkX = 0;
		}
		else
		{
			chunkX = blockX - (blockX % ChunkSize);
		}
	}
	
	int chunkY = 0;
	if(blockY < 0)
	{
		if(-blockY < ChunkSize)
		{
			chunkY = -ChunkSize;
		}
		else
		{
			chunkY = blockY - ChunkSize - (ChunkSize + blockY);
		}
	}else
    {
        if(blockY < ChunkSize)
        {
            chunkY = 0;
        }
        else
        {
            chunkY = blockY - (blockY % ChunkSize);
        }
    }

	
	int blockIndex = (blockY % ChunkSize) + (blockY % ChunkSize) * ChunkSize;
	//indexを絶対値に
	if (blockIndex < 0)
    {
        blockIndex = -blockIndex;
    }
	UE_LOG(LogTemp, Warning, TEXT("ChunkX:%d ChunkY:%d BlockX:%d BlockY:%d BlockIndex:%d"),chunkX, chunkY , blockX, blockY, blockIndex);
	//sSetBlockEvent(chunkX, chunkY,blockX,blockY, blockIndex, blockId);
}

