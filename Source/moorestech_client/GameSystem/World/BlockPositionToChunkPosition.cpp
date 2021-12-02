#include "BlockPositionToChunkPosition.h"
#include "ChunkBlockManager.h"

FVector UBlockPositionToChunkPosition::BlockPositionToChunkPosition(int blockX, int blockY)
{
	int ChunkSize = CHUNK_SIZE;
	int chunkX = blockX / ChunkSize;
	
	if (blockX < 0)
	{
		chunkX -= 1;
	}
	int chunkY = blockY / ChunkSize;
	if (blockY < 0)
	{
		chunkY -= 1;
	}
	int chunkXposition = chunkX * ChunkSize;
	int chunkYposition = chunkY * ChunkSize;
	
	FVector r = {(float)chunkXposition, (float)chunkYposition, (float)0};
	return r;
}
