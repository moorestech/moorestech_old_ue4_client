#pragma once

class moorestechBlockBase
{
public:
	virtual ~moorestechBlockBase() = default;
	virtual int GetBlockId();
	virtual void DeleteBlock();
	
};
