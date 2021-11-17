// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkBlockManager.h"
#include "BlockPositionToChunkPosition.h"

FVector UBlockPositionToChunkPosition::BlockPositionToChunkPosition(int blockX, int blockY)
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
	FVector r = {(float)chunkX, (float)chunkY, (float)0};
	return r;
}
