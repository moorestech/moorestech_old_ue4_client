#include "BitArrayEnumerator.h"

constexpr int BIT_MASK[] = {128 ,64, 32,16,8,4,2,1};

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
	int8 result = 0;
	int bitNum = 8;
	
	for (int i = 0; i < bitNum; i++)
	{
        if (MoveNextToBit())
        {
            result = result | BIT_MASK[i%8];
        }
	}
	
	return result;
}
int16 BitArrayEnumerator::MoveNextToShort()
{
	int16 result;
	int byteNum = 2;
	unsigned char byteArray[2];
	for (int i = 0; i < byteNum; i++)
	{
		byteArray[i] = MoveNextToByte();
	}
	FMemory::Memcpy(&result, byteArray, byteNum);
	
	return result;
}
int32 BitArrayEnumerator::MoveNextToInt()
{
	int32 result;
	int byteNum = 4;
	unsigned char byteArray[4];
	for (int i = 0; i < byteNum; i++)
	{
		byteArray[i] = MoveNextToByte();
	}
	FMemory::Memcpy(&result, byteArray, byteNum);
	
	return result;
}
float BitArrayEnumerator::MoveNextToFloat()
{
	float result;
	int byteNum = 4;
	unsigned char byteArray[4];
	for (int i = 0; i < byteNum; i++)
	{
		byteArray[i] = MoveNextToByte();
	}
	FMemory::Memcpy(&result, byteArray, byteNum);
	
	return result;
}