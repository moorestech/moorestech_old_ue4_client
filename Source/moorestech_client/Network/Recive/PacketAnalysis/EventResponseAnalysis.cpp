#include "EventResponseAnalysis.h"

AEventResponseAnalysis::AEventResponseAnalysis()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEventResponseAnalysis::Analysis(BitArrayEnumerator* BitArrayEnumerator)
{
	short i = BitArrayEnumerator->MoveNextToShort();
	UE_LOG(LogTemp, Warning, TEXT("[moorestech]Recive Event ID:%d"),i);
	if(i < EventPacketAnalysisBases.Num())
	{
		EventPacketAnalysisBases[i]->Analysis(BitArrayEnumerator);
	}
}

