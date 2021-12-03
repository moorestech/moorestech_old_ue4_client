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
	
	UFUNCTION(BlueprintImplementableEvent,Category="moorestech")
	void SetInventoryEvent(const TArray<int>& itemId,const TArray<int>& itemCount);
	UFUNCTION(BlueprintImplementableEvent,Category="moorestech")
	void SetInventorySlotEvent(const int itemSlot, const int itemId, const int itemCount);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
