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
	UE_LOG(LogTemp, Display, TEXT("サーバーへ接続開始"));
	this->ConnectToServer(TEXT("127.0.0.1"), 11564);
}

// Called every frame
void ASocketConnection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASocketConnection::ConnectToServer(const FString& InIP, const int32 InPort)
{

	// 接続アドレスを形成します
	RemoteAdress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	UE_LOG(LogTemp, Error, TEXT("TCP address try to connect <%s:%d>"), *InIP, InPort);

	bool bIsValid;
	RemoteAdress->SetIp(*InIP, bIsValid);
	RemoteAdress->SetPort(InPort);

	// 接続アドレスの有効性を確認してください
	if (!bIsValid)
	{
		UE_LOG(LogTemp, Error, TEXT("TCP address is invalid <%s:%d>"), *InIP, InPort);
		return;
	}

	// ソケットサブシステムの取得
	ClientSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, ClientSocketName, false);

	// 送信/受信バッファのサイズを設定します
	ClientSocket->SetSendBufferSize(BufferMaxSize, BufferMaxSize);
	ClientSocket->SetReceiveBufferSize(BufferMaxSize, BufferMaxSize);

	// フックアップ
	bIsConnected = ClientSocket->Connect(*RemoteAdress);

	// データを受信する準備ができていると言います
	bShouldReceiveData = true;

	// データリスナー
	ClientConnectionFinishedFuture = Async(EAsyncExecution::Thread, [&]()
		{
			uint32 BufferSize = 4096;
			TArray<uint8> ReceiveBuffer;
			FString ResultString;

			// データを受信するための無限ループを開始する
			while (bShouldReceiveData)
			{
				//データがある場合
				if (ClientSocket->HasPendingData(BufferSize))
				{
					// バッファサイズを設定する
					ReceiveBuffer.SetNumUninitialized(BufferSize);

					int32 Read = 0;
					ClientSocket->Recv(ReceiveBuffer.GetData(), ReceiveBuffer.Num(), Read);

				}
				// 1ティックスキップ
				ClientSocket->Wait(ESocketWaitConditions::WaitForReadOrWrite, FTimespan(1));
			}
		}
	);
}

bool ASocketConnection::Emit(const TArray<uint8>& Bytes)
{
	bool resp = false;

	//接続があるかどうかを確認します
	if (ClientSocket && ClientSocket->GetConnectionState() == SCS_Connected)
	{
		int32 BytesSent = 0; // 送信されたバイト数
		resp = ClientSocket->Send(Bytes.GetData(), Bytes.Num(), BytesSent);
	}
	return resp;
}

void ASocketConnection::CloseSocket()
{
	// ソケットがある場合
	if (ClientSocket)
	{
		// データの受信を停止します
		bShouldReceiveData = false;

		//接続を終了します
		ClientConnectionFinishedFuture.Get();
		ClientSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ClientSocket);
		ClientSocket = nullptr;
	}
}
