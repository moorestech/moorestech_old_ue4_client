// Fill out your copyright notice in the Description page of Project Settings.


#include "AssemblePlayerPositionProtocol.h"

#include "moorestech_client/Network/Util/TArrayAddRange.h"

TArray<uint8> UAssemblePlayerPositionProtocol::AssemblePlayerPosition(int x, int y,int playerId)
{
	TArray<uint8> assembleData;
	TArrayAddRange::AddRange(assembleData,(int16)1);
	TArrayAddRange::AddRange(assembleData,x);
	TArrayAddRange::AddRange(assembleData,y);
	TArrayAddRange::AddRange(assembleData,playerId);
    
	return assembleData;
}
