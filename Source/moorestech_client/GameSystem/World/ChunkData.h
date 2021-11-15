#pragma once
#include "moorestech_client/GameSystem/Blocks/Base/moorestechBlockBase.h"

class ChunkData
{
public:
	ChunkData(int X, int Y, TArray<int> BlockIds, TArray<AMoorestechBlockBase*>& BlockBases)
		: X(X),
		  Y(Y),
		  blockIds(BlockIds),
		  blockBases(BlockBases)
	{
	}

	int GetX();
	int GetY();
	int GetBlockId(int index);
	void SetBlockId(int index,int id);
	AMoorestechBlockBase& GetBlock(int index);
	void SetBlock(int index,AMoorestechBlockBase* block);
	
	
private:
	int X;
	int Y;
	TArray<int> blockIds;
	TArray<AMoorestechBlockBase*>& blockBases;
};
