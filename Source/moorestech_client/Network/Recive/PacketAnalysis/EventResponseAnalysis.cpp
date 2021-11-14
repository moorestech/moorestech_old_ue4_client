// Fill out your copyright notice in the Description page of Project Settings.


#include "EventResponseAnalysis.h"


// Sets default values
AEventResponseAnalysis::AEventResponseAnalysis()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AEventResponseAnalysis::Analysis(BitArrayEnumerator* BitArrayEnumerator)
{
	short i = BitArrayEnumerator->MoveNextToShort();
	if(i < EventPacketAnalysisBases.Num())
	{
		EventPacketAnalysisBases[i]->Analysis(BitArrayEnumerator);
	}
}

