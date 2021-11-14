// Fill out your copyright notice in the Description page of Project Settings.


#include "AssembleRequestEventProtocol.h"

#include "moorestech_client/Network/Util/TArrayAddRange.h"

TArray<uint8> UAssembleRequestEventProtocol::AssembleRequestEvent(int playerId)
{
	TArray<uint8> assembleData;
	TArrayAddRange::AddRange(assembleData,(int16)4);
	TArrayAddRange::AddRange(assembleData,playerId);
    
	return assembleData;
}
