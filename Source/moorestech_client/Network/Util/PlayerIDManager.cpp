#include "PlayerIDManager.h"
#include <cstdlib>
#include <random>



void APlayerIDManager::BeginPlay()
{
	playerId = (int)(rand() % 2147483647);
}

int APlayerIDManager::GetPlayerId()
{
    return playerId;
}

