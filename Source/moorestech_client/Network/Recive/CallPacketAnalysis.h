// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PacketAnalysis/ChunkDataPacketAnalysis.h"
#include "PacketAnalysis/PacketAnalysisBase.h"
#include "CallPacketAnalysis.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API ACallPacketAnalysis : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACallPacketAnalysis();
	void Analysis(TArray<uint8> ReceiveBuffer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	TArray<PacketAnalysisBase*> PacketAnalysisBases;
	bool init = false;
	UPROPERTY(EditAnywhere, Category = "Settings")
	AChunkDataPacketAnalysis*    ChunkDataPacketAnalysis;
};
