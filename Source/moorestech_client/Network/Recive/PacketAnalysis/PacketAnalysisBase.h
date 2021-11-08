#pragma once

class PacketAnalysisBase
{
public:
	virtual ~PacketAnalysisBase() = default;
	virtual void Analysis(TArray<uint8> ReceiveBuffer);
};
