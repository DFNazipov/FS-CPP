#pragma once
template <class Type> class Iterator
{
protected:
	Iterator() {};
	Iterator(unsigned int) {};
public:
	virtual ~Iterator() {};
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() const = 0;
	virtual Type getCurrent() = 0;
};

