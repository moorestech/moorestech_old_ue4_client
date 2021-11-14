// Fill out your copyright notice in the Description page of Project Settings.

#include "ChunkDataPacketAnalysis.h"
#include "moorestech_client/Network/Util/BitArrayEnumerator.h"

// Sets default values
AChunkDataPacketAnalysis::AChunkDataPacketAnalysis()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChunkDataPacketAnalysis::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChunkDataPacketAnalysis::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AChunkDataPacketAnalysis::Analysis(BitArrayEnumerator* BitArrayEnumerator)
{
	UE_LOG(LogTemp, Log, TEXT("ChunkDataPacketAnalysis データ受信"));
	TArray<int> chunkData;
	int X = BitArrayEnumerator->MoveNextToInt();
	int Y = BitArrayEnumerator->MoveNextToInt();
	for (int i = 0; i < 20*20; ++i)
	{
		if(BitArrayEnumerator->MoveNextToBit())
		{
			if (BitArrayEnumerator->MoveNextToBit())
			{
				BitArrayEnumerator->MoveNextToBit();
				chunkData.Add(BitArrayEnumerator->MoveNextToInt());
			}else
			{
				if (BitArrayEnumerator->MoveNextToBit())
				{
					chunkData.Add(BitArrayEnumerator->MoveNextToShort());
				}else
				{
					chunkData.Add(BitArrayEnumerator->MoveNextToByte());
				}
			}
		}else
		{
			chunkData.Add(0);
		}
	}
	ChunkBlockManager->AddChunk(X,Y,chunkData);
}
