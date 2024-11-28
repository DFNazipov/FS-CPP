//---------------------------------------------------------------------------
#include <System.hpp>
#pragma hdrstop
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
#include <sqlite3.h>
#pragma package(smart_init)
//---------------------------------------------------------------------------
//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Analyse_thread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall ThreadDB::ThreadDB(bool CreateSuspended)
	: TThread(CreateSuspended)
{

	FreeOnTerminate = true;

	int openResult = sqlite3_open16(L"../../database.db", &Database);
	if (openResult != SQLITE_OK) {
		throw "Cannot open sqlite db";
	}
	char* errmsg;
	char sql[] = "CREATE TABLE IF NOT EXISTS clusters("
		"cluster_num INT NOT NULL,"
		"content TEXT NOT NULL);";

    int execResult = sqlite3_exec(Database, sql, NULL, NULL, &errmsg);
	if (execResult != SQLITE_OK) {
		throw "Canoot create sqlite table";
	}

	int rc = sqlite3_prepare_v2(Database, "INSERT INTO clusters (cluster_num, content) VALUES (?, ?)", -1, &res, 0);
	if (rc != SQLITE_OK)
	{
		throw "Cannot prepate query";
	}

	DataReadyEvent = new TEvent(NULL, true, false, "", false);
	DataCopiedEvent = new TEvent(NULL, true, false, "", false);
}

//---------------------------------------------------------------------------
void __fastcall ThreadDB::Execute()
{
	while(!Terminated)
	{

		if(DataReadyEvent->WaitFor(INFINITE) == wrSignaled)
		{

			DataReadyEvent->ResetEvent();

  			Synchronize(Update);
			InsertData();
			DataCopiedEvent->SetEvent();
		}
	}
	sqlite3_close(Database);
	sqlite3_finalize(res);
    delete DataReadyEvent;
	delete DataCopiedEvent;
}
//---------------------------------------------------------------------------
void __fastcall ThreadDB::Send(Cluster* cluster){
	data = cluster;
}
void __fastcall ThreadDB::Update()
{
	TBytes buff;
	buff.set_length(32);
	memcpy(&buff[0],  data->getContent(), 32);

	PVirtualNode entryNode = Form1->ResStringTree->AddChild(Form1->ResStringTree->RootNode);
	NodeStruct *nodeData = (NodeStruct*)Form1->ResStringTree->GetNodeData(entryNode);
	nodeData->ClusterNum = data->getNumber();
	nodeData->Content = System::Sysutils::StringOf(buff);
}

void __fastcall ThreadDB::InsertData()
{
	char str[32];
	memcpy(str, data->getContent(), 32);
	sqlite3_exec(Database, "BEGIN;", nullptr, nullptr, nullptr);
	sqlite3_bind_int(res, 1, data->getNumber());
	sqlite3_bind_text(res, 2, str, -1, SQLITE_STATIC);
	int step = sqlite3_step(res);
	if (step == SQLITE_ERROR)
	{
		throw "SQLITE_ERROR";
	}

	sqlite3_clear_bindings(res);
	sqlite3_reset(res);
	sqlite3_exec(Database, "COMMIT;", nullptr, nullptr, nullptr);
}
