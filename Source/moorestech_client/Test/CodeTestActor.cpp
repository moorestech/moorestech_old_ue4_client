// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeTestActor.h"

#include "moorestech_client/Network/Util/ByteArrayConverter.h"

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
	
	TArray<uint8> actual;
	actual = ByteArrayConverter::ToByteArray("a");
	UE_LOG(LogTemp, Log, TEXT("a"));
	for (int i = 0;i<actual.Num();i++)
	{
		UE_LOG(LogTemp, Log, TEXT("Value=%d"), actual[i]);
	}
	
	actual = ByteArrayConverter::ToByteArray("a");
	UE_LOG(LogTemp, Log, TEXT("ab"));
	for (int i = 0;i<actual.Num();i++)
	{
		UE_LOG(LogTemp, Log, TEXT("Value=%d"), actual[i]);
	}
	
	actual = ByteArrayConverter::ToByteArray("あ");
	UE_LOG(LogTemp, Log, TEXT("あ"));
	for (int i = 0;i<actual.Num();i++)
	{
		UE_LOG(LogTemp, Log, TEXT("Value=%d"), actual[i]);
	}
	
}

// Called every frame
void ACodeTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

