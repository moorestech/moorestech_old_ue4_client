// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TcpSocketConnection.h"
#include "AnalyzeReceivedPacket.generated.h"

/**
 * 
 */
UCLASS()
class MOORESTECH_CLIENT_API AAnalyzeReceivedPacket : public ATcpSocketConnection
{
	GENERATED_BODY()
	public:
	UFUNCTION()
	void OnMessageReceived(int32 ConId, TArray<uint8>& Message);
	
};
