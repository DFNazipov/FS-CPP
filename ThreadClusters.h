//---------------------------------------------------------------------------

#ifndef ThreadClustersH
#define ThreadClustersH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "ThreadDB.h"
#include "FSCreator.h"
//---------------------------------------------------------------------------
class ThreadClusters : public TThread
{
private:
	__int64 clusters;
	UnicodeString FS;
	LPCWSTR fileName;
	class ThreadDB *ThreadDBObject;
    unsigned int clusterCount;
protected:
	void __fastcall Execute();
	void __fastcall UpdateLabel();
    void __fastcall UpdateFS();
	FSEnum __fastcall DetectFS(LPCWSTR fileName);
	FEEnum __fastcall GetFileType();
public:
	__fastcall ThreadClusters(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
