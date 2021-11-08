#pragma once
#include "moorestech_client/Network/Util/BitArrayEnumerator.h"

class PacketAnalysisBase
{
public:
	virtual ~PacketAnalysisBase() = default;
	virtual void Analysis(BitArrayEnumerator* BitArrayEnumerator);
};
