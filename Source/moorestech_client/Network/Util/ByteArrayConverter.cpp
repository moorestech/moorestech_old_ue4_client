#include "ByteArrayConverter.h"
#include "ReserveUint8Array.h"

#include <string>

#include "endian.h"

TArray<uint8> ByteArrayConverter::ToByteArray(int sendData)
{
	TArray<uint8> result;
	for (int i = 0; i < 4; i++)
	{
		result.Add(sendData >> i * 8);
	}
	if(endian::IS_LITTLE_ENDIAN())
	{
		result = ReserveUint8Array::ReserveTArray(result);
	}
	return result;
}
TArray<uint8> ByteArrayConverter::ToByteArray(int16 sendData)
{
	TArray<uint8> result;
	for (int i = 0; i < 2; i++)
	{
		result.Add(sendData >> i * 8);
	}
	if(endian::IS_LITTLE_ENDIAN())
	{
		result = ReserveUint8Array::ReserveTArray(result);
	}
	return result;
}
TArray<uint8> ByteArrayConverter::ToByteArray(float sendData)
{
	TArray<uint8> result;
	unsigned char const * p = reinterpret_cast<unsigned char const *>(&sendData);
	for (int i = 0; i != sizeof(float); i++)
	{
		result.Add((uint8)p[i]);
	}
	if(endian::IS_LITTLE_ENDIAN())
	{
		result = ReserveUint8Array::ReserveTArray(result);
	}
	return result;
}
TArray<uint8> ByteArrayConverter::ToByteArray(FString& sendData)
{
	FTCHARToUTF8 Convert(*sendData);
	int BytesLength = Convert.Length(); //length of the utf-8 string in bytes (when non-latin letters are used, it's longer than just the number of characters)
	uint8* messageBytes = static_cast<uint8*>(FMemory::Malloc(BytesLength));
	FMemory::Memcpy(messageBytes, (uint8*)TCHAR_TO_UTF8(sendData.GetCharArray().GetData()), BytesLength); //mcmpy is required, since TCHAR_TO_UTF8 returns an object with a very short lifetime

	TArray<uint8> result;
	for (int i = 0; i < BytesLength; i++)
	{
		result.Add(messageBytes[i]);
	}

	FMemory::Free(messageBytes);	

	return result;
}