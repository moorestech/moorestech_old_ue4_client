﻿#include "ByteArrayConverter.h"

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
		result = ReserveTArray(result);
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
		result = ReserveTArray(result);
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
		result = ReserveTArray(result);
	}
	return result;
}
TArray<uint8> ByteArrayConverter::ToByteArray(FString sendData)
{
	std::string data = std::string(TCHAR_TO_UTF8(*sendData));
	auto messageChar = new char[data.length()];
	data.copy(messageChar,data.length()-1);
	
	TArray<uint8> result;
	for (int i = 0; i < data.length() ; i++)
	{
		result.Add((uint8)messageChar[i]);
	}
	delete[] messageChar;

	return result;
}

TArray<uint8> ByteArrayConverter::ReserveTArray(TArray<uint8> tarray)
{
	for (int i = 0;i < tarray.Num()  /2;i++)
	{
		int j = tarray.Num() - 1 - i;
		int w = tarray[i];
		tarray[i] = tarray[j];
		tarray[j] = w;
	}
	return tarray;
}