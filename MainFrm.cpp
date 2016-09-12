// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "LibUIDK_Demo.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

BEGIN_MESSAGE_MAP(CMainFrame, CUIWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_pStaTitle = NULL;
	m_pBtnMin = NULL;
	m_pChkMax = NULL;
	m_pBtnClose = NULL;
	m_pStaMsg = NULL;

	m_bMax = FALSE;
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

void CMainFrame::DoDataExchange(CDataExchange* pDX)
{
	CUIWnd::DoDataExchange(pDX);

	DDX_Check(pDX, IDC_CHK_MAX, m_bMax);
}


//////////////////////////////////////////////////////////////////////////
// protected

int CMainFrame::InitControls()
{
	m_pStaTitle = (CSkinStatic *)GetDlgItem(IDC_STA_TITLE);
	m_pBtnMin = (CSkinButton *)GetDlgItem(IDC_BTN_MIN);
	m_pChkMax = (CSkinButton *)GetDlgItem(IDC_CHK_MAX);
	m_pBtnClose = (CSkinButton *)GetDlgItem(IDC_BTN_CLOSE);
	m_pStaMsg = (CSkinStatic *)GetDlgItem(IDC_STA_MSG);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CUIWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (InitControls() != 0)
		return -1;

	CenterWindow();

	// TODO: Add your message handler code here
	
	return 0;
}
