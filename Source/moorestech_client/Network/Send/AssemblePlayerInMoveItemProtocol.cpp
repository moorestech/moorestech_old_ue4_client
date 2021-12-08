// Fill out your copyright notice in the Description page of Project Settings.


#include "AssemblePlayerInMoveItemProtocol.h"

#include "moorestech_client/Network/Util/TArrayAddRange.h"

TArray<uint8> UAssemblePlayerInMoveItemProtocol::AssemblePlayerInMoveItem(int playerId, int fromSlot, int toSlot,int itemCount)
{
	TArray<uint8> assembleData;
	TArrayAddRange::AddRange(assembleData,(int16)6);
	TArrayAddRange::AddRange(assembleData,playerId);
	TArrayAddRange::AddRange(assembleData,fromSlot);
	TArrayAddRange::AddRange(assembleData,toSlot);
	TArrayAddRange::AddRange(assembleData,itemCount);
    
	return assembleData;
}
