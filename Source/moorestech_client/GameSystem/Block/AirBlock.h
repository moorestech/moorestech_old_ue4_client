#pragma once
#include "moorestechBlockBase.h"

class AirBlock : public moorestechBlockBase
{
public:
	virtual int GetBlockId() override;
	virtual void DeleteBlock() override;
};
