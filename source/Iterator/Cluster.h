#pragma once
#include <iostream>
#include "windows.h"
using namespace std;
enum class FEEnum { none, png, exe, pdf, jpeg };
class Cluster
{
private:
	unsigned int clusterNum = 0;
	BYTE* content = NULL;

public:
	void SetClusterNum(unsigned int num) {clusterNum = num;}
	void SetContent(BYTE* arr, unsigned int ClusterSize);
	BYTE* getContent() { return content; };
	unsigned int getNumber() const { return clusterNum; };
	FEEnum GetFileType();
	Cluster(BYTE* data, unsigned int num, unsigned int ClusterSize);
	Cluster() {};
	~Cluster();
};

