#pragma once

class BitArrayEnumerator
{
public:
	explicit BitArrayEnumerator(TArray<uint8> ReceiveBuffer);
	bool MoveNextToBit();
	uint8 MoveNextToByte();
	int16 MoveNextToShort();
	float MoveNextToFloat();
	int32 MoveNextToInt();
	

private:
	int index;
	TArray<uint8> ReceiveBuffer;
	
};
