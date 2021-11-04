// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeTestActor.h"

#include <string>

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
	std::string text = "あ";

	char const *c = text.c_str();
	std::vector<char> bytes(myString.begin(), myString.end());
}

// Called every frame
void ACodeTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

