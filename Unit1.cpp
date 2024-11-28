//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "ThreadClusters.h"
#include "ThreadDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	ResStringTree->NodeDataSize = sizeof(NodeStruct);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StopButtonClick(TObject *Sender)
{
    thrd->Terminate();
	thrd->Free();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StartButtonClick(TObject *Sender)
{
	Form1->ResStringTree->Clear();
	Form1->CountResultLabel->Caption = L"0";
	Form1->DetectResultLabel->Caption = L"None";
	thrd = new ThreadClusters(false);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ResStringTreeGet(TBaseVirtualTree *Sender, PVirtualNode Node,
		  int Column, TVSTTextType TextType, UnicodeString &CellText)
{
if (!Node) return;
	NodeStruct *nodeData = (NodeStruct*)Sender->GetNodeData(Node);
	switch(Column){
		case 0: CellText = nodeData->ClusterNum; break;
	   case 1: CellText = nodeData->Content; break;
	}

}
//---------------------------------------------------------------------------

