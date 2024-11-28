//---------------------------------------------------------------------------

#ifndef ThreadDBH
#define ThreadDBH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "Unit1.h"
#include "BaseFS.h"
#include "NTFS.h"
#include "windows.h"
#include "NTFSIterator.h"
#include "Decorator.h"
#include "FSDecorator.h"
#include "exFAT.h"
#include "FSCreator.h"
#include <sqlite3.h>
//---------------------------------------------------------------------------
class ThreadDB : public TThread
{
private:
protected:
	void __fastcall Execute();
	Cluster* data;
	sqlite3* Database;
	sqlite3_stmt* res;
	LPCWSTR DatabasePath;
public:
	__fastcall ThreadDB(bool CreateSuspended);
	void __fastcall Send(Cluster* data);
	void __fastcall Update();
	void __fastcall InsertData();
	// события, необходимые для реализации анализа
	TEvent *DataReadyEvent;
	TEvent *DataCopiedEvent;
};
//---------------------------------------------------------------------------
#endif
