// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultTestBlock.h"
#include "Base/moorestechBlockBase.h"


// Sets default values
ADefaultTestBlock::ADefaultTestBlock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

int ADefaultTestBlock::GetBlockId()
{
	return 1;
}

void ADefaultTestBlock::DeleteBlock()
{
	AMoorestechBlockBase::DeleteBlock();
}

// Called when the game starts or when spawned
void ADefaultTestBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADefaultTestBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

