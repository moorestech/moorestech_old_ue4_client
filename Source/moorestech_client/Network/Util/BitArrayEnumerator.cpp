#include "BitArrayEnumerator.h"

#include "endian.h"

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

uint8 BitArrayEnumerator::MoveNextToByte()
{
	uint8 result = 0;
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
	if (endian::IS_LITTLE_ENDIAN())
	{
		const unsigned char w = byteArray[0];
		byteArray[0] = byteArray[1];
		byteArray[1] = w;
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
	if (endian::IS_LITTLE_ENDIAN())
	{
		for (int i = 0;i < byteNum / 2;i++)
		{
			int j = 4 - 1 - i;
			int w = byteArray[i];
			byteArray[i] = byteArray[j];
			byteArray[j] = w;
		}
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
	if (endian::IS_LITTLE_ENDIAN())
	{
		for (int i = 0;i < byteNum / 2;i++)
		{
			int j = 4 - 1 - i;
			int w = byteArray[i];
			byteArray[i] = byteArray[j];
			byteArray[j] = w;
		}
	}
	FMemory::Memcpy(&result, byteArray, byteNum);
	
	return result;
}