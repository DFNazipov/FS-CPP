#include "NTFS.h"
#include "Iterator.h"
#include <iostream>
#include "windows.h"
#include "stdio.h"
using namespace std;

bool NTFS::ReadClusterSize()
{
    BYTE sector[512];
    DWORD bytesRead;
    DWORD bytesToRead = sizeof(sector);

    LARGE_INTEGER sectorSizeOffset{};
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
    unsigned int sectorsPerCluster = static_cast<unsigned int>(pBootRecord->sectorsPerCluster);
    unsigned int sectorSize = static_cast<unsigned int>(pBootRecord->bytesPerSector);
    unsigned int countSectors = static_cast<unsigned int>(pBootRecord->countSectors);
    clusterSize = sectorSize * sectorsPerCluster;
    clusterCount = countSectors / sectorsPerCluster;
    return true;
}

