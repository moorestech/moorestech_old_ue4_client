#include "CallPacketAnalysis.h"

#include "moorestech_client/Network/Util/BitArrayEnumerator.h"
#include "PacketAnalysis/ChunkDataPacketAnalysis.h"
#include "PacketAnalysis/DummyPacketAnalysis.h"

// Sets default values
ACallPacketAnalysis::ACallPacketAnalysis()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACallPacketAnalysis::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACallPacketAnalysis::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACallPacketAnalysis::Analysis(TArray<uint8> ReceiveBuffer)
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
		PacketAnalysisBases[bit->MoveNextToShort()]->Analysis(bit);
		delete bit;
	}
	catch (...)
	{
		UE_LOG(LogTemp, Error, TEXT("Packet Analysis Error"));
	}
}