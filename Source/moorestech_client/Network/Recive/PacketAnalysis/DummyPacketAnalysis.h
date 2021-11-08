#pragma once
#include "PacketAnalysisBase.h"
#include "moorestech_client/Network/Util/BitArrayEnumerator.h"

class DummyPacketAnalysis : public PacketAnalysisBase
{
public:
	void Analysis(BitArrayEnumerator* ReceiveBuffer);
};

