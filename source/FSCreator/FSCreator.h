#pragma once
#include "BaseFS.h"
#include "Windows.h"
enum class FSEnum { NTFS, exFAT };
class FSCreator
{
public:
	virtual BaseFS* CreateFS(FSEnum, LPCWSTR) = 0;
};

class MyFSCreator :
	public FSCreator
{
	BaseFS* CreateFS(FSEnum, LPCWSTR);
};
