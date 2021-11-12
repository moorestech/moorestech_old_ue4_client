// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "moorestech_client/Util/Coordinate.h"
#include "ChunkBlockManager.generated.h"

struct ChunkData;
UCLASS()
class MOORESTECH_CLIENT_API AChunkBlockManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunkBlockManager();
	void AddChunk(int x,int y,TArray<int> chunkData);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	TMap<Coordinate,ChunkData> ChunkDataMap;
};


struct ChunkData
{
	TArray<int> chunkIdData;
	TArray<AActor> chunkActor;
};
