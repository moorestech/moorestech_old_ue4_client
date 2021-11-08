#pragma once
#include "PacketAnalysis/PacketAnalysisBase.h"

class CallPacketAnalysis
{
public:
	void Analysis(TArray<uint8> ReceiveBuffer);
private:
	TArray<PacketAnalysisBase*> PacketAnalysisBases;
	bool init = false;
};
