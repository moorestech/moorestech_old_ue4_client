﻿// Fill out your copyright notice in the Description page of Project Settings.

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
	// Sets default values for this actor's properties
	ADefaultTestBlock();
	virtual int GetBlockId() override;
	virtual void DeleteBlock() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
