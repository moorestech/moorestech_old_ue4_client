// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "moorestech_client/GameSystem/Blocks/Base/moorestechBlockBase.h"
#include "ChunkBlockManager.generated.h"

#define CHUNK_SIZE  20;


struct ChunkData;
UCLASS()
class MOORESTECH_CLIENT_API AChunkBlockManager : public AActor
{
	GENERATED_BODY()
	
public:	
	void SetChunk(int chunkX,int chunky,TArray<int>& chunkData);
	void SetBlock(int blockX,int blockY,int blockId);

	UFUNCTION(BlueprintImplementableEvent,Category=".moorestech")
	void SetChunkEvent(const int chunkX,const int chunkY,const TArray<int>& chunkData);
	UFUNCTION(BlueprintImplementableEvent,Category=".moorestech")
	void SetBlockEvent(const int chunkX,const int chunkY,const int chunkDataIndex,const int blockId);
    
};
