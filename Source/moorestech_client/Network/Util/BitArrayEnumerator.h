#pragma once

class BitArrayEnumerator
{
public:
	BitArrayEnumerator(TArray<uint8> ReceiveBuffer);
	bool MoveNextToBit();
	int8 MoveNextToByte();
	int16 MoveNextToShort();
	float MoveNextToFloat();
	int32 MoveNextToInt();
	

private:
	int index;
	TArray<uint8> ReceiveBuffer;
};
