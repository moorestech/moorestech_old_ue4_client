#pragma once
#include "moorestech_client/Network/Util/BitArrayEnumerator.h"

UCLASS()
class AEventPacketAnalysisBase:public AActor
{
	GENERATED_BODY()
	
public:
	virtual ~AEventPacketAnalysisBase() = default;
	virtual void Analysis(BitArrayEnumerator* BitArrayEnumerator);
	
};
