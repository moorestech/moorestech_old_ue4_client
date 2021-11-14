﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "moorestech_client/GameSystem/Blocks/Base/moorestechBlockBase.h"
#include "GenerateBlockActor.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API AGenerateBlockActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGenerateBlockActor();
	AMoorestechBlockBase* GenerateBlock(int32 X,int32 Y,int32 BlockId);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	
	UPROPERTY(EditAnywhere, Category = "Settings")
	TArray<UClass*> BlockList; 
};
