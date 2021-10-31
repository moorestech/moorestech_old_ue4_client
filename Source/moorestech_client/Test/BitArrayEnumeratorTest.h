// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "BitArrayEnumeratorTest.generated.h"

/**
 * 
 */
UCLASS()
class MOORESTECH_CLIENT_API ABitArrayEnumeratorTest : public AFunctionalTest
{
	GENERATED_BODY()

	public:
	bool RunTest(int seed);
	
};
