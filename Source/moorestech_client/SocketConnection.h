// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SocketConnection.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNetEventS);
UCLASS()
class MOORESTECH_CLIENT_API ASocketConnection : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASocketConnection();
	FString ClientSocketName;
	void CloseSocket();
	bool Emit(const TArray<uint8>& Bytes);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	int32 BufferMaxSize;
	bool bIsConnected;
	TSharedPtr<FInternetAddr> RemoteAdress;
	FSocket * ClientSocket;
	FThreadSafeBool bShouldReceiveData;
	TFuture<void> ClientConnectionFinishedFuture;
	void ConnectToServer(const FString& InIP = TEXT("127.0.0.1"), const int32 InPort = 3000);

};
