#pragma once
#include "Iterator.h"
#include "Cluster.h"
template<class Type>
class Decorator :
    public Iterator<Type>
{
protected:
    Iterator<Type>* It;
public:
	Decorator(Iterator<Type> *it){
        It = it;
    }
	virtual void first() { It->first(); }
	virtual void next() { It->next(); }
	virtual bool isDone() const { return It->isDone(); }
	virtual Type getCurrent() { return It->getCurrent(); }
    ~Decorator() { delete It; }
};

