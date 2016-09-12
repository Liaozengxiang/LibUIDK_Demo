// LibUIDK_Demo.h : main header file for the LIBUIDK_DEMO application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

class CMainFrame;

/////////////////////////////////////////////////////////////////////////////
// CLibUIDK_DemoApp:
// See LibUIDK_Demo.cpp for the implementation of this class
//

class CLibUIDK_DemoApp : public CWinApp
{
public:
	CLibUIDK_DemoApp();

// Overrides
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	DECLARE_MESSAGE_MAP()

private:
	CMainFrame *m_pFrame;
};

