#pragma once
#include "BaseFS.h"
#include "Iterator.h"
class exFAT :
	public BaseFS
{
private:
	#pragma pack(push, 1)
	typedef struct {
		char jumpInstruction[72];
		uint64_t countSectors;
	} BootRecord;
	#pragma pack(pop)
protected:
	bool ReadClusterSize();
};

