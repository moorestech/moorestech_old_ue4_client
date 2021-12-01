#include "PlayerInventoryPacketAnalysis.h"

constexpr int PLAYER_INVENTORY_SIZE = 45;

APlayerInventoryPacketAnalysis::APlayerInventoryPacketAnalysis()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerInventoryPacketAnalysis::Analysis(BitArrayEnumerator* BitArrayEnumerator)
{
	BitArrayEnumerator->MoveNextToInt();//プレイヤーID
	BitArrayEnumerator->MoveNextToShort();//パディング
	TArray<int> ItemIds;
	TArray<int> ItemCounts;
	for (int i = 0; i < PLAYER_INVENTORY_SIZE; i++)
    {
        ItemIds.Add(BitArrayEnumerator->MoveNextToInt());
        ItemCounts.Add(BitArrayEnumerator->MoveNextToInt());
    }
	PlayerInventoryController->SetInventoryEvent(ItemIds, ItemCounts);
	
}

void APlayerInventoryPacketAnalysis::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerInventoryPacketAnalysis::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

