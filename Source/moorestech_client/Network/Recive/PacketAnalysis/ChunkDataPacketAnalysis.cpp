#include "ChunkDataPacketAnalysis.h"
#include "moorestech_client/Network/Util/BitArrayEnumerator.h"

AChunkDataPacketAnalysis::AChunkDataPacketAnalysis()
{
	PrimaryActorTick.bCanEverTick = true;

}
void AChunkDataPacketAnalysis::Analysis(BitArrayEnumerator* BitArrayEnumerator)
{
	TArray<int> chunkData;
	int X = BitArrayEnumerator->MoveNextToInt();
	int Y = BitArrayEnumerator->MoveNextToInt();
	for (int i = 0; i < 20*20; ++i)
	{
		if(BitArrayEnumerator->MoveNextToBit())
		{
			if (BitArrayEnumerator->MoveNextToBit())
			{
				BitArrayEnumerator->MoveNextToBit();
				chunkData.Add(BitArrayEnumerator->MoveNextToInt());
			}else
			{
				if (BitArrayEnumerator->MoveNextToBit())
				{
					chunkData.Add(BitArrayEnumerator->MoveNextToShort());
				}else
				{
					chunkData.Add(BitArrayEnumerator->MoveNextToByte());
				}
			}
		}else
		{
			chunkData.Add(0);
		}
	}
	ChunkBlockManager->SetChunk(X,Y,chunkData);
}
