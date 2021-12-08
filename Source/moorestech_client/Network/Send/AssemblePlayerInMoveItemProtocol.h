// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssemblePlayerInMoveItemProtocol.generated.h"

/**
 * 
 */
UCLASS()
class MOORESTECH_CLIENT_API UAssemblePlayerInMoveItemProtocol : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "moorestech Protocol")
	static TArray<uint8> AssemblePlayerInMoveItem(int playerId,int fromSlot,int toSlot, int itemCount);
};
