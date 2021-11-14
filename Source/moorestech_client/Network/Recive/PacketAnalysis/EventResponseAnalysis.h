// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PacketAnalysisBase.h"
#include "GameFramework/Actor.h"
#include "moorestech_client/Network/Recive/EventAnalysis/Base/EventPacketAnalysisBase.h"
#include "EventResponseAnalysis.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API AEventResponseAnalysis : public AActor,public PacketAnalysisBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEventResponseAnalysis();
	virtual void Analysis(BitArrayEnumerator* BitArrayEnumerator) override;
	
	UPROPERTY(EditAnywhere, Category = "Settings")
	TArray<AEventPacketAnalysisBase*> EventPacketAnalysisBases;
};
