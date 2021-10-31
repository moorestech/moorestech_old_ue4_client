#pragma once

class PacketAnalysisBase
{
public:
	virtual void Analysis(TArray<uint8> ReceiveBuffer);
};
