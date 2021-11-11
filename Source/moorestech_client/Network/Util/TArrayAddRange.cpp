#include "TArrayAddRange.h"
#include "moorestech_client/Network/Util/ByteArrayConverter.h"

void TArrayAddRange::AddRange(TArray<uint8>& ByteArray, TArray<uint8>& Range)
{
    for (int32 i = 0; i < Range.Num(); i++)
    {
        ByteArray.Add(Range[i]);
    }
}
void TArrayAddRange::AddRange(TArray<uint8>& ByteArray, int data)
{
    TArray<uint8> send = ByteArrayConverter::ToByteArray(data);
    AddRange(ByteArray,send);
}
void TArrayAddRange::AddRange(TArray<uint8>& ByteArray, int16 data)
{
    TArray<uint8> send = ByteArrayConverter::ToByteArray(data);
    AddRange(ByteArray,send);
}
void TArrayAddRange::AddRange(TArray<uint8>& ByteArray, float data)
{
    TArray<uint8> send = ByteArrayConverter::ToByteArray(data);
    AddRange(ByteArray,send);
}
void TArrayAddRange::AddRange(TArray<uint8>& ByteArray, FString& data)
{
    TArray<uint8> send = ByteArrayConverter::ToByteArray(data);
    AddRange(ByteArray,send);
}