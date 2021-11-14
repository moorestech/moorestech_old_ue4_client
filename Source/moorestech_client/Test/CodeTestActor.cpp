// Fill out your copyright notice in the Description page of Project Settings.

#include "CodeTestActor.h"
#include "moorestech_client/Network/Util/BitArrayEnumerator.h"

#include <string>

#include "moorestech_client/GameSystem/Blocks/Base/moorestechBlockBase.h"
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
	int X = 1;
	int Y = 1;
	FVector pos = {(float)(X * 100), (float)(Y * 100), 0};
	
	FRotator rot = {0,0,0};
	AMoorestechBlockBase* block = GetWorld()->SpawnActor<AMoorestechBlockBase>(Block,pos, rot);
	

}

// Called every frame
void ACodeTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

