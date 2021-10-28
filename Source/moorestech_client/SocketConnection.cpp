// Fill out your copyright notice in the Description page of Project Settings.


#include "SocketConnection.h"

#include "Common/TcpSocketBuilder.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"

// Sets default values
ASocketConnection::ASocketConnection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASocketConnection::BeginPlay()
{
	UE_LOG(LogTemp, Display, TEXT("接続開始"));
	FIPv4Address IPAddress;
	FIPv4Address::Parse(FString("127.0.0.1"),IPAddress);
	FIPv4Endpoint Endpoint(IPAddress,(uint16)11564);

	ListenSocket =FTcpSocketBuilder(TEXT("TcpSocket")).AsReusable();
	
	ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
	ListenSocket -> Bind(*SocketSubsystem->CreateInternetAddr(Endpoint.Address.Value,Endpoint.Port));
	ListenSocket -> Listen(8);
	
	
}

// Called every frame
void ASocketConnection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

