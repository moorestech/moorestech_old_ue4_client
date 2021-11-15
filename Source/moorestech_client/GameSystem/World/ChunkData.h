#pragma once
#include <iostream>
#include <vector>
#include "moorestech_client/GameSystem/Blocks/Base/moorestechBlockBase.h"

class ChunkData
{
public:
	ChunkData(int X, int Y)
		: X(X),
		  Y(Y)
	{
	}
	~ChunkData();
	
	int GetX();
	int GetY();
	
	int GetBlockId(int index);
	void SetBlockId(int index,int id);
	void AddBlockId(int id);
	
	AMoorestechBlockBase& GetBlock(int index);
	void SetBlock(int index,AMoorestechBlockBase* block);
	void AddBlock(AMoorestechBlockBase* block);
	
	
private:
	int X;
	int Y;
	std::vector<int> blockIds;
	std::vector<AMoorestechBlockBase*> blockBases;
};
