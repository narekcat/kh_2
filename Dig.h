#if !defined(AFX_DIG_H__E761F190_88EB_4E3D_BE9A_648AAA305C6F__INCLUDED_)
#define AFX_DIG_H__E761F190_88EB_4E3D_BE9A_648AAA305C6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDig dialog

class CDig : public CDialog
{
// Construction
public:
	CDig(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDig)
	enum { IDD = IDD_DIALOG1 };
	short	m_N;
	short	m_K;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDig)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIG_H__E761F190_88EB_4E3D_BE9A_648AAA305C6F__INCLUDED_)
