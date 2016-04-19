// kh_2View.cpp : implementation of the CKh_2View class
//

#include "stdafx.h"
#include "kh_2.h"

#include "kh_2Doc.h"
#include "kh_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKh_2View


//const short int num0=static_cast<short int>('0');

IMPLEMENT_DYNCREATE(CKh_2View, CFormView)

BEGIN_MESSAGE_MAP(CKh_2View, CFormView)
	//{{AFX_MSG_MAP(CKh_2View)
	ON_COMMAND(ID_TOOLS_NEXT, OnToolsNext)
	ON_COMMAND(ID_TOOLS_BACK, OnToolsBack)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_NEXT, OnUpdateToolsNext)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_BACK, OnUpdateToolsBack)
	ON_COMMAND(ID_TOOLS_COMPLETE, OnToolsComplete)
	ON_COMMAND(ID_TOOLS_RUN, OnToolsRun)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_RUN, OnUpdateToolsRun)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKh_2View construction/destruction

CKh_2View::CKh_2View()
	: CFormView(CKh_2View::IDD)
{
	//{{AFX_DATA_INIT(CKh_2View)
	m_this = 0;
	m_all = 0;
	m_W = _T("");
	m_S = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CKh_2View::~CKh_2View()
{
}

void CKh_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKh_2View)
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
	DDX_Text(pDX, IDC_EDIT1, m_this);
	DDX_Text(pDX, IDC_EDIT2, m_all);
	DDX_Control(pDX, IDC_MSFLEXGRID1, m_fg);
	DDX_Text(pDX, IDC_EDIT3, m_W);
	DDX_Text(pDX, IDC_EDIT4, m_S);
	//}}AFX_DATA_MAP
}

BOOL CKh_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CKh_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	CKh_2Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	next_flag=(pDoc->zm.index!=pDoc->zm.N);
	back_flag=(pDoc->zm.index!=0);
	m_all=pDoc->zm.all_drip;
	UpdateData(false);
	CString s="";
	m_fg.SetRows(pDoc->zm.K+1);
	Drawthis();
	for(int i=0;i<pDoc->zm.K;i++)
	{
		s.Format("Object %u",i+1);
		m_fg.SetTextMatrix(0,i+1,s);
		m_fg.SetTextMatrix(i+1,0,s);
	}
	is_run=false;
	run_flag=(pDoc->zm.all_drip==0);
}

/////////////////////////////////////////////////////////////////////////////
// CKh_2View printing

BOOL CKh_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKh_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKh_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CKh_2View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CKh_2View diagnostics

