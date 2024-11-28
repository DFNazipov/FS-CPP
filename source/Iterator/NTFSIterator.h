
#pragma once
#include "Iterator.h"
#include "BaseFS.h"
class NTFSIterator :
    public Iterator<Cluster>
{
private:
	BaseFS* ntfs;
    unsigned int Count;
    unsigned int Cursor;
public:
	NTFSIterator(BaseFS* fsItem) :Iterator(fsItem->getClusterCount()) {
        ntfs = fsItem;
		Count = ntfs->getClusterCount();
        Cursor = 0;
    }
	void first() { Cursor = 0; }
	void next() { Cursor ++; }
    bool isDone() const { return (Cursor >= Count); }
    Cluster getCurrent();
};

