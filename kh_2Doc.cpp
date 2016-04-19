// kh_2Doc.cpp : implementation of the CKh_2Doc class
//

#include "stdafx.h"
#include "kh_2.h"

#include "kh_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKh_2Doc

#include "tr.h"

extern trans tr_value; 

IMPLEMENT_DYNCREATE(CKh_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CKh_2Doc, CDocument)
	//{{AFX_MSG_MAP(CKh_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKh_2Doc construction/destruction

CKh_2Doc::CKh_2Doc()
{
	zm.SetParam(tr_value.trk,tr_value.trn);
}

CKh_2Doc::~CKh_2Doc()
{
}

BOOL CKh_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	SetModifiedFlag();
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CKh_2Doc serialization

void CKh_2Doc::Serialize(CArchive& ar)
{
	zm.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CKh_2Doc diagnostics

#ifdef _DEBUG
void CKh_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKh_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKh_2Doc commands
