//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "VirtualTrees.AncestorVCL.hpp"
#include "VirtualTrees.BaseAncestorVCL.hpp"
#include "VirtualTrees.BaseTree.hpp"
#include "VirtualTrees.hpp"
#include "ThreadClusters.h"
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *StartButton;
	TLabel *CountResultLabel;
	TVirtualStringTree *ResStringTree;
	TRadioButton *jpegButton;
	TRadioButton *pdfButton;
	TRadioButton *exeButton;
	TRadioButton *pngButton;
	TButton *StopButton;
	TPanel *Panel1;
	TLabel *FileExtensionLabel;
	TLabel *CountLabel;
	TLabel *DetectLabel;
	TLabel *DetectResultLabel;
	TEdit *DiskEdit1;
	TLabel *fileNameLabel;
	void __fastcall StopButtonClick(TObject *Sender);
	void __fastcall StartButtonClick(TObject *Sender);
	void __fastcall ResStringTreeGet(TBaseVirtualTree *Sender, PVirtualNode Node, int Column, TVSTTextType TextType, UnicodeString &CellText);
private:	// User declarations
	ThreadClusters *thrd;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
typedef struct
{
	ULONGLONG ClusterNum;
	UnicodeString Content;
} NodeStruct;
#endif
