// Dig.cpp : implementation file
//

#include "stdafx.h"
#include "kh_2.h"
#include "Dig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDig dialog


CDig::CDig(CWnd* pParent /*=NULL*/)
	: CDialog(CDig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDig)
	m_N = 0;
	m_K = 0;
	//}}AFX_DATA_INIT
}


void CDig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDig)
	DDX_Text(pDX, IDC_EDIT1, m_N);
	DDV_MinMaxInt(pDX, m_N, 1, 100);
	DDX_Text(pDX, IDC_EDIT2, m_K);
	DDV_MinMaxInt(pDX, m_K, 1, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDig, CDialog)
	//{{AFX_MSG_MAP(CDig)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDig message handlers
