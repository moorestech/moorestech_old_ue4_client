#pragma once
#include "moorestech_client/Network/Util/BitArrayEnumerator.h"

class EventPacketAnalysisBase
{
public:
	virtual ~EventPacketAnalysisBase() = default;
	virtual void Analysis(BitArrayEnumerator* BitArrayEnumerator);
	
};
