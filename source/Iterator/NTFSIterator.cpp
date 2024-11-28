#include "NTFSIterator.h"

Cluster NTFSIterator::getCurrent()
{
    Cluster item;
    if (!ntfs->ReadCluster(&item, Cursor)) {
        throw std::invalid_argument("Error: can not read cluster!");
    }
    return item;
}
