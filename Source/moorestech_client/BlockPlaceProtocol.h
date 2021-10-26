// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlockPlaceProtocol.generated.h"

/**
 * 
 */
UCLASS()
class MOORESTECH_CLIENT_API UBlockPlaceProtocol : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	  UFUNCTION(BlueprintCallable, Category = "moorestech Protocol")
	  static void BlockPlace(int blockPositionX,int blockPositionY,int blockID);
	
};
