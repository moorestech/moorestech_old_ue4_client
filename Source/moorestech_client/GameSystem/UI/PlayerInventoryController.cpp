// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInventoryController.h"


// Sets default values
APlayerInventoryController::APlayerInventoryController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerInventoryController::SetInventory(TArray<int>& itemId, TArray<int>& itemAmount)
{
	SetInventoryEvent(itemId,itemAmount);
}

void APlayerInventoryController::SetInventory(int itemSlot, int itemId, int itemAmount)
{
	SetInventorySlotEvent(itemSlot, itemId, itemAmount);
}

// Called when the game starts or when spawned
void APlayerInventoryController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerInventoryController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

