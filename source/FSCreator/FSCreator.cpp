
#include "FSCreator.h"
#include "NTFS.h"
#include "BaseFS.h"
#include "exFAT.h"

#include <stdexcept>

BaseFS* MyFSCreator::CreateFS(FSEnum fsType, LPCWSTR device)
{
	switch (fsType) {
	case FSEnum::NTFS: {
		NTFS* fs = new NTFS();
		fs->Init(device);
		return fs;
	}
	case FSEnum::exFAT: {
		exFAT* fs = new exFAT();
		fs->Init(device);
		return fs;
	}
	default:
		throw std::invalid_argument("Set FilePointer error");
		return NULL;
	}
}
