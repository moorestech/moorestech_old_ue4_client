// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkBlockManager.h"

#include "BlockPositionToChunkPosition.h"
#include "moorestech_client/GameSystem/Blocks/Base/moorestechBlockBase.h"


void AChunkBlockManager::SetChunk(int chunkX,int chunky,TArray<int>& chunkData)
{
	SetChunkEvent(chunkX,chunky,chunkData);
}

//BP側で扱いやすいデータに変換する
void AChunkBlockManager::SetBlock(int blockX, int blockY, int blockId)
{
	int ChunkSize = CHUNK_SIZE;

	//C++は余剰の計算がちゃんとしてないのでif文でチャンク座標を求める
	FVector a = UBlockPositionToChunkPosition::BlockPositionToChunkPosition(blockX, blockY);
	int chunkX = (int)a.X;
	int chunkY = (int)a.Y;

	int BlockXinChunk = 0;
	int BlockYinChunk= 0;
	//ブロックの座標からチャンク内の座標を求める
	if(chunkX < 0)
	{
		BlockXinChunk = blockX + -chunkX;
	}else
	{
		BlockXinChunk = blockX - chunkX;
	}
	if (chunkY < 0)
	{
		BlockYinChunk = blockY + -chunkY;
	}else{
		BlockYinChunk = blockY - chunkY;
	}
	
	int blockIndex = BlockYinChunk + BlockXinChunk * ChunkSize;

	UE_LOG(LogTemp, Warning, TEXT("ChunkX:%d ChunkY:%d BlockX:%d BlockY:%d BlockIndex:%d"),chunkX, chunkY , blockX, blockY, blockIndex);
	SetBlockEvent(chunkX, chunkY,blockX,blockY, blockIndex, blockId);
}

