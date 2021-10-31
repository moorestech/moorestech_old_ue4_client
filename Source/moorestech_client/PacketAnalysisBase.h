#pragma once

class PacketAnalysisBase
{
public:
	virtual void Analusis(TArray<uint8> ReceiveBuffer);
};
