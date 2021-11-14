// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodeTestActor.generated.h"

UCLASS()
class MOORESTECH_CLIENT_API ACodeTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACodeTestActor();
	
	UPROPERTY(EditAnywhere, Category = "Settings")
	UClass* Block;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
