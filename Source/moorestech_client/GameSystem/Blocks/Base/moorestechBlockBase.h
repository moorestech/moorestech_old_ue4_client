#pragma once

#include "MoorestechBlockBase.generated.h"

UCLASS()
class AMoorestechBlockBase : public AActor
{
	GENERATED_BODY()
public:
	virtual ~AMoorestechBlockBase() = default;
	
	UFUNCTION(BlueprintPure,Category=".moorestech")
	virtual int GetBlockId();
	
};
