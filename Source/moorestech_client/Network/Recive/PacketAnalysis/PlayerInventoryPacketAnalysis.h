#pragma once

#include "CoreMinimal.h"
#include "Base/PacketAnalysisBase.h"
#include "GameFramework/Actor.h"
#include "moorestech_client/GameSystem/UI/PlayerInventoryController.h"
#include "PlayerInventoryPacketAnalysis.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API APlayerInventoryPacketAnalysis : public AActor,public PacketAnalysisBase
{
	GENERATED_BODY()

public:
	APlayerInventoryPacketAnalysis();
	virtual void Analysis(BitArrayEnumerator* BitArrayEnumerator) override;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = "Settings")
	APlayerInventoryController* PlayerInventoryController;
	
	virtual void Tick(float DeltaTime) override;
};
