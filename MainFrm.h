// MainFrm.h : interface of the CMainFrame class
//
#pragma once

class CMainFrame : public CUIWnd
{
public:
	CMainFrame();
	virtual ~CMainFrame();
	void WindowID() { IDD = IDW_MAIN; }

protected:
	int InitControls();

public:


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

protected:
	CSkinStatic *m_pStaTitle;
	CSkinButton *m_pBtnMin;
	CSkinButton *m_pChkMax;
	CSkinButton *m_pBtnClose;
	CSkinStatic *m_pStaMsg;

public:
	BOOL m_bMax;
};
