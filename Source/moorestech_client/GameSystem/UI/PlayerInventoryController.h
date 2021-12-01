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
	void SetInventory(TArray<int>& itemId,TArray<int>& itemAmount);
	void SetInventory(int itemSlot, int itemId, int itemAmount);
	
	UFUNCTION(BlueprintImplementableEvent,Category="moorestech")
	void SetInventoryEvent(const TArray<int>& itemId,const TArray<int>& itemAmount);
	UFUNCTION(BlueprintImplementableEvent,Category="moorestech")
	void SetInventorySlotEvent(const int itemSlot, const int itemId, const int itemAmount);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
