// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "moorestech_client/Network/Util/BitArrayEnumerator.h"
#include "EventPacketAnalysisBase.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API AEventPacketAnalysisBase : public AActor
{
	GENERATED_BODY()
	
public:	
	virtual ~AEventPacketAnalysisBase() = default;
	virtual void Analysis(BitArrayEnumerator* BitArrayEnumerator);

};
