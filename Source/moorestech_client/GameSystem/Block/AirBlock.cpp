// Fill out your copyright notice in the Description page of Project Settings.


#include "AirBlock.h"
#include "moorestech_client/GameSystem/moorestechBlockBase.h"

int AAirBlock::GetBlockId()
{
	return 0;
}

void AAirBlock::DeleteBlock()
{
	//BP側でアクタの破壊を行う
	DeleteBlockEvent();
}
