#pragma once
#include "PacketAnalysisBase.h"

class ChunkDataPacketAnalysis : public PacketAnalysisBase
{
public:
	void Analysis(TArray<uint8> ReceiveBuffer);
};
