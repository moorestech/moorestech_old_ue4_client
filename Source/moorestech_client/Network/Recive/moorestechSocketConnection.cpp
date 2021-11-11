// Fill out your copyright notice in the Description page of Project Settings.


#include "PacketAnalysis/DummyPacketAnalysis.h"
#include "moorestechSocketConnection.h"

void AmoorestechSocketConnection::Receive(TArray<uint8> ReceiveBuffer)
{
	
	if (!init)
	{
		PacketAnalysisBases.Add(new DummyPacketAnalysis());
		PacketAnalysisBases.Add(ChunkDataPacketAnalysis);
		init = true;
	}
	try
	{
		BitArrayEnumerator* bit = new BitArrayEnumerator(ReceiveBuffer);
		int i = bit->MoveNextToShort();
		if(i < PacketAnalysisBases.Num())
		{
			PacketAnalysisBases[i]->Analysis(bit);	
		}
		delete bit;
	}
	catch (...)
	{
		UE_LOG(LogTemp, Error, TEXT("Packet Analysis Error"));
	}
}


