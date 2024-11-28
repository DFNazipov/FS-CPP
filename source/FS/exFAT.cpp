#include "exFAT.h"
#include "Iterator.h"
#include <iostream>
#include "windows.h"
#include "stdio.h"
using namespace std;

bool exFAT::ReadClusterSize()
{
    BYTE sector[512];
    DWORD bytesRead;
    DWORD bytesToRead = sizeof(sector);

    LARGE_INTEGER sectorSizeOffset;
    sectorSizeOffset.QuadPart = 0;

    if (!SetFilePointerEx(fileHandler, sectorSizeOffset, NULL, FILE_BEGIN)) {
		throw std::invalid_argument("Failed to set file pointer");
		CloseHandle(fileHandler);
        return false;
    }
    if (!ReadFile(fileHandler, sector, bytesToRead, &bytesRead, NULL))
    {
        throw std::invalid_argument("Failed to read from file");
        CloseHandle(fileHandler);
        return false;
    }
   BootRecord* pBootRecord = reinterpret_cast<BootRecord*>(sector);
   unsigned int sectorSize = pow (2, sector[108]);
   unsigned int classCoeff = pow (2, sector[109]);
   clusterSize = sectorSize * classCoeff;
   unsigned int countSectors = static_cast<unsigned int>(pBootRecord->countSectors);
   clusterCount = countSectors / classCoeff;
   return true;
}
