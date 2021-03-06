#pragma once

#include "CoreMinimal.h"
#include "TcpSocketConnection.h"
#include "PacketAnalysis/ChunkDataPacketAnalysis.h"
#include "PacketAnalysis/EventResponseAnalysis.h"
#include "PacketAnalysis/PlayerInventoryPacketAnalysis.h"
#include "PacketAnalysis/Base/PacketAnalysisBase.h"
#include "moorestechSocketConnection.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API AmoorestechSocketConnection : public ATcpSocketConnection
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category=".moorestech")
	void Receive(TArray<uint8> ReceiveBuffer);
	
private:
	TArray<PacketAnalysisBase*> PacketAnalysisBases;
	bool init = false;
	
	UPROPERTY(EditAnywhere, Category = "Settings")
	AChunkDataPacketAnalysis*    ChunkDataPacketAnalysis;
	UPROPERTY(EditAnywhere, Category = "Settings")
	AEventResponseAnalysis*    EventResponseAnalysis;
	UPROPERTY(EditAnywhere, Category = "Settings")
	APlayerInventoryPacketAnalysis* PlayerInventoryPacketAnalysis;
	
};
