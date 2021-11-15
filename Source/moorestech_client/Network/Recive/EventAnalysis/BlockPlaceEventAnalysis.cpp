// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockPlaceEventAnalysis.h"

void ABlockPlaceEventAnalysis::Analysis(BitArrayEnumerator* BitArrayEnumerator)
{
	int x = BitArrayEnumerator->MoveNextToInt();
	int y = BitArrayEnumerator->MoveNextToInt();
	int id = BitArrayEnumerator->MoveNextToInt();

	ChunkBlockManager->SetBlock(x,y,id);
}
