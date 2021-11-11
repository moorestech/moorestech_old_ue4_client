// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TcpSocketConnection.h"
#include "PacketAnalysis/ChunkDataPacketAnalysis.h"
#include "moorestechSocketConnection.generated.h"

/**
 * 
 */
UCLASS()
class MOORESTECH_CLIENT_API AmoorestechSocketConnection : public ATcpSocketConnection
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="MyF")
	void Receive(TArray<uint8> ReceiveBuffer);
	
private:
	TArray<PacketAnalysisBase*> PacketAnalysisBases;
	bool init = false;
	
	UPROPERTY(EditAnywhere, Category = "Settings")
	AChunkDataPacketAnalysis*    ChunkDataPacketAnalysis;
	
};
