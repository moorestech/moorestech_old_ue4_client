#pragma once
#include "moorestechBlockBase.h"

class AirBlock : public AMoorestechBlockBase
{
public:
	virtual int GetBlockId() override;
	virtual void DeleteBlock() override;
};
