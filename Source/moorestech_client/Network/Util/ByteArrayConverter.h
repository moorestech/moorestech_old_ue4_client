#pragma once

class ByteArrayConverter
{
public:
	static TArray<uint8> ToByteArray(int sendData);
	static TArray<uint8> ToByteArray(int16 sendData);
	static TArray<uint8> ToByteArray(float sendData);
	static TArray<uint8> ToByteArray(FString& sendData);
};
