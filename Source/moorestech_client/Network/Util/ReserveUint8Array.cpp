#include "ReserveUint8Array.h"

TArray<uint8> ReserveUint8Array::ReserveTArray(TArray<uint8> tarray)
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
