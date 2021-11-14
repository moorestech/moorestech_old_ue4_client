// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerateBlockActor.h"
#include "moorestech_client/GameSystem/moorestechBlockBase.h"


// Sets default values
AGenerateBlockActor::AGenerateBlockActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

AMoorestechBlockBase* AGenerateBlockActor::GenerateBlock(int32 X, int32 Y, int32 BlockId)
{
	//*100する理由は仮想的な座標を実際のワールド座標に変換する必要があるから
	FVector pos = {(float)(X * 100), (float)(Y * 100), 0};
	FRotator rot = {0,0,0};

	
	if (BlockList.Num() <= BlockId)
	{
		//IDが境界外のときは0(air)をスポーンさせる
		UE_LOG(LogTemp, Error, TEXT("BlockId is range out of index=%d"), BlockId);
		AMoorestechBlockBase* block = GetWorld()->SpawnActor<AMoorestechBlockBase>(BlockList[0],pos, rot);
		return block;
	}
	AMoorestechBlockBase* block = GetWorld()->SpawnActor<AMoorestechBlockBase>(BlockList[BlockId],pos, rot);
	return block;
}

// Called when the game starts or when spawned
void AGenerateBlockActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGenerateBlockActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

