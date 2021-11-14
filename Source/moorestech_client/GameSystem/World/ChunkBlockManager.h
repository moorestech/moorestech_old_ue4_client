// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenerateBlockActor.h"
#include "GameFramework/Actor.h"
#include "moorestech_client/GameSystem/moorestechBlockBase.h"
#include "ChunkBlockManager.generated.h"

struct ChunkData;
UCLASS()
class MOORESTECH_CLIENT_API AChunkBlockManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunkBlockManager();
	void AddChunk(int x,int y,TArray<int>& chunkData);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Settings")
	AGenerateBlockActor*  GenerateBlockActor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	TArray<ChunkData> chunks;
};

struct ChunkData
{
	int X;
	int Y;
	TArray<int>& chunkIds;
	TArray<AMoorestechBlockBase*>& chunkBlockBases;
};
