//---------------------------------------------------------------------------

#ifndef ReadThreadH
#define ReadThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "ThreadDB.h"
#include "FSCreator.h"
//---------------------------------------------------------------------------
class ThreadCluster : public TThread
{
private:
	__int64 clusters;
	UnicodeString DetectedFS;
    LPCWSTR logicDisk;
	class ThreadDB *ThreadDBObject;
    unsigned int clusterCount;
protected:
	void __fastcall Execute();
	void __fastcall UpdateLabel();
    void __fastcall UpdateFS();
	FSEnum __fastcall DetectFS(LPCWSTR device);
	FEEnum __fastcall GetFileType();
public:
	__fastcall ThreadCluster(bool CreateSuspended);

};
//---------------------------------------------------------------------------
#endif
