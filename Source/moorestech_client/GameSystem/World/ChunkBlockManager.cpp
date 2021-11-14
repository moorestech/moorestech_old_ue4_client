// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkBlockManager.h"
#include "map"
#include "moorestech_client/GameSystem/Blocks/Base/moorestechBlockBase.h"
constexpr int CHUNK_SIZE = 20;


void AChunkBlockManager::AddChunk(int x, int y, TArray<int>& chunkIds)
{
	UE_LOG(LogTemp, Warning, TEXT("[moorestech]AddChunk X:%d Y:%d"), x, y);
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

				//サーバー側でblock[x][y]となっているので、xを割り算して、yを求める。
				const int blockX = x + i / CHUNK_SIZE;
				const int blockY = y + i % CHUNK_SIZE;
				
				chunks[i].chunkBlockBases[j] = GenerateBlockActor->GenerateBlock(blockX,blockY,chunkIds[j]);
			}
		}	
		return;
	}
	TArray<AMoorestechBlockBase*> chunkBlockBases;
	//まだ存在していないチャンクなので、新しく生成する
	for (int i = 0; i < chunkIds.Num(); ++i)
	{
		//サーバー側でblock[x][y]となっているので、xを割り算して、yを求める。
		const int blockX = x + i / CHUNK_SIZE;
		const int blockY = y + i % CHUNK_SIZE;
		chunkBlockBases.Add(GenerateBlockActor->GenerateBlock(blockX,blockY,chunkIds[i]));
	}
	ChunkData ChunkData = { x,y,chunkIds,chunkBlockBases };
	chunks.Add(ChunkData);
}

void AChunkBlockManager::AddBlock(int blockX, int blockY, int blockId)
{
	UE_LOG(LogTemp, Warning, TEXT("[moorestech]AddBlockEvent X:%d Y:%d ID:%d"), blockX, blockY,blockId);
	int chunkX = (blockX / CHUNK_SIZE) * CHUNK_SIZE;
	int chunkY = (blockY / CHUNK_SIZE) * CHUNK_SIZE;
	//チャンクが存在しているか確認
	for (int i = 0; i < chunks.Num(); ++i)
	{
		if (chunks[i].X == chunkX && chunks[i].Y == chunkY)
		{
			int blockIndex = blockY - chunkY + (blockX - chunkX) * CHUNK_SIZE;
			//ブロックIDが違うときに、そのブロックに置き換える
			if (chunks[i].chunkBlockBases[blockIndex]->GetBlockId() != blockId)
            {
                chunks[i].chunkBlockBases[blockIndex]->DeleteBlock();
                delete chunks[i].chunkBlockBases[blockIndex];
                chunks[i].chunkBlockBases[blockIndex] = GenerateBlockActor->GenerateBlock(blockX, blockY, blockId);
            }
		}
	}
	
}

