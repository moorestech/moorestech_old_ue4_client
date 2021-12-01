// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInventoryUpdateEvent.h"

void APlayerInventoryUpdateEvent::Analysis(BitArrayEnumerator* BitArrayEnumerator)
{
	int slot = BitArrayEnumerator->MoveNextToInt();
	int itemID = BitArrayEnumerator->MoveNextToInt();
	int itemCount = BitArrayEnumerator->MoveNextToInt();
	PlayerInventoryController->SetInventorySlotEvent(slot, itemID, itemCount);
}
