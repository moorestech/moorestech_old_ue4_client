// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerInventoryController.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API APlayerInventoryController : public AActor
{
	GENERATED_BODY()

public:
	APlayerInventoryController();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
