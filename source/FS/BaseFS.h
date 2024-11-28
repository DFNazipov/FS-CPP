
#include "Cluster.h"
#include "windows.h"
#pragma once
class BaseFS
{
protected:
	HANDLE fileHandler = NULL;
	unsigned int clusterSize;
	unsigned int clusterCount;
	virtual bool ReadClusterSize();
public:
	bool Init(LPCWSTR);
	bool ReadCluster(Cluster* asd, unsigned int);
	unsigned int getClusterSize() const { return clusterSize; };
	unsigned int getClusterCount() const { return clusterCount; };
	virtual ~BaseFS();
};