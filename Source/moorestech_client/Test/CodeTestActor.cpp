// Fill out your copyright notice in the Description page of Project Settings.

#include "CodeTestActor.h"
#include "moorestech_client/Network/Util/BitArrayEnumerator.h"

#include <string>

#include "moorestech_client/Network/Util/ByteArrayConverter.h"
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

// Sets default values
ACodeTestActor::ACodeTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodeTestActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Error, TEXT("AAAAA"));
	TArray<uint8> actual;
	actual.Add(5);
	actual.Add(130);
	actual.Add(179);
	actual.Add(94);
	actual.Add(0);
	actual.Add(0);
	actual.Add(32);
	actual.Add(94);
	actual.Add(13);
	actual.Add(72);
	actual.Add(9);
	actual.Add(56);
	actual.Add(106);
	actual.Add(64);
	actual.Add(185);
	actual.Add(64);

	BitArrayEnumerator* bits;
	bits = new BitArrayEnumerator(actual);
	
	TArray<bool> ans;
	ans.Add(bits->MoveNextToByte() == (uint8)5);
	ans.Add(bits->MoveNextToBit() == true);
	ans.Add(bits->MoveNextToBit() == false);
	ans.Add(bits->MoveNextToBit() == false);
	ans.Add(bits->MoveNextToShort() == (int16)5530);
	ans.Add(bits->MoveNextToByte() == (uint8)240);
	ans.Add(bits->MoveNextToBit() == false);
	ans.Add(bits->MoveNextToInt() == (int32)132576);
	ans.Add(bits->MoveNextToBit() == true);
	ans.Add(bits->MoveNextToBit() == true);
	ans.Add(bits->MoveNextToBit() == false);
	ans.Add(bits->MoveNextToBit() == true);
	ans.Add(bits->MoveNextToFloat() == (float)140513.6513);
	ans.Add(bits->MoveNextToBit() == false);
	ans.Add(bits->MoveNextToBit() == true);
	ans.Add(bits->MoveNextToShort() == (int16)741);

	for (int i = 0; i < ans.Num(); ++i)
	{
		if(!ans[i])
		{
            UE_LOG(LogTemp, Error, TEXT("Failed at %d"), i);
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("%d"), ans.Num());

}

// Called every frame
void ACodeTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

