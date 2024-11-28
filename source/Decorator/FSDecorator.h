#pragma once
#include "Decorator.h"
#include "Cluster.h"
#include <iostream>
class FSDecorator:public Decorator<Cluster>
{
private:
	FEEnum ItFile;
public:
	FSDecorator(Iterator<Cluster>*it, FEEnum itFile): Decorator(it){
		ItFile = itFile;
	}
	void first();
	void next();
};

