// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/moorestechBlockBase.h"
#include "AirBlock.generated.h"

/**
 * 
 */
UCLASS()
class MOORESTECH_CLIENT_API AAirBlock : public AMoorestechBlockBase
{
	GENERATED_BODY()
public:
	virtual int GetBlockId() override; 
	
};
