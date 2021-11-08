// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeTestActor.h"

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
	FString ab = "adv-";
	auto a = ByteArrayConverter::ToByteArray(ab);
	for (int i = 0;i < a.Num();i++)
	{
		UE_LOG(LogTemp, Log, TEXT("MyIntValue = %d"), a[i]);
	}
}

// Called every frame
void ACodeTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

