// kh_2.h : main header file for the KH_2 application
//

#if !defined(AFX_KH_2_H__AA9210D5_B0E8_452E_9C46_B487978D066B__INCLUDED_)
#define AFX_KH_2_H__AA9210D5_B0E8_452E_9C46_B487978D066B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKh_2App:
// See kh_2.cpp for the implementation of this class
//

class CKh_2App : public CWinApp
{
public:
	CKh_2App();
	bool is_first;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKh_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CKh_2App)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KH_2_H__AA9210D5_B0E8_452E_9C46_B487978D066B__INCLUDED_)
