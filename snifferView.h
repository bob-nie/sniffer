// snifferView.h : interface of the CSnifferView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNIFFERVIEW_H__AFCFD2CA_8048_45D9_954D_24432CAA8EC3__INCLUDED_)
#define AFX_SNIFFERVIEW_H__AFCFD2CA_8048_45D9_954D_24432CAA8EC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000




class CSnifferView : public CFormView
{
protected: // create from serialization only
	CSnifferView();
	DECLARE_DYNCREATE(CSnifferView)

public:
	//{{AFX_DATA(CSnifferView)
	enum{ IDD = IDD_SNIFFER_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CSnifferDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnifferView)
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
	virtual ~CSnifferView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSnifferView)
	afx_msg void OnBtnStart();
	afx_msg void OnBtnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in snifferView.cpp
inline CSnifferDoc* CSnifferView::GetDocument()
   { return (CSnifferDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNIFFERVIEW_H__AFCFD2CA_8048_45D9_954D_24432CAA8EC3__INCLUDED_)