#ifdef _DEBUG
void CKh_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CKh_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CKh_2Doc* CKh_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKh_2Doc)));
	return (CKh_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKh_2View message handlers

void CKh_2View::Drawthis()
{
	CKh_2Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	CString s="";
	int i,j;
	if(pDoc->zm.index==pDoc->zm.N)
	{
		if(m_fg.GetCols()!=pDoc->zm.K+2)
		{
			m_fg.SetCols(pDoc->zm.K+3);
			m_fg.SetRows(pDoc->zm.K+2);
			m_fg.SetTextMatrix(0,pDoc->zm.K+1,"Gumar");
			m_fg.SetTextMatrix(0,pDoc->zm.K+2,"New class");
			m_fg.SetTextMatrix(pDoc->zm.K+1,0,"tij");
		}
		for(i=0;i<pDoc->zm.K+1;i++)
			for(j=0;j<pDoc->zm.K+2;j++)
			{
				s.Format("%u",pDoc->zm.gumar[i][j]);
				m_fg.SetTextMatrix(i+1,j+1,s);
			}
		m_fg.SetTextMatrix(pDoc->zm.K+1,pDoc->zm.K+2,"");
		m_fg.SetTextMatrix(pDoc->zm.K+1,pDoc->zm.K+1,"");
		m_fg.SetTextMatrix(0,0,"Gumar");
		m_this=0;
		UpdateData(false);
	}
	else
	{
		if(m_fg.GetCols()!=pDoc->zm.K+1)
		{
			m_fg.SetCols(pDoc->zm.K+1);
			m_fg.SetRows(pDoc->zm.K+1);
		}
		m_this=pDoc->zm.this_drip[pDoc->zm.index];
		UpdateData(false);
		for(i=0;i<pDoc->zm.K;i++)
			for(j=0;j<pDoc->zm.K;j++)
			{
				if(pDoc->zm.p[pDoc->zm.index].mat[i][j]!='x')
				{
					s=pDoc->zm.p[pDoc->zm.index].mat[i][j];
					m_fg.SetTextMatrix(i+1,j+1,s);
				}
				else
					m_fg.SetTextMatrix(i+1,j+1,"");
			}
		s.Format("Expen %u",pDoc->zm.index+1);
		m_fg.SetTextMatrix(0,0,s);
	}
}

void CKh_2View::OnToolsNext() 
{
	CKh_2Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->zm.index++;
	next_flag=(pDoc->zm.index!=pDoc->zm.N);
	back_flag=(pDoc->zm.index!=0);
	Drawthis();
}

void CKh_2View::OnToolsBack() 
{
	CKh_2Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->zm.index--;
	next_flag=(pDoc->zm.index!=pDoc->zm.N);
	back_flag=(pDoc->zm.index!=0);
	Drawthis();
}

void CKh_2View::OnUpdateToolsNext(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(next_flag);
}

void CKh_2View::OnUpdateToolsBack(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(back_flag);
}

BEGIN_EVENTSINK_MAP(CKh_2View, CFormView)
    //{{AFX_EVENTSINK_MAP(CKh_2View)
	ON_EVENT(CKh_2View, IDC_MSFLEXGRID1, -603 /* KeyPress */, OnKeyPressMsflexgrid1, VTS_PI2)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CKh_2View::OnKeyPressMsflexgrid1(short FAR* KeyAscii) 
{
	int r=m_fg.GetRow(),c=m_fg.GetCol();
	char nChar=static_cast<char>(*KeyAscii);
	CKh_2Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	if(r!=c && pDoc->zm.index!=pDoc->zm.N)
		if(nChar=='0' || nChar=='1')
		{
			if(pDoc->zm.p[pDoc->zm.index].mat[r-1][c-1]=='x')
			{
				if(nChar=='1')
				{
					pDoc->zm.gumar[r-1][c-1]++;
					pDoc->zm.gumar[r-1][pDoc->zm.K]++;
				}
				else
				{
					pDoc->zm.gumar[c-1][r-1]++;
					pDoc->zm.gumar[c-1][pDoc->zm.K]++;
				}
				pDoc->zm.this_drip[pDoc->zm.index]--;
				m_this=pDoc->zm.this_drip[pDoc->zm.index];
				pDoc->zm.all_drip--;
				m_all=pDoc->zm.all_drip;
				UpdateData(false);
			}
			if(nChar=='0')
			{
				if(pDoc->zm.p[pDoc->zm.index].mat[r-1][c-1]=='1')
				{
					pDoc->zm.gumar[r-1][c-1]--;
					pDoc->zm.gumar[r-1][pDoc->zm.K]--;
					pDoc->zm.gumar[c-1][r-1]++;
					pDoc->zm.gumar[c-1][pDoc->zm.K]++;
				}
				m_fg.SetTextMatrix(r,c,"0");
				m_fg.SetTextMatrix(c,r,"1");
				pDoc->zm.p[pDoc->zm.index].mat[r-1][c-1]='0';
				pDoc->zm.p[pDoc->zm.index].mat[c-1][r-1]='1';
			}
			else
			{
				if(pDoc->zm.p[pDoc->zm.index].mat[r-1][c-1]=='0')
				{
					pDoc->zm.gumar[r-1][c-1]++;
					pDoc->zm.gumar[r-1][pDoc->zm.K]++;
					pDoc->zm.gumar[c-1][r-1]--;
					pDoc->zm.gumar[c-1][pDoc->zm.K]--;
				}
				m_fg.SetTextMatrix(r,c,"1");
				m_fg.SetTextMatrix(c,r,"0");
				pDoc->zm.p[pDoc->zm.index].mat[r-1][c-1]='1';
				pDoc->zm.p[pDoc->zm.index].mat[c-1][r-1]='0';
			}
			pDoc->SetModifiedFlag();
			pDoc->UpdateAllViews(this,0L,NULL);
			run_flag=(!pDoc->zm.all_drip);
			if(is_run)
			{
				is_run=false;
				m_W="";
				m_S="";
				UpdateData(false);
				m_Progress.SetPos(0);
			}

		}
}

void CKh_2View::OnToolsComplete() 
{
	CKh_2Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	int i,j;
	short int c;
	if(pDoc->zm.index<pDoc->zm.N)
	{
		bool t=false;
		for(i=0;i<pDoc->zm.K-1;i++)
			for(j=i+1;j<pDoc->zm.K;j++)
			{
				if(pDoc->zm.p[pDoc->zm.index].mat[i][j]=='x')
				{
					t=true;
					c=rand()%2;
					switch(c)
					{
					case 0:
						pDoc->zm.gumar[j][i]++;
						pDoc->zm.gumar[j][pDoc->zm.K]++;
						pDoc->zm.p[pDoc->zm.index].mat[i][j]='0';
						pDoc->zm.p[pDoc->zm.index].mat[j][i]='1';
						m_fg.SetTextMatrix(i+1,j+1,"0");
						m_fg.SetTextMatrix(j+1,i+1,"1");
						break;
					case 1:
						pDoc->zm.gumar[i][j]++;
						pDoc->zm.gumar[i][pDoc->zm.K]++;
						pDoc->zm.p[pDoc->zm.index].mat[i][j]='1';
						pDoc->zm.p[pDoc->zm.index].mat[j][i]='0';
						m_fg.SetTextMatrix(i+1,j+1,"1");
						m_fg.SetTextMatrix(j+1,i+1,"0");
						break;
					}
					pDoc->zm.this_drip[pDoc->zm.index]--;
					pDoc->zm.all_drip--;
				}
			}
		if(t)
		{
			pDoc->UpdateAllViews(this,0L,NULL);
			pDoc->SetModifiedFlag();
			m_all=pDoc->zm.all_drip;
			m_this=pDoc->zm.this_drip[pDoc->zm.index];
			UpdateData(false);
			run_flag=true;
		}
	}
}

void CKh_2View::OnToolsRun() 
{
	CKh_2Doc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->zm.index=pDoc->zm.N;
	Drawthis();
	double Sv,Wv;
	pDoc->zm.run(Wv,Sv);
	CString s="";
	for(int i=0;i<pDoc->zm.K;i++)
	{
		s.Format("%u",pDoc->zm.gumar[i][pDoc->zm.K+1]);
		m_fg.SetTextMatrix(i+1,pDoc->zm.K+2,s);
		s.Format("%u",pDoc->zm.gumar[pDoc->zm.K][i]);
		m_fg.SetTextMatrix(pDoc->zm.K+1,i+1,s);
	}
	m_S.Format("%.3f",Sv);
	m_W.Format("%.3f",Wv);
	UpdateData(false);
	m_Progress.SetRange(1,10);
	for(i=1;i<=10;i++)
		m_Progress.SetPos(i);
	is_run=true;
}

void CKh_2View::OnUpdateToolsRun(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(run_flag);
}
