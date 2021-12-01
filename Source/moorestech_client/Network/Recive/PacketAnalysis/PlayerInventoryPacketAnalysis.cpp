#include "PlayerInventoryPacketAnalysis.h"

APlayerInventoryPacketAnalysis::APlayerInventoryPacketAnalysis()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerInventoryPacketAnalysis::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerInventoryPacketAnalysis::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

