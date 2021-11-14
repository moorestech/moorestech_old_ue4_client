#pragma once
#include "Base/PacketAnalysisBase.h"
#include "moorestech_client/Network/Util/BitArrayEnumerator.h"

class DummyPacketAnalysis : public PacketAnalysisBase
{
public:
	virtual void Analysis(BitArrayEnumerator* BitArrayEnumerator) override;
};

