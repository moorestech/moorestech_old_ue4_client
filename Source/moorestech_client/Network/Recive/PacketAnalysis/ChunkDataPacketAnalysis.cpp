#include "ChunkDataPacketAnalysis.h"

#include "moorestech_client/Network/Util/BitArrayEnumerator.h"

void ChunkDataPacketAnalysis::Analysis(TArray<uint8> ReceiveBuffer)
{
	BitArrayEnumerator* bit = new BitArrayEnumerator(ReceiveBuffer);
	
}
