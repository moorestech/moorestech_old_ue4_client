// Fill out your copyright notice in the Description page of Project Settings.


#include "AssemblePlayerInventoryProtocol.h"

#include "moorestech_client/Network/Util/TArrayAddRange.h"

constexpr short PACKET_ID = 3;

TArray<uint8> UAssemblePlayerInventoryProtocol::AssembleRequestPlayerInventory(int playerId)
{
	TArray<uint8> assembleData;
	TArrayAddRange::AddRange(assembleData,PACKET_ID);
	TArrayAddRange::AddRange(assembleData,playerId);
    
	return assembleData;
}
