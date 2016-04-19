// kh_2View.h : interface of the CKh_2View class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_KH_2VIEW_H__DC91E25F_684B_40FA_A384_9719DBE92686__INCLUDED_)
#define AFX_KH_2VIEW_H__DC91E25F_684B_40FA_A384_9719DBE92686__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKh_2View : public CFormView
{
protected: // create from serialization only
	void Drawthis();
	CKh_2View();
	DECLARE_DYNCREATE(CKh_2View)

public:
	//{{AFX_DATA(CKh_2View)
	enum { IDD = IDD_KH_2_FORM };
	CProgressCtrl	m_Progress;
	int		m_this;
	int		m_all;
	CMSFlexGrid	m_fg;
	CString	m_W;
	CString	m_S;
	//}}AFX_DATA

// Attributes
public:
	bool next_flag,back_flag;
	CKh_2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKh_2View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKh_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	bool is_run;
	bool run_flag;

// Generated message map functions
protected:
	//{{AFX_MSG(CKh_2View)
	afx_msg void OnToolsNext();
	afx_msg void OnToolsBack();
	afx_msg void OnUpdateToolsNext(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsBack(CCmdUI* pCmdUI);
	afx_msg void OnKeyPressMsflexgrid1(short FAR* KeyAscii);
	afx_msg void OnToolsComplete();
	afx_msg void OnToolsRun();
	afx_msg void OnUpdateToolsRun(CCmdUI* pCmdUI);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in kh_2View.cpp
inline CKh_2Doc* CKh_2View::GetDocument()
   { return (CKh_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KH_2VIEW_H__DC91E25F_684B_40FA_A384_9719DBE92686__INCLUDED_)
