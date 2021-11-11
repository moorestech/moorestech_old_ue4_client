// Fill out your copyright notice in the Description page of Project Settings.


#include "moorestechSocketConnection.h"

void AmoorestechSocketConnection::Receive(TArray<uint8> ReceiveBuffer)
{
	
	packetAnalysis->Analysis(ReceiveBuffer);
}


