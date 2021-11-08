#include "CallPacketAnalysis.h"

#include "moorestech_client/Network/Util/BitArrayEnumerator.h"
#include "PacketAnalysis/ChunkDataPacketAnalysis.h"
#include "PacketAnalysis/DummyPacketAnalysis.h"

void CallPacketAnalysis::Analysis(TArray<uint8> ReceiveBuffer)
{
	if (!init)
	{
		PacketAnalysisBases.Add(new DummyPacketAnalysis());
		PacketAnalysisBases.Add(new ChunkDataPacketAnalysis());
		init = true;
	}
	BitArrayEnumerator* bit = new BitArrayEnumerator(ReceiveBuffer);
	PacketAnalysisBases[bit->MoveNextToShort()]->Analysis(bit);
	delete bit;
}