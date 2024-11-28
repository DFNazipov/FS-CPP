//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
#include "ThreadDB.h"
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "VirtualTrees.AncestorVCL.hpp"
#include "VirtualTrees.BaseAncestorVCL.hpp"
#include "VirtualTrees.BaseTree.hpp"
#include "VirtualTrees.hpp"
#include "Unit1.h"
#include "BaseFS.h"
#include "NTFS.h"
#include "windows.h"
#include "Decorator.h"
#include "FSDecorator.h"
#include "exFAT.h"
#include "FSCreator.h"
#include "ThreadClusters.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall read_thread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall ThreadClusters::ThreadClusters(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	 FreeOnTerminate = true;
	 ThreadDBObject = new ThreadDB(false);
}
//---------------------------------------------------------------------------
void __fastcall ThreadClusters::Execute()
{
	while(!Terminated)
	{
		//---- Place thread code here ----
		FSCreator* fsCreator = new MyFSCreator;
		UnicodeString tempString = Form1->DiskEdit1->Text;
		fileName = tempString.c_str();
		FSEnum fsType = DetectFS(fileName);
		Synchronize(UpdateFS);
		BaseFS* fs = fsCreator->CreateFS(fsType, fileName);
		if (!fs->Init(fileName)) {
			throw  "Cannot open logic disk";
		};
		clusterCount = fs->getClusterCount();
		unsigned int clusterSize = fs->getClusterSize();
		FEEnum fileType = GetFileType();
		Iterator<Cluster>* it = new FSDecorator(
			new NTFSIterator(fs),
			fileType
		);
		for (it->first();!it->isDone() && !Terminated;it->next()) {
			Cluster currentObject = it->getCurrent();
			clusters += 1;
			ThreadDBObject->Send(&currentObject);
			ThreadDBObject->DataReadyEvent->SetEvent();
			while(ThreadDBObject->DataCopiedEvent->WaitFor(3000) != wrSignaled)
			{ }
			ThreadDBObject->DataCopiedEvent->ResetEvent();
			Synchronize(UpdateLabel);
		}

        break;
	}
	ThreadDBObject->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall ThreadClusters::UpdateLabel()
{
	Form1->CountResultLabel->Caption = clusters;
}
void __fastcall ThreadClusters::UpdateFS()
{
	Form1->DetectResultLabel->Caption = FS;
}
FSEnum __fastcall ThreadClusters::DetectFS(LPCWSTR fileName) {
    HANDLE fileHandler = CreateFileW(
		fileName,    // Drive to open
        GENERIC_READ,           // Access mode
        FILE_SHARE_READ | FILE_SHARE_WRITE,        // Share Mode
        NULL,                   // Security Descriptor
        OPEN_EXISTING,          // How to create
        0,                      // File attributes
        NULL);                  // Handle to template
    if (fileHandler == INVALID_HANDLE_VALUE)
    {
        throw std::invalid_argument("Error INVALID_HANDLE_VALUE!");
    }
    DWORD bytesRead;
    BYTE buffer[2048];

    if (!ReadFile(fileHandler, buffer, sizeof(buffer), &bytesRead, nullptr)) {
        throw "Error reading volume\n";
	}
	BYTE ntfsSignature[] = { 0x4E, 0x54, 0x46, 0x53 };
	if (memcmp(buffer + 3, ntfsSignature, sizeof(ntfsSignature)) == 0) {
		FS = L"NTFS";
		return FSEnum::NTFS;
	}
    BYTE exfatSignature[] = { 0x45, 0x58, 0x46, 0x41, 0x54 };
	if (memcmp(buffer + 3, exfatSignature, sizeof(exfatSignature)) == 0) {
		FS = L"exFAT";
		return FSEnum::exFAT;
	}
    throw "Cannot detect fs!";
}
FEEnum __fastcall ThreadClusters::GetFileType()
{
	if(Form1->jpegButton->Checked){
		return  FEEnum::jpeg;
	}
	if(Form1->pdfButton->Checked){
		return  FEEnum::pdf;
	}
	if(Form1->exeButton->Checked){
		return  FEEnum::exe;
	}
	return FEEnum::png;
}
