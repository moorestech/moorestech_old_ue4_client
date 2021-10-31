#include "ByteArrayConverter.h"

static TArray<uint8> ToByteArray(int sendData)
{
	TArray<uint8> result;
	for (int i = 0; i < 4; i++)
	{
		result.Add(sendData >> i * 8);
	}
	return result;
}
static TArray<uint8> ToByteArray(int16 sendData)
{
	TArray<uint8> result;
	for (int i = 0; i < 2; i++)
	{
		result.Add(sendData >> i * 8);
	}
	return result;
}
static TArray<uint8> ToByteArray(float sendData)
{
	TArray<uint8> result;
	unsigned char const * p = reinterpret_cast<unsigned char const *>(&sendData);
	for (int i = 0; i != sizeof(float); i++)
	{
		result.Add((uint8)p[i]);
	}
	return result;
}
static TArray<uint8> ToByteArray(FString sendData)
{
	FTCHARToUTF8 Convert(*sendData);
	int BytesLength = Convert.Length(); 
	uint8* messageBytes = static_cast<uint8*>(FMemory::Malloc(BytesLength));
	FMemory::Memcpy(messageBytes, (uint8*)TCHAR_TO_UTF8(sendData.GetCharArray().GetData()), BytesLength); 

	TArray<uint8> result;
	for (int i = 0; i < BytesLength; i++)
	{
		result.Add(messageBytes[i]);
	}

	FMemory::Free(messageBytes);	

	return result;
}