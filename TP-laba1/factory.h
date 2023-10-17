#pragma once
#include "keeper.h"
class Factory
{
public:
	Factory();
	virtual ~Factory();
	virtual void ClearVirtual() = 0;
};