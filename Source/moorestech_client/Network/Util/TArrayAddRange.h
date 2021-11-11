#pragma once

class TArrayAddRange
{
public:
	static void AddRange(TArray<uint8>& ByteArray, TArray<uint8>& Range);
	static void AddRange(TArray<uint8>& ByteArray, int data);
	static void AddRange(TArray<uint8>& ByteArray, int16 data);
	static void AddRange(TArray<uint8>& ByteArray, float data);
	static void AddRange(TArray<uint8>& ByteArray, FString& data);
};
