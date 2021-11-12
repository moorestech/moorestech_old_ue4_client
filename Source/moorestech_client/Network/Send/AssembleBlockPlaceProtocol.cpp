// Fill out your copyright notice in the Description page of Project Settings.


#include "AssembleBlockPlaceProtocol.h"
#include "moorestech_client/Network/Util/ByteArrayConverter.h"
#include "moorestech_client/Network/Util/TArrayAddRange.h"

//TODO 機械のインプット、アウトプットに対応したプロトコルを作成する
TArray<uint8> UAssembleBlockPlaceProtocol::AssembleBlockPlace(int blockPositionX,int blockPositionY,int blockID)
{
    TArray<uint8> assembleData;
    TArrayAddRange::AddRange(assembleData,(int16)1);
    TArrayAddRange::AddRange(assembleData,blockID);
    TArrayAddRange::AddRange(assembleData,(int16)0);
    TArrayAddRange::AddRange(assembleData,blockPositionX);
    TArrayAddRange::AddRange(assembleData,blockPositionY);
    TArrayAddRange::AddRange(assembleData,0);
    TArrayAddRange::AddRange(assembleData,0);
    
    return assembleData;
}
