#include "Cluster.h"
#include <iostream>
using namespace std;
Cluster::~Cluster()
{
    delete[] content;
}
FEEnum Cluster::GetFileType()
{
	if (content[0] == 0x4D && content[1] == 0x5A) {
		return  FEEnum::exe;
	}
   else if (content[0] == 0x89 && content[1] == 0x50 && content[2] == 0x4E && content[3] == 0x47 && content[4] == 0x0D && content[5] == 0x0A && content[6] == 0x1A && content[6] == 0x0A) {
		return  FEEnum::png;
	}
	else if (content[0] == 0x25 && content[1] == 0x50 && content[2] == 0x44 && content[3] == 0x46) {
		return  FEEnum::pdf;
	}
	else if (content[0] == 0xFF && content[1] == 0xD8 && content[2] == 0xFF && content[3] == 0xE0) {
		return  FEEnum::jpeg;
    }
    return FEEnum::none;
}
Cluster::Cluster(BYTE* data, unsigned int num, unsigned int ClusterSize)
{
    content = new BYTE[ClusterSize];
    std::memcpy(content, data, sizeof(BYTE) * ClusterSize);
    clusterNum = num;
}
void Cluster::SetContent(BYTE* data,unsigned int ClusterSize)
{
    content = new BYTE[ClusterSize];
    std::memcpy(content, data, sizeof(BYTE) * ClusterSize);
}
