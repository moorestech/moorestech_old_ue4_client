// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/moorestechBlockBase.h"
#include "GameFramework/Actor.h"
#include "DefaultTestBlock.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API ADefaultTestBlock : public AMoorestechBlockBase
{
	GENERATED_BODY()

public:
	virtual int GetBlockId() override;
};
