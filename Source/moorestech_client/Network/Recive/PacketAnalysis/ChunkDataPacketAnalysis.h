// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Base/PacketAnalysisBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "moorestech_client/GameSystem/World/ChunkBlockManager.h"
#include "ChunkDataPacketAnalysis.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API AChunkDataPacketAnalysis : public AActor,public PacketAnalysisBase
{
	GENERATED_BODY()
	
public:	
	AChunkDataPacketAnalysis();
	virtual void Analysis(BitArrayEnumerator* BitArrayEnumerator) override;

private:
	UPROPERTY(EditAnywhere, Category = "Settings")
	AChunkBlockManager* ChunkBlockManager;
};
