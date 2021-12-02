// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerIDManager.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API APlayerIDManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "moorestech")
	int GetPlayerId();

protected:
	virtual void BeginPlay() override;

private:
    int playerId;
    
};
