// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlockPositionToChunkPosition.generated.h"

/**
 * 
 */
UCLASS()
class MOORESTECH_CLIENT_API UBlockPositionToChunkPosition : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "moorestech util")
	static FVector BlockPositionToChunkPosition(int blockPositionX,int blockPositionY);
	
};
