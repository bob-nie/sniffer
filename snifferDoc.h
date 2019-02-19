// snifferDoc.h : interface of the CSnifferDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNIFFERDOC_H__E4DCFD8E_D3C1_4027_BBF0_F84F325F9C69__INCLUDED_)
#define AFX_SNIFFERDOC_H__E4DCFD8E_D3C1_4027_BBF0_F84F325F9C69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSnifferDoc : public CDocument
{
protected: // create from serialization only
	CSnifferDoc();
	DECLARE_DYNCREATE(CSnifferDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnifferDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSnifferDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSnifferDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNIFFERDOC_H__E4DCFD8E_D3C1_4027_BBF0_F84F325F9C69__INCLUDED_)
