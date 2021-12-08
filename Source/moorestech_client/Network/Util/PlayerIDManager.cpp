#include "PlayerIDManager.h"
#include <cstdlib>
#include <random>



void APlayerIDManager::BeginPlay()
{
	playerId = (int)(rand() % 999);
}

int APlayerIDManager::GetPlayerId()
{
    return playerId;
}

