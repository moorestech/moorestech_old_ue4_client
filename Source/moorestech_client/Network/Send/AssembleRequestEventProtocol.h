// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssembleRequestEventProtocol.generated.h"

/**
 * 
 */
UCLASS()
class MOORESTECH_CLIENT_API UAssembleRequestEventProtocol : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "moorestech Protocol")
	static TArray<uint8> AssembleRequestEvent(int playerId);
};
