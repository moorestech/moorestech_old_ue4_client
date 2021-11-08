#pragma once
#include "PacketAnalysisBase.h"

class ChunkDataPacketAnalysis : public PacketAnalysisBase
{
public:
	virtual void Analysis(BitArrayEnumerator* BitArrayEnumerator) override;
};
