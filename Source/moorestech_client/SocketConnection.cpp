// Fill out your copyright notice in the Description page of Project Settings.


#include "SocketConnection.h"

#include "Sockets.h"
#include "SocketSubsystem.h"
// Sets default values
ASocketConnection::ASocketConnection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASocketConnection::BeginPlay()
{
	
	
}

// Called every frame
void ASocketConnection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASocketConnection::ConnectToServer(const FString& InIP, const int32 InPort)
{

	// формируем адрес подключения
	RemoteAdress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	UE_LOG(LogTemp, Error, TEXT("TCP address try to connect <%s:%d>"), *InIP, InPort);

	bool bIsValid;
	RemoteAdress->SetIp(*InIP, bIsValid);
	RemoteAdress->SetPort(InPort);

	// чекаем валидность адреса подключения
	if (!bIsValid)
	{
		UE_LOG(LogTemp, Error, TEXT("TCP address is invalid <%s:%d>"), *InIP, InPort);
		return;
	}

	// Получаем подсистему сокетов
	ClientSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, ClientSocketName, false);

	// Устанавливаем размер буфера отправки/приема
	ClientSocket->SetSendBufferSize(BufferMaxSize, BufferMaxSize);
	ClientSocket->SetReceiveBufferSize(BufferMaxSize, BufferMaxSize);

	// конектимся
	bIsConnected = ClientSocket->Connect(*RemoteAdress);

	// если подключились бродкастим эвент
	if (bIsConnected)
	{
		OnConnected.Broadcast();
	}

	// говорим что готовы получать данные
	bShouldReceiveData = true;

	// Слушатель данных
	ClientConnectionFinishedFuture = Async(EAsyncExecution::Thread, [&]()
		{
			uint32 BufferSize = 0;
			TArray<uint8> ReceiveBuffer;
			FString ResultString;

			// запускаем бесконечный цикл получения данных
			while (bShouldReceiveData)
			{
				// если есть данные
				if (ClientSocket->HasPendingData(BufferSize))
				{
					// устанавливаем размер буфера
					ReceiveBuffer.SetNumUninitialized(BufferSize);

					int32 Read = 0;
					ClientSocket->Recv(ReceiveBuffer.GetData(), ReceiveBuffer.Num(), Read);

					// отправляем буфер в эвент
					OnReceivedBytes.Broadcast(ReceiveBuffer);

				}
				// пропускаем 1 тик
				ClientSocket->Wait(ESocketWaitConditions::WaitForReadOrWrite, FTimespan(1));
			}
		}
	);
}

