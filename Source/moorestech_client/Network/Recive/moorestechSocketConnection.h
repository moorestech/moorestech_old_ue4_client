// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TcpSocketConnection.h"
#include "CallPacketAnalysis.h"
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
	UPROPERTY(EditAnywhere, Category = "Settings")
	ACallPacketAnalysis*    packetAnalysis;
	
};
