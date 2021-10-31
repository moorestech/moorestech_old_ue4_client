#include "BitArrayEnumerator.h"

constexpr int BIT_MASK[] = {0, 1, 2, 3};

BitArrayEnumerator::BitArrayEnumerator(TArray<uint8> ReceiveBuffer)
{
	this->ReceiveBuffer = ReceiveBuffer;
	this->index = 0;
}

bool BitArrayEnumerator::MoveNextToBit()
{
	const int r = ReceiveBuffer[index/8] & BIT_MASK[index%8];
	index++;
	if(r == 0)
	{
		return false;
	}else
	{
		return true;
	}
}

int8 BitArrayEnumerator::MoveNextToByte()
{
	return ReceiveBuffer[index++];
}
int16 BitArrayEnumerator::MoveNextToShort()
{
	int16 result;
	unsigned char byteArray[2];

	for (int i = 0; i < 2; i++,index++)
	{
		byteArray[index + i] = ReceiveBuffer[index + i];
	}

	FMemory::Memcpy(&result, byteArray, 2);
	
	return result;
}
int32 BitArrayEnumerator::MoveNextToInt()
{
	int result;
	unsigned char byteArray[4];

	for (int i = 0; i < 4; i++,index++)
	{
		byteArray[index + i] = ReceiveBuffer[index + i];
	}

	FMemory::Memcpy(&result, byteArray, 4);
	
	return result;
}
float BitArrayEnumerator::MoveNextToFloat()
{
	float result;
	unsigned char byteArray[4];

	for (int i = 0; i < 4; i++,index++)
	{
		byteArray[index + i] = ReceiveBuffer[index + i];
	}

	FMemory::Memcpy(&result, byteArray, 4);
	
	return result;
}