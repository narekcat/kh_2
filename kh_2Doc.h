// kh_2Doc.h : interface of the CKh_2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KH_2DOC_H__1A0782B9_429D_42D5_9A17_226ECF61751F__INCLUDED_)
#define AFX_KH_2DOC_H__1A0782B9_429D_42D5_9A17_226ECF61751F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "zujg.h"

class CKh_2Doc : public CDocument
{
protected: // create from serialization only
	CKh_2Doc();
	DECLARE_DYNCREATE(CKh_2Doc)

// Attributes
public:
	zujg zm;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKh_2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKh_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKh_2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KH_2DOC_H__1A0782B9_429D_42D5_9A17_226ECF61751F__INCLUDED_)
