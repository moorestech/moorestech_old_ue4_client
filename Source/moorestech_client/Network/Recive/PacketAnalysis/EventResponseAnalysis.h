#pragma once

#include "CoreMinimal.h"
#include "Base/PacketAnalysisBase.h"
#include "GameFramework/Actor.h"
#include "moorestech_client/Network/Recive/EventAnalysis/Base/EventPacketAnalysisBase.h"
#include "EventResponseAnalysis.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API AEventResponseAnalysis : public AActor,public PacketAnalysisBase
{
	GENERATED_BODY()

public:
	AEventResponseAnalysis();
	virtual void Analysis(BitArrayEnumerator* BitArrayEnumerator) override;
	
	UPROPERTY(EditAnywhere, Category = "Settings")
	TArray<AEventPacketAnalysisBase*> EventPacketAnalysisBases;
};
