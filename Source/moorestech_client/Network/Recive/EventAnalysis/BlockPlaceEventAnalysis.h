// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/EventPacketAnalysisBase.h"
#include "GameFramework/Actor.h"
#include "moorestech_client/GameSystem/World/ChunkBlockManager.h"
#include "BlockPlaceEventAnalysis.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API ABlockPlaceEventAnalysis : public AEventPacketAnalysisBase
{
	GENERATED_BODY()

public:
	virtual void Analysis(BitArrayEnumerator* BitArrayEnumerator) override;
private:
	UPROPERTY(EditAnywhere, Category = "Settings")
	AChunkBlockManager* ChunkBlockManager;
};
