#include "moorestechSocketConnection.h"
#include "PacketAnalysis/DummyPacketAnalysis.h"

// パケットを受信し、各クラスにパケットのパース処理を振り分けている
//現状の問題点として、作ったクラスをBPにしてマップに置き、アタッチすることでこれを実現している
//UE4とC++に詳しくないのでできないが、理想としては全て動的にインスタンスを生成して処理を移譲させたい
void AmoorestechSocketConnection::Receive(TArray<uint8> ReceiveBuffer)
{
	
	if (!init)
	{
		PacketAnalysisBases.Add(new DummyPacketAnalysis());
		PacketAnalysisBases.Add(ChunkDataPacketAnalysis);
		PacketAnalysisBases.Add(new DummyPacketAnalysis());//他プレイヤーの座標を取得するパケット(WIP)
		PacketAnalysisBases.Add(EventResponseAnalysis);
		PacketAnalysisBases.Add(PlayerInventoryPacketAnalysis);
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


