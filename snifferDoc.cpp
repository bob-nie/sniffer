// snifferDoc.cpp : implementation of the CSnifferDoc class
//

#include "stdafx.h"
#include "sniffer.h"

#include "snifferDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnifferDoc

IMPLEMENT_DYNCREATE(CSnifferDoc, CDocument)

BEGIN_MESSAGE_MAP(CSnifferDoc, CDocument)
	//{{AFX_MSG_MAP(CSnifferDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnifferDoc construction/destruction

CSnifferDoc::CSnifferDoc()
{
	// TODO: add one-time construction code here

}

CSnifferDoc::~CSnifferDoc()
{
}

BOOL CSnifferDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSnifferDoc serialization

void CSnifferDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSnifferDoc diagnostics

#ifdef _DEBUG
void CSnifferDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnifferDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnifferDoc commands
