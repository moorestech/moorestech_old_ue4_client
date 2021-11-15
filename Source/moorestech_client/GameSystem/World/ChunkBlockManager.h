// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenerateBlockActor.h"
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
	void AddChunk(int x,int y,TArray<int>& chunkData);
	void AddBlock(int blockX,int blockY,int blockId);

protected:
	UPROPERTY(EditAnywhere, Category = "Settings")
	AGenerateBlockActor*  GenerateBlockActor;

private:
	TArray<ChunkData> chunks;
};
