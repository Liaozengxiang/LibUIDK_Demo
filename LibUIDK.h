#ifndef _CONTROLS_H_
#define _CONTROLS_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning (disable : 4786)

#include <AFXCMN.H>
#include <vector>
#include <map>
#include <afxole.h>
#include <afxtempl.h>
#include <comutil.h>
#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include <afxhtml.h>
#include <afxdtctl.h>

#ifdef USEGDIPLUS

#ifndef ULONG_PTR
#if defined(_WIN64)
	typedef unsigned __int64 ULONG_PTR;
#else
	typedef unsigned long ULONG_PTR;
#endif //_WIN64
#endif //ULONG_PTR

#include <GdiPlus.h>
using namespace Gdiplus;
#pragma comment (lib, "Gdiplus.lib")

#endif //USEGDIPLUS


#ifdef USEGDIPLUS
typedef Bitmap * BITMAPOBJ;
#else
typedef HBITMAP BITMAPOBJ;
#endif

#ifndef WS_EX_LAYERED
#define WS_EX_LAYERED           0x00080000
#endif
#ifndef LWA_COLORKEY
#define LWA_COLORKEY            0x00000001
#endif
#ifndef LWA_ALPHA
#define LWA_ALPHA               0x00000002
#endif

#ifndef WS_EX_NOACTIVATE
#if(_WIN32_WINNT >= 0x0500)
#define WS_EX_NOACTIVATE        0x08000000L
#endif /* _WIN32_WINNT >= 0x0500 */
#endif

#if _WIN32_WINNT < 0x0600
#ifndef LVS_EX_JUSTIFYCOLUMNS
#define LVS_EX_JUSTIFYCOLUMNS   0x00200000  // Icons are lined up in columns that use up the whole view area.
#endif
#endif // _WIN32_WINNT >= 0x0600


namespace LibUIDK
{

//////////////////////////////////////////////////////////////////////////
// Message Define:
// LibUIDK use custom message ID from WM_APPLICATION to WM_LIBUIDK
#define WM_APPLICATION	WM_USER+100
#define WM_BUTTON		WM_USER+200
#define WM_STATIC		WM_USER+300
#define WM_EDIT			WM_USER+400
#define WM_COMBOBOX		WM_USER+400
#define WM_SLIDER		WM_USER+500
#define WM_SPINBUTTON	WM_USER+600
#define WM_PROGRESS		WM_USER+700
#define WM_HOTKEYCTRL	WM_USER+800
#define WM_IPADDRESS	WM_USER+900
#define WM_LISTCTRL		WM_USER+1000
#define WM_TREECTRL		WM_USER+1100
#define WM_SCROLLBAR	WM_USER+1200
#define WM_THUMBNAIL	WM_USER+1300
#define WM_TREELIST		WM_USER+1400
#define WM_RICHEDIT		WM_USER+1500
#define WM_HTMLCTRL		WM_USER+1600
#define WM_DATETIMECTRL	WM_USER+1700
#define WM_WAVECTRL		WM_USER+1800
#define WM_RECTCTRL		WM_USER+1900
#define WM_CLOCK		WM_USER+2000
#define WM_HEADER		WM_USER+2100
#define WM_MENU			WM_USER+2200
#define WM_MENUBAR		WM_USER+2300
#define WM_DRAGDROP		WM_USER+3000
#define WM_TASKWNDMGR	WM_USER+3100
#define WM_LIBUIDK		WM_USER+4000
#define WM_CUSTOM		WM_USER+5000

#define WM_CHANGESKIN                 WM_APPLICATION+3
#define WM_GETRESIZEPOINT             WM_APPLICATION+5 // LPARAM is the handle of the control.
// The WPARAM of the WM_GETRESIZEPOINT
#define GR_POINTX                     0x00000001 // x of the resizing point
#define GR_POINTY                     0x00000002 // y of the resizing point
#define WM_NEEDRESIZE                 WM_APPLICATION+6
#define WM_ISNEEDRESIZE               WM_APPLICATION+11
#define WM_ISCHILDMOVE                WM_APPLICATION+12 // WPARAM: not used. LPARAM: handle of the child
#define WM_PARENTEVENT                WM_APPLICATION+16
#define WM_DRAWITEMEX                 WM_APPLICATION+17
#define WM_GETDOCVIEWCLIENTRECT       WM_APPLICATION+18 // Get the MDI or SDI document/view client rect, LPARAM is a pointer to RECT struct.
#define WM_ISUIWND                    WM_APPLICATION+19	// Is the window CUIWnd or its derive class.
#define WM_ISIUIFRAMEWND              WM_APPLICATION+20	// Is the window CIUIFrameWnd or its derive class.
#define WM_DRAWCONTROL                WM_APPLICATION+21	// Draw the control send by CUIWnd with layered style and use UpdateLayeredWindow to draw the UI.
#define WM_REFRESHUIWND               WM_APPLICATION+22	// Refresh CUIWnd instead of InvalidateRect.
#define WM_ISUPDATELAYEREDWINDOW      WM_APPLICATION+23	// If the CUIWnd has called UpdateLayeredWindow.
#define WM_GETBACKGROUND              WM_APPLICATION+24	// Return HBITMAP.
#define WM_SHOWUIWINDOW               WM_APPLICATION+25	// Send to CUIWnd's parent that the CUIWnd show or hide. WPARAM: Specifies whether a window is being shown; LPARAM: CUIWnd *.
#define WM_SET_RELEASE_RESOURCE_FLAG  WM_APPLICATION+26	// WPARAM: TRUE or FALSE; LPARAM: not use.
#define WM_GET_RELEASE_RESOURCE_FLAG  WM_APPLICATION+27
#define WM_GETMENUBAR                 WM_APPLICATION+28	// WPARAM, not use; LPARAM: CMenuBar **.

#define WM_MENUMOUSEMOVE              WM_MENU+1
#define WM_ISMENUBAR                  WM_MENU+2			// Is the window menu bar.

#define WM_TASKWNDSWITCHING           WM_TASKWNDMGR+1	// WPARAM: 'CTaskWndInfo *' for switch to; LPARAM: 'CTaskWndInfo *' for to be hide.
#define WM_TASKWNDSWITCHED            WM_TASKWNDMGR+2	// WPARAM: 'CTaskWndInfo *' for switch to; LPARAM: 'CTaskWndInfo *' for to be hide.

// Owner draw control types
#define ODT_TREELIST                  10
#define ODT_THUMBNAIL                 11


//////////////////////////////////////////////////////////////////////////
// The error code of return value by CUIWnd::GetLastCreateError()
#define E_LOADBMPB                    1		// failed to load the base image
#define E_LOADBMPN                    2		// failed to load the background image of normal status(end by _N.bmp)
#define E_LOADBMPH                    3		// failed to load the background image of highlight status(end by _H.bmp)
#define E_LOADBMPD                    4		// failed to load the background image of disable status(end by _D.bmp)
#define E_LOADBMPS                    5		// failed to load the background image of selected status(end by _S.bmp)
#define E_LOADBMPC                    6		// failed to load the background image of checked status(end by _CX.bmp)
#define E_ATTACHBMPB                  50	// failed to attach the HBITMAP of base image to CBitmap object
#define E_ATTACHBMPN                  51	// failed to attach the HBITMAP of normal image to CBitmap object
#define E_ATTACHBMPH                  52	// failed to attach the HBITMAP of highlight image to CBitmap object
#define E_ATTACHBMPD                  53	// failed to attach the HBITMAP of disable image to CBitmap object
#define E_ATTACHBMPS                  54	// failed to attach the HBITMAP of selected image to CBitmap object
#define E_ATTACHBMPC                  55	// failed to attach the HBITMAP of checked image to CBitmap object
#define E_ADJUSTCHILD                 56	// failed to adjust the child controls while change the skin
#define E_CREATECHILD                 110	// failed to create the child window 

//////////////////////////////////////////////////////////////////////////
// The error code of return value while load skin
#define E_SETUIPATH                   200   // failed to set .ui or .xui path, it cause by the ui path isn't exists.
#define E_INVALIDLICENSE              201   // invalid license
#define E_NOTUNICODE                  202	// the .ui file not support unicode when you define _UNICODE or UNICODE micro.
#define E_OLDERVERSION                203	// the version of .ui or .xui file older than LibUIDK.
#define E_NEWERVERSION                204	// the version of .ui or .xui file newer than LibUIDK.
#define E_OLEUNINIT                   205	// Not call ::OleInitialize
#define E_NOROOTELEMENT               206	// Failed to load the root element of *.xui.
#define E_CANCELTRANSFERTONEWVERSION  207	// Cancel to transfer to new version of *.xui.
#define E_NOWINDOWSNODE               208	// Not found the 'Windows' node.
#define E_NORESOURCENODE              209	// Not found the 'Resource' node.


#define DROPM_DRAGENTER				WM_DRAGDROP+1
#define DROPM_DRAGOVER				WM_DRAGDROP+2
#define DROPM_DROP					WM_DRAGDROP+3
#define DROPM_DROPEX				WM_DRAGDROP+4
#define DROPM_DRAGLEAVE				WM_DRAGDROP+5
#define DROPM_DRAGSCROLL            WM_DRAGDROP+6

#define NM_DBLCLKEX                 (NM_FIRST-30)	// Parameter same as CSkinTreeCtrl::NM_DBLCLK
#define BNN_DRAWTEXT				(NM_FIRST-31)
#define TVN_HIGHLIGHTCHANGING		(NM_FIRST-32)	// Parameter same as CSkinTreeCtrl::TVN_SELCHANGING
#define TVN_HIGHLIGHTCHANGED		(NM_FIRST-33)	// Parameter same as CSkinTreeCtrl::TVN_SELCHANGED
#define WVN_SCROLLED				(NM_FIRST-34)
#define RCN_SIZE					(NM_FIRST-35)	// Size of CRectCtrl changed

//
// type of controls
//
#define ARROW              _T("ARROW")
#define PUSHBUTTON         _T("PUSHBUTTON")
#define CHECK              _T("CHECK")
#define RADIO              _T("RADIO")
#define COMBOBOX           _T("COMBOBOX")
#define STATIC             _T("STATIC")
#define EDIT               _T("EDIT")
#define SLIDER             _T("SLIDER")
#define PROGRESS           _T("PROGRESS")
#define SPIN               _T("SPIN")
#define HOTKEY             _T("HOTKEY")
#define IPADDRESS          _T("IPADDRESS")
#define SLIDEREX           _T("SLIDEREX")
#define LISTCTRL           _T("LISTCTRL")
#define TREECTRL           _T("TREECTRL")
#define SCROLLBAR          _T("SCROLLBAR")
#define SCROLLBAREX        _T("SCROLLBAREX")
#define TREELIST           _T("TREELIST")
#define THUMBNAIL          _T("THUMBNAIL")
#define RICHEDIT           _T("RICHEDIT")
#define HTMLCTRL           _T("HTMLCTRL")
#define DATETIMECTRL       _T("DATETIMECTRL")
#define WAVECTRL           _T("WAVECTRL")
#define MENU               _T("MENU")
#define MENUBAR            _T("MENUBAR")
#define HEADERCTRL         _T("HEADERCTRL")
#define HORSCROLLBAR       _T("HORSCROLLBAR")
#define VERSCROLLBAR       _T("VERSCROLLBAR")
#define RECTCTRL           _T("RECT")
#define UIWND              _T("UIWND")

//
// type of resource
//
#define RESOURCEFONT				_T("FONT")
#define RESOURCECOLOR				_T("COLOR")

//
// type of style, share the struct of control
//

#define STYLE_PUSHBUTTON         _T("STYLE_PUSHBUTTON")
#define STYLE_CHECK              _T("STYLE_CHECK")
#define STYLE_RADIO              _T("STYLE_RADIO")
#define STYLE_COMBOBOX           _T("STYLE_COMBOBOX")
#define STYLE_STATIC             _T("STYLE_STATIC")
#define STYLE_EDIT               _T("STYLE_EDIT")
#define STYLE_SLIDER             _T("STYLE_SLIDER")
#define STYLE_PROGRESS           _T("STYLE_PROGRESS")
#define STYLE_SPIN               _T("STYLE_SPIN")
#define STYLE_HOTKEY             _T("STYLE_HOTKEY")
#define STYLE_IPADDRESS          _T("STYLE_IPADDRESS")
#define STYLE_SLIDEREX           _T("STYLE_SLIDEREX")
#define STYLE_LISTCTRL           _T("STYLE_LISTCTRL")
#define STYLE_TREECTRL           _T("STYLE_TREECTRL")
#define STYLE_TREELIST           _T("STYLE_TREELIST")
#define STYLE_RICHEDIT           _T("STYLE_RICHEDIT")
#define STYLE_HTMLCTRL           _T("STYLE_HTMLCTRL")
#define STYLE_DATETIMECTRL       _T("STYLE_DATETIMECTRL")
#define STYLE_WAVECTRL           _T("STYLE_WAVECTRL")
#define STYLE_MENU               _T("STYLE_MENU")
#define STYLE_MENUBAR            _T("STYLE_MENUBAR")
#define STYLE_HEADERCTRL         _T("STYLE_HEADERCTRL")
#define STYLE_HORSCROLLBAR       _T("STYLE_HORSCROLLBAR")
#define STYLE_VERSCROLLBAR       _T("STYLE_VERSCROLLBAR")


// SetProp
#define SETPROP_WNDPROC				_T("IUI_OLD_WNDPROC")
#define SETPROP_GRID_PANEL			_T("IUI_HWND_GRID_PANEL")
#define SETPROP_UIWND_STRINGID		_T("IUI_UIWND_STRINGID")


//////////////////////////////////////////////////////////////////////////

#define COMBINEIMAGESIZE2					2
#define COMBINEIMAGESIZE4					4
#define COMBINEIMAGESIZE8					8


//////////////////////////////////////////////////////////////////////////
// the LPARAM parameter of BNN_DRAWTEXT notify
struct NMBUTTON
{
	NMHDR hdr;
	HDC hDC;
	RECT rc;
	UINT uFormat;
};

//////////////////////////////////////////////////////////////////////////

// text horizontal align mode
enum TEXT_ALIGN_HOR
{
	TAH_UNKNOWN = -1,
	TAH_DEFAULT = 0,
	TAH_LEFT = 1,
	TAH_RIGHT = 2,
	TAH_CENTER = 3,
};

// text vertical align mode
enum TEXT_ALIGN_VER
{
	TAV_UNKNOWN = -1,
	TAV_DEFAULT = 0,
	TAV_TOP = 1,
	TAV_BOTTOM = 2,
	TAV_CENTER = 3,
};

// foreground image horizontal align mode
enum FOREGROUND_ALIGN_HOR
{
	FAH_UNKNOWN = -1,
	FAH_CENTER,
	FAH_LEFT,
	FAH_RIGHT,
};

// foreground image vertical align mode
enum FOREGROUND_ALIGN_VER
{
	FAV_UNKNOWN = -1,
	FAV_CENTER,
	FAV_TOP,
	FAV_BOTTOM
};

// Control horizontal layout mode
enum CONTROL_LAYOUT_HOR
{
	CLH_UNKNOWN = -1,
	CLH_DEFAULT = 0,
	CLH_LEFT = 1,
	CLH_RIGHT = 2,
	CLH_CENTER = 3,
	CLH_FREE = 4
};

// Control vertical layout mode
enum CONTROL_LAYOUT_VER
{
	CLV_UNKNOWN = -1,
	CLV_DEFAULT = 0,
	CLV_TOP = 1,
	CLV_BOTTOM = 2,
	CLV_CENTER = 3,
	CLV_FREE = 4
};

enum BTN_TYPE
{
	BT_UNKNOWN = -1,
	BT_NORMAL,
	BT_MINIMIZEBOX,
	BT_CLOSEBOX
};

enum CHK_TYPE
{
	CT_UNKNOWN = -1,
	CT_NORMAL,
	CT_MAXIMIZEBOX
};

enum WINDOW_TYPE
{
	WT_UNKNOWN = -1,
	WT_NORMAL,
	WT_MDIFRAME,
	WT_MDICLIENT,
	WT_MDICHILDFRAME,
	WT_MDIVIEW
};

enum CMB_STYLE
{
	CS_UNKNOWN = -1,
	CS_SIMPLE = CBS_SIMPLE,
	CS_DROPDOWN = CBS_DROPDOWN,
	CS_DROPDOWNLIST = CBS_DROPDOWNLIST
};

enum SPN_ALIGN
{
	SPNA_UNKNOWN = -1,
	SPNA_UNATTACHED = 0,
	SPNA_LEFT = 1,
	SPNA_RIGHT = 2
};

enum SLD_EXT_STYLE
{
	SLDES_UNKNOWN = -1,
	SLDES_NORMAL = 0,
	SLDES_PROGRESS = 1,
	SLDES_SPLITPROGRESS = 2
};

enum LST_STYLE
{
	LSTS_UNKNOWN = -1,
	LSTS_ICON = 0,
	LSTS_SMALLICON = 1,
	LSTS_LIST = 2,
	LSTS_REPORT = 3,
	LSTS_THUMBNAIL = 4
};

enum LST_ALIGN
{
	LSTA_UNKNOWN = -1,
	LSTA_TOP = 0,
	LSTA_LEFT = 1
};

enum LST_SORT
{
	LSTST_UNKNOWN = -1,
	LSTST_UNSET,
	LSTST_ASCENDING = 1,
	LSTST_DESCENDING = 2
};

enum BACKGROUND_TYPE
{
	BKT_UNKNOWN = -1,
	BKT_IMAGE,
	BKT_COLOR
};

enum PROGRESS_THUMB_MODE
{
	PTM_UNKNOWN = -1,
	PTM_STRETCH,
	PTM_TILE
};

enum ALPHA_FORMAT
{
	AF_UNKNOWN = -1,
	AF_NONE,
	AF_AC_SRC_ALPHA
};

enum GRID_PANEL_UINT
{
	GPU_UNKNOWN = -1,
	GPU_PIXEL,
	GPU_PERCENT
};

enum MENU_BORDER_STYLE
{
	MBS_UNKNOWN = -1,
	MBS_NORMAL,			// has 3D-like border
	MBS_FLAT,			// has one pix border
	MBS_NONE			// has no border
};

//////////////////////////////////////////////////////////////////////////

enum STACK_PANEL_ORIENTATION
{
	SPO_UNKNOWN = -1,
	SPO_LEFT,
	SPO_TOP,
	SPO_RIGHT,
	SPO_BOTTOM,
	SPO_CENTER,
	SPO_VCENTER
};

enum GRID_ELEMENT_ALIGN_HOR
{
	GEAH_UNKNOWN = -1,
	GEAH_LEFT,
	GEAH_CENTER,
	GEAH_RIGHT,
	GEAH_STRETCH
};

enum GRID_ELEMENT_ALIGN_VER
{
	GEAV_UNKNOWN = -1,
	GEAV_TOP,
	GEAV_CENTER,
	GEAV_BOTTOM,
	GEAV_STRETCH
};

enum GRID_ELEMENT_TYPE
{
	GET_UNKNOWN = -1,
	GET_WINDOW,
	GET_PANEL
};

enum STACK_ELEMENT_TYPE
{
	SET_UNKNOWN = -1,
	SET_WINODW,
	SET_PANEL
};

//

enum RESOURCE_TYPE
{
	REST_FONT,
	REST_COLOR
};

enum STYLE_TYPE
{
	STYLET_PUSHBUTTON,
	STYLET_CHECK,
	STYLET_RADIO,
	STYLET_COMBOBOX,
	STYLET_STATIC,
	STYLET_EDIT,
	STYLET_SLIDER,
	STYLET_PROGRESS,
	STYLET_SPIN,
	STYLET_HOTKEY,
	STYLET_IPADDRESS,
	STYLET_SLIDEREX,
	STYLET_LISTCTRL,
	STYLET_TREECTRL,
	STYLET_TREELIST,
	STYLET_RICHEDIT,
	STYLET_HTMLCTRL,
	STYLET_DATETIMECTRL,
	STYLET_WAVECTRL,
	STYLET_MENU,
	STYLET_MENUBAR,
	STYLET_HEADERCTRL,
	STYLET_HORSCROLLBAR,
	STYLET_VERSCROLLBAR
};

enum CONTROL_STATE
{
	CS_NORMAL,
	CS_HIGHLIGHT,
	CS_SELECTED,
	CS_DISABLED
};

//////////////////////////////////////////////////////////////////////////
// 

enum VARENUMEX
{
	VT_EX_STRUCT_SIZE = VT_EMPTY+1,
	VT_EX_CONTROL_ID,
	VT_EX_CONTROL_TYPE,
	VT_EX_RECT,
	VT_EX_POINT,
	VT_EX_COLOR,
	VT_EX_FONT,
	VT_EX_BITMAPPATH,
	VT_EX_LAYOUT_HOR,
	VT_EX_LAYOUT_VER,
	VT_EX_TEXT_ALIGN_HOR,
	VT_EX_TEXT_ALIGN_VER,
	VT_EX_FOREGROUND_ALIGN_HOR,
	VT_EX_FOREGROUND_ALIGN_VER,
	VT_EX_BUTTON_TYPE,
	VT_EX_CHECKBOX_TYPE,
	VT_EX_WINDOW_TYPE,
	VT_EX_COMBOBOX_STYLE,
	VT_EX_SPN_ALIGN,
	VT_EX_SLD_EXT_STYLE,
	VT_EX_LST_STYLE,
	VT_EX_LST_ALIGN,
	VT_EX_LST_SORT,
	VT_EX_BACKGROUND_TYPE,
	VT_EX_PROGRESS_THUMB_MODE,
	VT_EX_ALPHA_FORMAT,
	VT_EX_MENU_BORDER_STYLE,
	// Resource
	VT_EX_RESOURCE_FONT,
	VT_EX_RESOURCE_COLOR,
	// Style
	VT_EX_STYLE_PUSHBUTTON,
	VT_EX_STYLE_CHECK,
	VT_EX_STYLE_RADIO,
	VT_EX_STYLE_COMBOBOX,
	VT_EX_STYLE_STATIC,
	VT_EX_STYLE_EDIT,
	VT_EX_STYLE_SLIDER,
	VT_EX_STYLE_PROGRESS,
	VT_EX_STYLE_SPIN,
	VT_EX_STYLE_HOTKEY,
	VT_EX_STYLE_IPADDRESS,
	VT_EX_STYLE_SLIDEREX,
	VT_EX_STYLE_LISTCTRL,
	VT_EX_STYLE_TREECTRL,
	VT_EX_STYLE_TREELIST,
	VT_EX_STYLE_RICHEDIT,
	VT_EX_STYLE_HTMLCTRL,
	VT_EX_STYLE_DATETIMECTRL,
	VT_EX_STYLE_WAVECTRL,
	VT_EX_STYLE_MENU,
	VT_EX_STYLE_MENUBAR,
	VT_EX_STYLE_HEADERCTRL,
	VT_EX_STYLE_HORSCROLLBAR,
	VT_EX_STYLE_VERSCROLLBAR
};


class IUI_VARIANT : public _variant_t
{
public:
	// Constructors
	//
	IUI_VARIANT() throw();

	IUI_VARIANT(const _variant_t& varSrc) ;
	IUI_VARIANT(const _variant_t* pSrc) ;
	IUI_VARIANT(const IUI_VARIANT& varSrc) ;

	IUI_VARIANT(_variant_t& varSrc, bool fCopy) ;          // Attach _variant_t if !fCopy

	IUI_VARIANT(short sSrc, VARTYPE vtSrc = VT_I2) ;    // Creates a VT_I2, or a VT_BOOL
	IUI_VARIANT(long lSrc, VARTYPE vtSrc = VT_I4) ;     // Creates a VT_I4, a VT_ERROR, or a VT_BOOL
	IUI_VARIANT(float fltSrc) throw();                                   // Creates a VT_R4
	IUI_VARIANT(double dblSrc, VARTYPE vtSrc = VT_R8) ; // Creates a VT_R8, or a VT_DATE
	IUI_VARIANT(const CY& cySrc) throw();                                // Creates a VT_CY
	IUI_VARIANT(const _bstr_t& bstrSrc) ;               // Creates a VT_BSTR
	IUI_VARIANT(const wchar_t *pSrc) ;                  // Creates a VT_BSTR
	IUI_VARIANT(const char* pSrc) ;                     // Creates a VT_BSTR
	IUI_VARIANT(IDispatch* pSrc, bool fAddRef = true) throw();           // Creates a VT_DISPATCH
	IUI_VARIANT(bool boolSrc) throw();                                   // Creates a VT_BOOL
	IUI_VARIANT(IUnknown* pSrc, bool fAddRef = true) throw();            // Creates a VT_UNKNOWN
	IUI_VARIANT(const DECIMAL& decSrc) throw();                          // Creates a VT_DECIMAL
	IUI_VARIANT(BYTE bSrc) throw();                                      // Creates a VT_UI1

#if(_MSC_VER > 1200) // VC6.0
	IUI_VARIANT(char cSrc) throw();                                      // Creates a VT_I1
	IUI_VARIANT(unsigned short usSrc) throw();                           // Creates a VT_UI2
	IUI_VARIANT(unsigned long ulSrc) throw();                            // Creates a VT_UI4
	IUI_VARIANT(int iSrc) throw();                                       // Creates a VT_INT
	IUI_VARIANT(unsigned int uiSrc) throw();                             // Creates a VT_UINT
#endif
#if (_WIN32_WINNT >= 0x0501)
	IUI_VARIANT(__int64 i8Src) throw();                                  // Creates a VT_I8
	IUI_VARIANT(unsigned __int64 ui8Src) throw();                        // Creates a VT_UI8
#endif
	IUI_VARIANT(RECT rcSrc) throw();
	IUI_VARIANT(POINT ptSrc) throw();
	IUI_VARIANT(LOGFONT lf) throw();
	IUI_VARIANT(CONTROL_LAYOUT_HOR eSrc) throw();
	IUI_VARIANT(CONTROL_LAYOUT_VER eSrc) throw();
	IUI_VARIANT(TEXT_ALIGN_HOR eSrc) throw();
	IUI_VARIANT(TEXT_ALIGN_VER eSrc) throw();
	IUI_VARIANT(FOREGROUND_ALIGN_HOR eSrc) throw();
	IUI_VARIANT(FOREGROUND_ALIGN_VER eSrc) throw();
	IUI_VARIANT(BTN_TYPE eSrc) throw();
	IUI_VARIANT(CHK_TYPE eSrc) throw();
	IUI_VARIANT(WINDOW_TYPE eSrc) throw();
	IUI_VARIANT(CMB_STYLE eSrc) throw();
	IUI_VARIANT(SPN_ALIGN eSrc) throw();
	IUI_VARIANT(SLD_EXT_STYLE eSrc) throw();
	IUI_VARIANT(LST_STYLE eSrc) throw();
	IUI_VARIANT(LST_ALIGN eSrc) throw();
	IUI_VARIANT(LST_SORT eSrc) throw();
	IUI_VARIANT(BACKGROUND_TYPE eSrc) throw();
	IUI_VARIANT(PROGRESS_THUMB_MODE eSrc) throw();
	IUI_VARIANT(ALPHA_FORMAT eSrc) throw();
	IUI_VARIANT(MENU_BORDER_STYLE eSrc) throw();

	// Destructor
	//
	~IUI_VARIANT() throw() ;

	// Extractors
	//
#if(_MSC_VER <= 1200) // VC6.0
	operator int() const throw();
#endif
	operator _variant_t() const throw();
	operator LPCWSTR() const throw();
	operator LPCSTR() const throw();
	operator RECT() const throw();
	operator CRect() const throw();
	operator POINT() const throw();
	operator COLORREF() const throw();
	operator LOGFONT() const throw();
	operator CONTROL_LAYOUT_HOR() const throw();
	operator CONTROL_LAYOUT_VER() const throw();
	operator TEXT_ALIGN_HOR() const throw();
	operator TEXT_ALIGN_VER() const throw();
	operator FOREGROUND_ALIGN_HOR() const throw();
	operator FOREGROUND_ALIGN_VER() const throw();
	operator BTN_TYPE() const throw();
	operator CHK_TYPE() const throw();
	operator WINDOW_TYPE() const throw();
	operator CMB_STYLE() const throw();
	operator SPN_ALIGN() const throw();
	operator SLD_EXT_STYLE() const throw();
	operator LST_STYLE() const throw();
	operator LST_ALIGN() const throw();
	operator LST_SORT() const throw();
	operator BACKGROUND_TYPE() const throw();
	operator PROGRESS_THUMB_MODE() const throw();
	operator ALPHA_FORMAT() const throw();
	operator MENU_BORDER_STYLE() const throw();

	// Assignment operations
	//
	IUI_VARIANT& operator=(const _variant_t& varSrc) ;
	IUI_VARIANT& operator=(const _variant_t* pSrc) ;
	IUI_VARIANT& operator=(const IUI_VARIANT& varSrc) ;

	IUI_VARIANT& operator=(short sSrc) ;                // Assign a VT_I2, or a VT_BOOL
	IUI_VARIANT& operator=(long lSrc) ;                 // Assign a VT_I4, a VT_ERROR or a VT_BOOL
	IUI_VARIANT& operator=(float fltSrc) ;              // Assign a VT_R4
	IUI_VARIANT& operator=(double dblSrc) ;             // Assign a VT_R8, or a VT_DATE
	IUI_VARIANT& operator=(const CY& cySrc) ;           // Assign a VT_CY
	IUI_VARIANT& operator=(const _bstr_t& bstrSrc) ;    // Assign a VT_BSTR
	IUI_VARIANT& operator=(const wchar_t* pSrc) ;       // Assign a VT_BSTR
	IUI_VARIANT& operator=(const char* pSrc) ;          // Assign a VT_BSTR
	IUI_VARIANT& operator=(IDispatch* pSrc) ;           // Assign a VT_DISPATCH
	IUI_VARIANT& operator=(bool boolSrc) ;              // Assign a VT_BOOL
	IUI_VARIANT& operator=(IUnknown* pSrc) ;            // Assign a VT_UNKNOWN
	IUI_VARIANT& operator=(const DECIMAL& decSrc) ;     // Assign a VT_DECIMAL
	IUI_VARIANT& operator=(BYTE bSrc) ;                 // Assign a VT_UI1

#if(_MSC_VER > 1200) // VC6.0
	IUI_VARIANT& operator=(char cSrc) ;                 // Assign a VT_I1
	IUI_VARIANT& operator=(unsigned short usSrc) ;      // Assign a VT_UI2
	IUI_VARIANT& operator=(unsigned long ulSrc) ;       // Assign a VT_UI4
	IUI_VARIANT& operator=(int iSrc) ;                  // Assign a VT_INT
	IUI_VARIANT& operator=(unsigned int uiSrc) ;        // Assign a VT_UINT
#endif
#if (_WIN32_WINNT >= 0x0501)
	IUI_VARIANT& operator=(__int64 i8Src) ;             // Assign a VT_I8
	IUI_VARIANT& operator=(unsigned __int64 ui8Src) ;   // Assign a VT_UI8
#endif
	IUI_VARIANT& operator=(const RECT &rcSrc);
	IUI_VARIANT& operator=(const POINT &ptSrc);
	IUI_VARIANT& operator=(const LOGFONT &lfSrc);
	IUI_VARIANT& operator=(CONTROL_LAYOUT_HOR eSrc);
	IUI_VARIANT& operator=(CONTROL_LAYOUT_VER eSrc);
	IUI_VARIANT& operator=(TEXT_ALIGN_HOR eSrc);
	IUI_VARIANT& operator=(TEXT_ALIGN_VER eSrc);
	IUI_VARIANT& operator=(FOREGROUND_ALIGN_HOR eSrc);
	IUI_VARIANT& operator=(FOREGROUND_ALIGN_VER eSrc);
	IUI_VARIANT& operator=(BTN_TYPE eSrc);
	IUI_VARIANT& operator=(CHK_TYPE eSrc);
	IUI_VARIANT& operator=(WINDOW_TYPE eSrc);
	IUI_VARIANT& operator=(CMB_STYLE eSrc);
	IUI_VARIANT& operator=(SPN_ALIGN eSrc);
	IUI_VARIANT& operator=(SLD_EXT_STYLE eSrc);
	IUI_VARIANT& operator=(LST_STYLE eSrc);
	IUI_VARIANT& operator=(LST_ALIGN eSrc);
	IUI_VARIANT& operator=(LST_SORT eSrc);
	IUI_VARIANT& operator=(BACKGROUND_TYPE eSrc);
	IUI_VARIANT& operator=(PROGRESS_THUMB_MODE eSrc);
	IUI_VARIANT& operator=(ALPHA_FORMAT eSrc);
	IUI_VARIANT& operator=(MENU_BORDER_STYLE eSrc);

	// Comparison operations
	//
	bool operator==(const _variant_t& varSrc) const throw();
	bool operator==(const _variant_t* pSrc) const throw();
	bool operator!=(const _variant_t& varSrc) const throw();
	bool operator!=(const _variant_t* pSrc) const throw();

	bool operator==(LPCTSTR lpszSrc) const throw();
	bool operator!=(LPCTSTR lpszSrc) const throw();


	// Low-level operations
	//
	void Init();
	void IUI_VARIANT_Copy(const IUI_VARIANT &varSrc);
	void IUI_VARIANT_Clear();
	_variant_t& GetVARIANT() throw();
	_variant_t* GetAddress() ;
	void SetString(const char* pSrc) ; // used to set ANSI string
	int SetPointX(LONG x);
	int SetPointY(LONG y);
	int SetRectLeft(LONG lLeft);
	int SetRectTop(LONG lTop);
	int SetRectWidth(LONG lWidth);
	int SetRectHeight(LONG lHeight);
	_bstr_t GetEnumString() const;
	int InitByEnumString(const CString &str);

	// For binding property
	int SetBindVariant(const IUI_VARIANT *pvarBind);
	const IUI_VARIANT *GetBindVariant() const;
	int RemoveBindVariant();
	int SetBindCompareValue(const IUI_VARIANT &var);
	const IUI_VARIANT GetBindCompareValue() const;

protected:
	mutable char *strA;
	IUI_VARIANT *pvarBind;
	IUI_VARIANT *pvarCompare;

public:
	VARTYPE vtEx;			// extended variant type. the value if enum VARENUMEX.
	bool bSaveToSkinFile;	// specifies the variable save to *.xui file or not.
	bool bNeedToConvert;	// specifies the variable is only valid in old version, it has been instead of by new property, it need to be convert to the new version.
	bool bReadOnly;
	_bstr_t strVarName;		// variable name
	_bstr_t strUIKeyName;			// key name in the.ui file
	_bstr_t strXUIElementName;		// element name in the.xui file
	_bstr_t strXUIAttributeName;	// attribute name in the.xui file
	bool bShowInPropertiesWnd;		// specifies the variable show in CPropertiesWnd or not. the following three variable is valid while bShowInPropertiesWnd is TRUE.
	bool bGroup;
	CString strGroupName;		// valid while bGroup is TRUE.
	CString strPropWndName;			// name in CPropertiesWnd
	CString strDescription;		// description of the variable
	CStringList lstStringOptions;		// options value of the variable
	int nMinValue;			// specifies the minimize value while vt is VT_I4 etc.
	int nMaxValue;			// specifies the maximize value while vt is VT_I4 etc.

	// Disabled while bind property is...
	// Disabled while bind property isn't ...
	bool bDisabledWhileBindIs;
	bool bDisabledWhileBindIsnot;
	long lBeBindCount;
};

//////////////////////////////////////////////////////////////////////////
// 

struct ITEMTEXTCOLOR
{
	int nItem;					// Item index for CListCtrl or item HANDLE for CTreeCtrl.
	int nSubItem;				// Subitem for CListCtrl, otherwise, not use.
	COLORREF crItemText;
};

//////////////////////////////////////////////////////////////////////////
//

#define GIF_TEXT                0x0001
#define GIF_POINTER             0x0002
#define GIF_PARAM               0x0004
#define GIF_ALL                 GIF_TEXT|GIF_POINTER|GIF_PARAM

class CGridItem
{
public:
	CGridItem();
	~CGridItem();

public:
	void SetText(const CString &strText);
	CString GetText() const;

	void SetPointer(void *pBuffer);
	void *GetPointer() const;

	void SetParam(LPARAM lParam);
	LPARAM GetParam() const;

public:
	UINT m_uMask;

private:
	CString m_strText;
	void *m_pBuffer;
	LPARAM m_lParam;
};

class CGrid
{
public:
	CGrid();
	~CGrid();

public:
	// for header
	int InsertColumn(int nCol, const CString &strColumnHeading = _T(""));
	BOOL DeleteColumn(int nCol);

	int GetColumnCount() const;

	BOOL SetColumn(int nCol, const CGridItem *pColumn);
	BOOL GetColumn(int nCol, CGridItem *pColumn) const;

	BOOL SetColumnText(int nCol, const CString &strColumn);
	BOOL GetColumnText(int nCol, CString *pstrColumn) const;

	BOOL SetColumnPointer(int nCol, void *pBuffer);
	void *GetColumnPointer(int nCol) const;

	BOOL SetColumnData(int nCol, LPARAM lParam);
	LPARAM GetColumnData(int nCol) const;

	BOOL SwapColumn(int nFirst, int nSecond);

	// for item
	int InsertItem(int nItem, LPCTSTR lpszItem);
	BOOL DeleteItem(int nItem);
	BOOL DeleteAllItems();

	int GetItemCount() const;

	BOOL SetItem(int nItem, int nSubItem, const CGridItem *pItem);
	BOOL GetItem(int nItem, int nSubItem, CGridItem *pItem) const;

	BOOL SetItemText(int nItem, int nSubItem, const CString &strText);
	CString GetItemText(int nItem, int nSubItem) const;

	BOOL SetItemPointer(int nItem, int nSubItem, void *pBuffer);
	void *GetItemPointer(int nItem, int nSubItem) const;

	BOOL SetItemData(int nItem, int nSubItem, LPARAM lParam);
	LPARAM GetItemData(int nItem, int nSubItem) const;

	BOOL SortItems(PFNLVCOMPARE pfnCompare, DWORD dwData);
	int FindItem(LV_FINDINFO* pFindInfo, int nStart = -1) const;
	BOOL SwapItem(int nFirst, int nSecond);

	// Check column or item valid
	BOOL IsColumnValid(int nCol) const;
	BOOL IsItemValid(int nItem, int nSubItem) const;

private:
	std::vector<CGridItem> m_vHeader;
	std::vector<std::vector<CGridItem> > m_vvData;
};

//////////////////////////////////////////////////////////////////////////

struct IUI_LOGFONT : public LOGFONT
{
	IUI_LOGFONT();
	IUI_LOGFONT(const LOGFONT &lf);
	IUI_LOGFONT(const IUI_LOGFONT &lf);
	virtual ~IUI_LOGFONT();

	IUI_LOGFONT &operator=(const LOGFONT &lf);
	IUI_LOGFONT &operator=(const IUI_LOGFONT &lf);
};

//////////////////////////////////////////////////////////////////////////

struct CTRLPROPERTIES
{
	CTRLPROPERTIES();
	virtual ~CTRLPROPERTIES();

	virtual LONG GetPropertyCount() const;
	IUI_VARIANT *GetVariant(int nIndex);
	const IUI_VARIANT *GetVariant(int nIndex) const;

	static CString GetIDPrefix(LPCTSTR lpszType);
	CString GetClassName() const;
	CString GetVariablePrefix() const;
	CString GetVariableName() const;

	// disable some properties
	int DisableBackgroundProperties(BOOL bOnlyHighlightSelected);
	int DisableFontProperties(BOOL bOnlyHighlightSelected);
	int DisableTextColorProperties(BOOL bOnlyHighlightSelected);

	// Scroll bar
	virtual bool IsEnableCustomScrollBar() const;

	// Resource
	virtual bool IsFontResource() const;
	virtual bool IsColorResource() const;

	IUI_VARIANT lStructSize;
	IUI_VARIANT strType;
	IUI_VARIANT strID;
	IUI_VARIANT rect;
	IUI_VARIANT bVisible;
	IUI_VARIANT bDisabled;
	IUI_VARIANT bTabStop;
	IUI_VARIANT bClipChildren;
	IUI_VARIANT bClipSiblings;
	IUI_VARIANT eHorLayoutMode;
	IUI_VARIANT eVerLayoutMode;

	IUI_VARIANT bCanBackgroundStateChange;	// FALSE: The highlight, selected and disabled background image use normal background image.
		IUI_VARIANT bSpecifyBackgroundImages;
			IUI_VARIANT bCombineBackgroundImages;
				IUI_VARIANT strBKCombine;
				IUI_VARIANT strBKN;
				IUI_VARIANT strBKH;
				IUI_VARIANT strBKS;
				IUI_VARIANT strBKD;
				IUI_VARIANT ptResize;


	// For compatible old version of *.xui.
	IUI_VARIANT lfN;
	IUI_VARIANT lfH;
	IUI_VARIANT lfS;
	IUI_VARIANT lfD;

	IUI_VARIANT strResFontIDN;
	IUI_VARIANT bHSameNFont;		// the font of Highlight state same to normal
	IUI_VARIANT strResFontIDH;
	IUI_VARIANT bSSameNFont;
	IUI_VARIANT strResFontIDS;
	IUI_VARIANT bDSameNFont;
	IUI_VARIANT strResFontIDD;

	IUI_VARIANT crN;
	IUI_VARIANT crH;
	IUI_VARIANT crS;
	IUI_VARIANT crD;

	IUI_VARIANT strResColorIDN;
	IUI_VARIANT bHSameNColor;
	IUI_VARIANT strResColorIDH;
	IUI_VARIANT bSSameNColor;
	IUI_VARIANT strResColorIDS;
	IUI_VARIANT bDSameNColor;
	IUI_VARIANT strResColorIDD;
};

struct RECTPROPERTIES : public CTRLPROPERTIES
{
	RECTPROPERTIES();
	virtual ~RECTPROPERTIES();
};

// Horizontal scroll bar
struct HORSBPROPERTIES : public CTRLPROPERTIES
{
	HORSBPROPERTIES();
	virtual ~HORSBPROPERTIES();

	IUI_VARIANT bCombineThumbImages;
	IUI_VARIANT strThumbCombine;
	IUI_VARIANT strThumbN;
	IUI_VARIANT strThumbH;
	IUI_VARIANT strThumbS;
	IUI_VARIANT strThumbD;
	IUI_VARIANT ptThumbResize;

	IUI_VARIANT nLeftButtonWidth;
	IUI_VARIANT nRightButtonWidth;
};

// Vertical scroll bar
struct VERSBPROPERTIES : public CTRLPROPERTIES
{
	VERSBPROPERTIES();
	virtual ~VERSBPROPERTIES();

	IUI_VARIANT bCombineThumbImages;
	IUI_VARIANT strThumbCombine;
	IUI_VARIANT strThumbN;
	IUI_VARIANT strThumbH;
	IUI_VARIANT strThumbS;
	IUI_VARIANT strThumbD;
	IUI_VARIANT ptThumbResize;

	IUI_VARIANT nUpButtonHeight;
	IUI_VARIANT nDownButtonHeight;
};

struct BTNBASEPROPERTIES : public CTRLPROPERTIES
{
	BTNBASEPROPERTIES();
	virtual ~BTNBASEPROPERTIES();

	IUI_VARIANT bR2LReadOrder;
	IUI_VARIANT bMultiline;
	IUI_VARIANT bEndEllipsis;		// only valid while bMultiline is FALSE

	IUI_VARIANT	strCaption;
	IUI_VARIANT strTag;
	IUI_VARIANT strMaskBmp;

	IUI_VARIANT bUseToolTip;
	IUI_VARIANT strToolTip;

	IUI_VARIANT eTextHorAlignMode;
	IUI_VARIANT lHorAlign;
	IUI_VARIANT eTextVerAlignMode;
	IUI_VARIANT lVerAlign;

	IUI_VARIANT bSpecifyForegroundImages;
		IUI_VARIANT eForegroundHorAlignMode;
		IUI_VARIANT	lForegroundHorAlign;
		IUI_VARIANT eForegroundVerAlignMode;
		IUI_VARIANT	lForegroundVerAlign;
		IUI_VARIANT bCombineForegroundImages;
			IUI_VARIANT strFGCombine;
			IUI_VARIANT strFGN;
			IUI_VARIANT strFGH;
			IUI_VARIANT strFGS;
			IUI_VARIANT strFGD;
};

struct BTNPROPERTIES : public BTNBASEPROPERTIES
{
	BTNPROPERTIES();
	virtual ~BTNPROPERTIES();

	IUI_VARIANT eBtnType;
	IUI_VARIANT bDefPushButton;
};

struct TOGGLEBTNPROPERTIES : public BTNBASEPROPERTIES
{
	TOGGLEBTNPROPERTIES();
	virtual ~TOGGLEBTNPROPERTIES();

	IUI_VARIANT strBKCN;
	IUI_VARIANT strBKCH;
	IUI_VARIANT strBKCS;
	IUI_VARIANT strBKCD;
	IUI_VARIANT strFGCN;
	IUI_VARIANT strFGCH;
	IUI_VARIANT strFGCS;
	IUI_VARIANT strFGCD;
};

struct CHKPROPERTIES : public TOGGLEBTNPROPERTIES
{
	CHKPROPERTIES();
	virtual ~CHKPROPERTIES();

	IUI_VARIANT eChkType;
};

struct RADPROPERTIES : public TOGGLEBTNPROPERTIES
{
	RADPROPERTIES();
	virtual ~RADPROPERTIES();

	IUI_VARIANT bGroup;
};

struct TXTPROPERTIES : public CTRLPROPERTIES
{
	TXTPROPERTIES();
	virtual ~TXTPROPERTIES();

	IUI_VARIANT bR2LReadOrder;
	IUI_VARIANT bNoWrap;
		IUI_VARIANT bPathEllipsis; // only valid while bNoWrap is TRUE.
		IUI_VARIANT bEndEllipsis;	// only valid while bNoWrap is TRUE.

	IUI_VARIANT strCaption;

	// 
	IUI_VARIANT bSpecifyForegroundImages;
		IUI_VARIANT eForegroundHorAlignMode;
		IUI_VARIANT	lForegroundHorAlign;
		IUI_VARIANT eForegroundVerAlignMode;
		IUI_VARIANT	lForegroundVerAlign;
		IUI_VARIANT bCombineForegroundImages;
			IUI_VARIANT strFGCombine;
			IUI_VARIANT strFGN;
			IUI_VARIANT strFGD;

	// Tooltip
	IUI_VARIANT bUseToolTip;
		IUI_VARIANT strToolTip;

	// alignment
	IUI_VARIANT eTextHorAlignMode;
		IUI_VARIANT lHorAlign;
	IUI_VARIANT eTextVerAlignMode;
		IUI_VARIANT lVerAlign;
};

struct EDTPROPERTIES : public CTRLPROPERTIES
{
	EDTPROPERTIES();
	virtual ~EDTPROPERTIES();

	IUI_VARIANT bBorder;
	IUI_VARIANT bHScroll;
	IUI_VARIANT bVScroll;
	IUI_VARIANT bAutoHScroll;
	IUI_VARIANT bAutoVScroll;
	IUI_VARIANT bDisableNoScroll; // For Rich Edit
	IUI_VARIANT bLowercase;
	IUI_VARIANT bUppercase;
	IUI_VARIANT bNumber;
	IUI_VARIANT bPassword;
	IUI_VARIANT bReadOnly;
	IUI_VARIANT bMultiline;
	IUI_VARIANT bWantReturn;
	IUI_VARIANT bR2LReadOrder;

	IUI_VARIANT strTag;

	// Text Alignment
	IUI_VARIANT eTextHorAlignMode;
		IUI_VARIANT lHorAlign;
	IUI_VARIANT lVerAlign;
};

struct RICHEDITPROPERTIES : public EDTPROPERTIES
{
	RICHEDITPROPERTIES();
	virtual ~RICHEDITPROPERTIES();
};

struct CMBPROPERTIES : public CTRLPROPERTIES
{
	CMBPROPERTIES();
	virtual ~CMBPROPERTIES();

	IUI_VARIANT eComboStyle;
	IUI_VARIANT bVScroll;
	IUI_VARIANT bAutoHScroll;
	IUI_VARIANT bDisableNoScroll;
	IUI_VARIANT bSort;
	IUI_VARIANT bUppercase;
	IUI_VARIANT bLowercase;
	IUI_VARIANT lHorAlign;
	IUI_VARIANT lVerAlign;
	IUI_VARIANT lItemHeight;
	IUI_VARIANT lDropListHeight;
	IUI_VARIANT lBtnWidth;
	IUI_VARIANT strTag;
};

struct SPNPROPERTIES : public CTRLPROPERTIES
{
	SPNPROPERTIES();
	virtual ~SPNPROPERTIES();

	IUI_VARIANT eAlignMode;
	IUI_VARIANT bVertical;
	IUI_VARIANT bAutoBuddy;
	IUI_VARIANT bSetBuddyInt;
	IUI_VARIANT bNoThousands;
	IUI_VARIANT bWrap;
	IUI_VARIANT bArrowKeys;
	IUI_VARIANT bHotTrack;
};

struct SLDPROPERTIES : public CTRLPROPERTIES
{
	SLDPROPERTIES();
	virtual ~SLDPROPERTIES();

	IUI_VARIANT eExtendedStyle;
	IUI_VARIANT bVertical;
	IUI_VARIANT bUseToolTip;
	IUI_VARIANT bUseMark;

	// Thumb Images
	IUI_VARIANT bCombineThumbImages;
	IUI_VARIANT strThumbCombine;
	IUI_VARIANT strThumbN;
	IUI_VARIANT strThumbH;
	IUI_VARIANT strThumbS;
	IUI_VARIANT strThumbD;

	// Show tip window
	IUI_VARIANT bEnableTipWindow;
	IUI_VARIANT sizeTipWindowOffset;
};

struct SLDEXPROPERTIES : public SLDPROPERTIES
{
	SLDEXPROPERTIES();
	virtual ~SLDEXPROPERTIES();
};

struct PRGPROPERTIES : public CTRLPROPERTIES
{
	PRGPROPERTIES();
	virtual ~PRGPROPERTIES();

	IUI_VARIANT bVertical;

	// Progress images
	IUI_VARIANT eThumbMode;		// PROGRESS_THUMB_MODE
	IUI_VARIANT bCombineThumbImages;
	IUI_VARIANT strThumbCombine;
	IUI_VARIANT strThumbN;
	IUI_VARIANT strThumbD;

	// Show percent text
	IUI_VARIANT bShowText;
		IUI_VARIANT lHorAlignN;
		IUI_VARIANT lVerAlignN;
};

struct HOTPROPERTIES : public CTRLPROPERTIES
{
	HOTPROPERTIES();
	virtual ~HOTPROPERTIES();
};

struct IPAPROPERTIES : public CTRLPROPERTIES
{
	IPAPROPERTIES();
	virtual ~IPAPROPERTIES();
};

struct LSTCTRLPROPERTIES : public CTRLPROPERTIES
{
	LSTCTRLPROPERTIES();
	virtual ~LSTCTRLPROPERTIES();

	virtual bool IsEnableCustomScrollBar() const;

	// General
	IUI_VARIANT bBorder;
	IUI_VARIANT eListStyle;
	IUI_VARIANT eListSort;
	IUI_VARIANT bEditLabels;
	IUI_VARIANT bShowSelAlways;
	IUI_VARIANT bSingleSel;
		IUI_VARIANT bHoldCtrlKey;	// Only valid while bSingleSel is false.
	IUI_VARIANT bCheckBoxes;
	IUI_VARIANT bInfoTooltip;
	IUI_VARIANT bTrackSelect;
	IUI_VARIANT bTwoClickActivate;
	IUI_VARIANT bEnableOwnerDraw;
	IUI_VARIANT bDragDrop;
	IUI_VARIANT strTag;

	// Only for report style
	IUI_VARIANT bFullRowSelect;
	IUI_VARIANT bSubItemImages;

	// Icon and small icon view
	IUI_VARIANT eListAlign;
	IUI_VARIANT bAutoArrange;	// for icon and small icon view
	IUI_VARIANT bNoScroll;		// This style is not compatible with the LVS_LIST or LVS_REPORT styles
	IUI_VARIANT bNoLabelWrap;	// for icon view

	// Grid line
	IUI_VARIANT bShowGridLine;
	IUI_VARIANT crGridLine;

	// Normal Item
	IUI_VARIANT bEnableNormalItemEffect;
	IUI_VARIANT eNormalItemBkType;
	IUI_VARIANT strNormalItemBkColorResID;
	IUI_VARIANT strNormalItemBkImage;
	IUI_VARIANT ptNormalItemBkResize;

	// Highlight Item
	IUI_VARIANT bEnableHighlightItemEffect;
	IUI_VARIANT eHighlightItemBkType;
	IUI_VARIANT strHighlightItemBkColorResID;
	IUI_VARIANT strHighlightItemBkImage;
	IUI_VARIANT ptHighlightItemBkResize;

	// Selected Item
	IUI_VARIANT bSelectedFitClient;		// Only valid while list with report style
	IUI_VARIANT eSelectedItemBkType;
	IUI_VARIANT strSelectedItemBkColorResID;
	IUI_VARIANT strSelectedItemBkImage;
	IUI_VARIANT ptSelectedItemBkResize;

	// Normal and Disabled Item
	IUI_VARIANT bEnableNormalDisabledItemEffect;
	IUI_VARIANT eNormalDisabledItemBkType;
	IUI_VARIANT strNormalDisabledItemBkColorResID;
	IUI_VARIANT strNormalDisabledItemBkImage;
	IUI_VARIANT ptNormalDisabledItemBkResize;

	// Selected and Disabled Item
	IUI_VARIANT bEnableSelectedDisabledItemEffect;
	IUI_VARIANT eSelectedDisabledItemBkType;
	IUI_VARIANT strSelectedDisabledItemBkColorResID;
	IUI_VARIANT strSelectedDisabledItemBkImage;
	IUI_VARIANT ptSelectedDisabledItemBkResize;
	IUI_VARIANT bSDSameNFont;
	IUI_VARIANT strResFontIDSD;
	IUI_VARIANT bSDSameNColor;
	IUI_VARIANT strResColorIDSD;

	// Thumbnail view
	IUI_VARIANT lTotalItemWidth;
	IUI_VARIANT lTotalItemHeight;

	// Thumbnail Background Position
	IUI_VARIANT rcThumbnailBkN;
	IUI_VARIANT rcThumbnailBkH;
	IUI_VARIANT rcThumbnailBkS;
	IUI_VARIANT rcThumbnailBkD;

	// Thumbnail Position
	IUI_VARIANT rcThumbnailN;
	IUI_VARIANT rcThumbnailH;
	IUI_VARIANT rcThumbnailS;
	IUI_VARIANT rcThumbnailD;

	// Thumbnail Label Position
	IUI_VARIANT rcThumbnailLabelN;
	IUI_VARIANT rcThumbnailLabelH;
	IUI_VARIANT rcThumbnailLabelS;
	IUI_VARIANT rcThumbnailLabelD;

	// Thumbnail Icon Position
	IUI_VARIANT rcThumbnailIconN;
	IUI_VARIANT rcThumbnailIconH;
	IUI_VARIANT rcThumbnailIconS;
	IUI_VARIANT rcThumbnailIconD;

	// Header
	IUI_VARIANT bNoHeader;
	IUI_VARIANT bNoSortHeader;
	IUI_VARIANT nHeaderHeight;
	IUI_VARIANT bHeaderDragDrop;
	IUI_VARIANT strHeaderStyleID;

	// Custom scroll bar
	IUI_VARIANT bUseCustomScrollBar;
	IUI_VARIANT strHorScrollbarID;
	IUI_VARIANT strVerScrollbarID;
};

struct TREECTRLPROPERTIES : public CTRLPROPERTIES
{
	TREECTRLPROPERTIES();
	virtual ~TREECTRLPROPERTIES();

	virtual bool IsEnableCustomScrollBar() const;

	IUI_VARIANT bBorder;
	IUI_VARIANT bCheckBoxes;
	IUI_VARIANT bHasButtons;
	IUI_VARIANT bHasLines;
	IUI_VARIANT bLinesAtRoot;
	IUI_VARIANT bFullRowSel;
	IUI_VARIANT bShowSelAlways;
	IUI_VARIANT bDisableDragDrop;
	IUI_VARIANT bEditLabels;
	IUI_VARIANT bScroll;
	IUI_VARIANT bNonEvenHeight;
	IUI_VARIANT bSingleExpand;
	IUI_VARIANT bTrackSel;
	IUI_VARIANT bInfoTip;
	IUI_VARIANT bToolTips;
	IUI_VARIANT bDefaultItemHeight;
	IUI_VARIANT nItemHeight;

	// Item Line
	IUI_VARIANT bEnableItemLine;
	IUI_VARIANT crItemLine;
	IUI_VARIANT strItemLineColorResID;

	// Selected Item
	IUI_VARIANT eSelectedItemBkType;
	IUI_VARIANT crSelectedItemBkColor;
	IUI_VARIANT strSelectedItemBkColorResID;
	IUI_VARIANT strSelectedItemBkImageN;
	IUI_VARIANT strSelectedItemBkImageD;
	IUI_VARIANT ptSelectedItemBkResize;

	// Highlight Item
	IUI_VARIANT bEnableHighlightItem;
	IUI_VARIANT eHighlightItemBkType;
	IUI_VARIANT crHighlightItemBkColor;
	IUI_VARIANT strHighlightItemBkColorResID;
	IUI_VARIANT strHighlightItemBkImageN;
	IUI_VARIANT strHighlightItemBkImageD;
	IUI_VARIANT ptHighlightItemBkResize;

	// Custom scroll bar
	IUI_VARIANT bUseCustomScrollBar;
	IUI_VARIANT strHorScrollbarID;
	IUI_VARIANT strVerScrollbarID;
};

struct SBPROPERTIES : public CTRLPROPERTIES
{
	SBPROPERTIES();
	virtual ~SBPROPERTIES();

	IUI_VARIANT bVertical;
	IUI_VARIANT strHorScrollbarStyleID;
	IUI_VARIANT strVerScrollbarStyleID;
};

struct SBEXPROPERTIES : public SBPROPERTIES
{
	SBEXPROPERTIES();
	virtual ~SBEXPROPERTIES();
};

struct THMPROPERTIES : public CTRLPROPERTIES
{
	THMPROPERTIES();
	virtual ~THMPROPERTIES();

	virtual bool IsEnableCustomScrollBar() const;

	IUI_VARIANT bListStyle;
	IUI_VARIANT bHoldCtrlKey;
	IUI_VARIANT bDragDrop;

	IUI_VARIANT lTotalItemWidth;
	IUI_VARIANT lTotalItemHeight;

	IUI_VARIANT lThumbnailLeftN;
	IUI_VARIANT lThumbnailTopN;
	IUI_VARIANT lThumbnailRightN;
	IUI_VARIANT lThumbnailBottomN;

	IUI_VARIANT lThumbnailLeftH;
	IUI_VARIANT lThumbnailTopH;
	IUI_VARIANT lThumbnailRightH;
	IUI_VARIANT lThumbnailBottomH;

	IUI_VARIANT lLabelLeftN;
	IUI_VARIANT lLabelTopN;
	IUI_VARIANT lLabelRightN;
	IUI_VARIANT lLabelBottomN;

	IUI_VARIANT lLabelLeftH;
	IUI_VARIANT lLabelTopH;
	IUI_VARIANT lLabelRightH;
	IUI_VARIANT lLabelBottomH;

	IUI_VARIANT strItemBkN;
	IUI_VARIANT strItemBkH;
	IUI_VARIANT strItemBkS;
	IUI_VARIANT strItemBkD;

	// Custom scroll bar
	IUI_VARIANT bEnableScrollBar;
	IUI_VARIANT strVerScrollbarID;
};

struct TREELISTPROPERTIES : public CTRLPROPERTIES
{
	TREELISTPROPERTIES();
	virtual ~TREELISTPROPERTIES();

	IUI_VARIANT bVariableItemHeight;
};

struct HTMLCTRLPROPERTIES : public CTRLPROPERTIES
{
	HTMLCTRLPROPERTIES();
	virtual ~HTMLCTRLPROPERTIES();

	IUI_VARIANT bHideBorder;
	IUI_VARIANT bHideScrollBar;
	IUI_VARIANT bHideContextMenu;
	IUI_VARIANT strStartPage;
};

struct DATETIMECTRLPROPERTIES : public CTRLPROPERTIES
{
	DATETIMECTRLPROPERTIES();
	virtual ~DATETIMECTRLPROPERTIES();
};

struct WAVECTRLPROPERTIES : public CTRLPROPERTIES
{
	WAVECTRLPROPERTIES();
	virtual ~WAVECTRLPROPERTIES();

	IUI_VARIANT bEnableDragMove;

	// Grid
	IUI_VARIANT lGridWidth;
	IUI_VARIANT lGridHeight;
	IUI_VARIANT crGridLine;
	IUI_VARIANT strGridLineColorResID;
	IUI_VARIANT lGridUnitX;
	IUI_VARIANT lGridUnitY;

	// Info area
	IUI_VARIANT lInfoAreaWidth;
	IUI_VARIANT lInfoAreaHeight;

	// Background
	IUI_VARIANT crBackground;
	IUI_VARIANT strBackgroundColorResID;
};

struct RESMENUPROPERTIES : public CTRLPROPERTIES
{
	RESMENUPROPERTIES();
	virtual ~RESMENUPROPERTIES();

	// Normal item
	IUI_VARIANT crNormalItemText;
	IUI_VARIANT lfNormalItemText;
	IUI_VARIANT eNormalItemBkType;
		IUI_VARIANT crNormalItemBkColor;
		IUI_VARIANT strNormalItemBkImage;
			IUI_VARIANT ptNormalItemBkResize;

	// Highlight item
	IUI_VARIANT crHighlightItemText;
	IUI_VARIANT lfHighlightItemText;
	IUI_VARIANT eHighlightItemBkType;
		IUI_VARIANT crHighlightItemBkColor;
		IUI_VARIANT strHighlightItemBkImage;
			IUI_VARIANT ptHighlightItemBkResize;

	// Disabled item
	IUI_VARIANT crDisabledItemText;
	IUI_VARIANT lfDisabledItemText;
	IUI_VARIANT eDisabledItemBkType;
		IUI_VARIANT crDisabledItemBkColor;
		IUI_VARIANT strDisabledItemBkImage;
			IUI_VARIANT ptDisabledItemBkResize;

	// Separator
	IUI_VARIANT eSeparatorBkType;
		IUI_VARIANT crSeparator;
			IUI_VARIANT nSeparatorLeftMargin;
			IUI_VARIANT nSeparatorRightMargin;
		IUI_VARIANT strSeparatorBkImage;
			IUI_VARIANT ptSeparatorBkImageResize;

	// Icon area
	IUI_VARIANT nIconAreaWidth;
	IUI_VARIANT crIconAreaStart;
	IUI_VARIANT crIconAreaEnd;

	// Border
	IUI_VARIANT eMenuBorderStyle;
	IUI_VARIANT crFlatMenuBorder;

	// Height of Menu item
	IUI_VARIANT nMenuItemHeight;
};

struct MENUBARPROPERTIES : public CTRLPROPERTIES
{
	MENUBARPROPERTIES();
	virtual ~MENUBARPROPERTIES();

	IUI_VARIANT strMenuStyleID;
};

struct UIWNDPROPERTIES : public CTRLPROPERTIES
{
	UIWNDPROPERTIES ();
	virtual ~UIWNDPROPERTIES();

	IUI_VARIANT bNoActivate;
	IUI_VARIANT bAppWindow;
	IUI_VARIANT bLayeredWindow;
		IUI_VARIANT bAlpha;
			IUI_VARIANT btAlphaValue;
		IUI_VARIANT bUpdateLayeredWindow;
			IUI_VARIANT eAlphaFormat;	// ALPHA_FORMAT
	IUI_VARIANT bTopmost;
	IUI_VARIANT bAcceptFiles;
	IUI_VARIANT bToolWindow;
	IUI_VARIANT lTitleBarHeight;	// -1: All area of window can be drag to move; 0: window can't be moved; >0: the height of title bar.
	IUI_VARIANT strBKNo;

	// 
	IUI_VARIANT bUseMaskColor;
		IUI_VARIANT crMask;
		IUI_VARIANT strMaskColorResID;

	// 
	IUI_VARIANT bResize;
		IUI_VARIANT bResizingBorder;
		IUI_VARIANT ptResize;
		IUI_VARIANT uXRepeatPixel;
		IUI_VARIANT uYRepeatPixel;

	//
	IUI_VARIANT eWindowType;
	IUI_VARIANT rcClientArea;	// can auto resize by windows resizing relative to ptResize.

	std::vector<CTRLPROPERTIES *> vControls;
};

//////////////////////////////////////////////////////////////////////////
// Resource properties

struct RESFONTPROPERTIES : public CTRLPROPERTIES
{
	RESFONTPROPERTIES();
	virtual ~RESFONTPROPERTIES();

	virtual bool IsFontResource() const;

	IUI_VARIANT logFont;
};

struct RESCOLORPROPERTIES : public CTRLPROPERTIES
{
	RESCOLORPROPERTIES();
	virtual ~RESCOLORPROPERTIES();

	virtual bool IsColorResource() const;

	IUI_VARIANT crColor;
};

struct RESHEADERPROPERTIES : public CTRLPROPERTIES
{
	RESHEADERPROPERTIES();
	virtual ~RESHEADERPROPERTIES();

	// Header Background
	IUI_VARIANT strHeaderBk;				// If Specify header button image, this variable is ignore.
	IUI_VARIANT ptHeaderBkImageResize;
};

//////////////////////////////////////////////////////////////////////////
// 

struct MENU_ITEM_PROPERTIES
{
	MENU_ITEM_PROPERTIES()
	{
		// Text
		m_crItemText = RGB(0, 0, 0);
		memset(&m_lfItem, 0, sizeof(LOGFONT));

		// Background
		m_eBackgroundType = BKT_COLOR;
			m_crItemBk = RGB(249, 248, 247);
			m_hItemBk = NULL;
				m_ptItemResize.x = 20;
				m_ptItemResize.y = 2;
	}

	virtual ~MENU_ITEM_PROPERTIES()
	{
		// the m_pfItem and m_hItemBk are shared, don't release theme.
	}

	// Text
	COLORREF m_crItemText;
	LOGFONT m_lfItem;

	// Background
	BACKGROUND_TYPE m_eBackgroundType;
		COLORREF m_crItemBk;
		BITMAPOBJ m_hItemBk;
			CPoint m_ptItemResize;
};

struct MENUMEMBER
{
	MENUMEMBER()
	{
		// Border
		m_eMbs = MBS_FLAT;
		m_crFlatMenuBorder = RGB(102, 102, 102);

		// Height of Menu Item
		m_nItemHeight = 23;

		// Highlight menu item
		m_HighlightItemProp.m_crItemText = RGB(255, 255, 255);
		m_HighlightItemProp.m_crItemBk = RGB(10, 36, 106);

		// Disabled menu item
		m_DisabledItemProp.m_crItemText = RGB(166, 166, 166);

		m_eSeparatorBkType = BKT_COLOR;
		m_crSeparator = RGB(166, 166, 166);
		m_nSeparatorLeftMargin = 2;
		m_nSeparatorRightMargin = 2;
		m_hSeparator = NULL;
		m_ptSeparatorResize = CPoint(20, 2);

		// Side bar
		m_crSideBarStart = RGB(0, 0, 192);
		m_crSideBarEnd = RGB(0, 0, 0);

		// Icon area
		m_nIconAreaWidth = 22;
		m_crIconAreaStart = RGB(249, 248, 247);
		m_crIconAreaEnd = RGB(215, 212, 204);

		// 
		m_bBreak = false;
		m_bBreakBar = false;
	}

	virtual ~MENUMEMBER()
	{

	}

	// Border
	MENU_BORDER_STYLE m_eMbs;
	COLORREF m_crFlatMenuBorder;	// Only valid while m_eMbs is MBS_FLAT.

	// Height of menu item
	int m_nItemHeight;

	// Menu item properties
	MENU_ITEM_PROPERTIES m_NormalItemProp;
	MENU_ITEM_PROPERTIES m_HighlightItemProp;
	MENU_ITEM_PROPERTIES m_DisabledItemProp;

	// Separator line properties
	BACKGROUND_TYPE m_eSeparatorBkType;
		COLORREF m_crSeparator;
			int m_nSeparatorLeftMargin;
			int m_nSeparatorRightMargin;
		BITMAPOBJ m_hSeparator;
			CPoint m_ptSeparatorResize;

	// Draw the left sidebar, like 'Start menu'.
	COLORREF m_crSideBarStart;	// Start color of the gradient sidebar bottom side
	COLORREF m_crSideBarEnd;	// end color of the gradient sidebar top side

	// Icon area
	int m_nIconAreaWidth;
	COLORREF m_crIconAreaStart;		// Background color of the button(icon) area left side
	COLORREF m_crIconAreaEnd;		// Background color of the button(icon) area right side

	BOOL m_bBreak;		//if true, next item inserted into the menu will be added with the style MF_MENUBREAK
	BOOL m_bBreakBar;	//if true, next item inserted into the menu will be added with the style MF_MENUBARBREAK
};

//////////////////////////////////////////////////////////////////////////
// Globals

int BackgroundMask(CWnd *pWnd, CString szMaskBitmap, COLORREF crMask);
int BackgroundMask(CWnd *pWnd, BITMAPOBJ hBmpMask, COLORREF crMask);

void TransparentBlt2(HDC hdcDest, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc, UINT crTransparent);
BOOL TileBlt(HDC hdcDest, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc);
int SubBitmap(BITMAPOBJ hSrcBmp, BITMAPOBJ &hDstBmp, int nX, int nY, int nWidth, int nHeight);
int SubBitmap(BITMAPOBJ hSrcBmp, BITMAPOBJ &hDstBmp, const CRect &rcSub);
int StretchBitmap(HBITMAP hSrcBmp, HBITMAP *phDstBmp, int nResizingX, int nResizingY, int nDstWidth, int nDstHeight, int nTilePixelX=1, int nTilePixelY=1);
int StretchBitmap(HBITMAP hSrcBmp, HBITMAP *phDstBmp, int nDstWidth, int nDstHeight);
int AutoStretchControlBk(HDC hdcDest, int nDstX, int nDstY, int nDstWidth, int nDstHeight, HBITMAP hSrcBmp, int nResizingX, int nResizingY, int nTilePixelX=1, int nTilePixelY=1);
int StretchBltEx(HDC hdcDest, int nXDest, int nYDest, int nWidthDest, int nHeightDest, HBITMAP hbmpSrc, int nResizingXSrc, int nResizingYSrc, int nTilePixelX=1, int nTilePixelY=1);
int BitBltEx(HDC hdcDest, int nXDest, int nYDest, int nDstWidth, int nDstHeight, HBITMAP hSrcBmp, int nXSrc, int nYSrc, DWORD dwRop);

int DrawNCBackground(CWnd *pCtrl, BITMAPOBJ hbmp, BOOL bResizingPointFromParent, int nResizingX, int nResizingY);
int DrawBackground(CWnd *pCtrl, CDC *pDstDC, BITMAPOBJ hbmp, BOOL bResizingPointFromParent, int nResizingX, int nResizingY);
int DrawForeground(CWnd *pCtrl, CDC *pDstDC, int nDstX, int nDstY, BITMAPOBJ hbmp, FOREGROUND_ALIGN_HOR eForegroundAlignHor, FOREGROUND_ALIGN_VER eForegroundAlignVer, COLORREF crMask);

int CopyHBITMAP(HBITMAP hSrc, HBITMAP *phDest);
#ifdef USEGDIPLUS
int CopyBitmap(Bitmap *pSrc, Bitmap **pDest);
#endif
int CopyBITMAPOBJ(BITMAPOBJ hSrc, BITMAPOBJ *phDest);

int CopyHFONT(HFONT hFontSrc, HFONT *phFontDest);
int CopyCFont(const CFont *pFontSrc, CFont *pFontDest);

HBITMAP CreateGradientBitmap(HDC hDC, COLORREF crStart, COLORREF crEnd, int nWidth, int nHeight, int nDir, int nNumColors);

// for DPI
int GetDPIBitmap(HBITMAP hSrcBmp, HBITMAP *phDstBmp);
HBITMAP GetDPIBitmap(HBITMAP hSrcBmp, BOOL bDeleteSrc = TRUE);
int GetDPIRect(LPRECT lpRect);
int GetDPIPointX(long &nX);
int GetDPIPointY(long &nY);
int GetDPILogFont(LPLOGFONT lpLogFont);
int GetDPILogFont(IUI_VARIANT *pvarLf);

// For window
BOOL IsParent(HWND hChild, HWND hParent);

#if(_MSC_VER <= 1200) // VC6.0
BOOL UpdateLayeredWindow(HWND hWnd, HDC hdcDst, POINT *pptDst, SIZE *psize, HDC hdcSrc, POINT *pptSrc, COLORREF crKey, BLENDFUNCTION *pblend, DWORD dwFlags);
#endif

int SetLayeredWindow(HWND hWnd, BOOL bSet);
BOOL IsLayeredWindow(HWND hWnd);

#ifdef USEGDIPLUS
BOOL TileDrawImage(Graphics *pGraphicsDst, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, Bitmap *pSrcImg, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc);
int StretchBitmap(Bitmap *pSrcBmp, Bitmap **phDstBmp, int nResizingX, int nResizingY, int nDstWidth, int nDstHeight, int nTilePixelX=1, int nTilePixelY=1);
int StretchBitmap(Bitmap *pSrcBmp, Bitmap **phDstBmp, int nDstWidth, int nDstHeight);
int AutoStretchControlBk(HDC hdcDest, int nDstX, int nDstY, int nDstWidth, int nDstHeight, Bitmap *hSrcBmp, int nResizingX, int nResizingY, int nTilePixelX=1, int nTilePixelY=1);
int StretchBltEx(HDC hdcDest, int nXDest, int nYDest, int nWidthDest, int nHeightDest, Bitmap *hbmpSrc, int nResizingXSrc, int nResizingYSrc, int nTilePixelX=1, int nTilePixelY=1);
int BitBltEx(HDC hdcDest, int nXDest, int nYDest, int nDstWidth, int nDstHeight, Bitmap *hSrcBmp, int nXSrc, int nYSrc, DWORD dwRop);
int GetBitmapSize(Bitmap *obj, LPSIZE size);
BOOL TileDrawImageBase(Graphics *pGraphicsDst, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, Bitmap *pSrcImg);
int StretchBitmapBase(Bitmap **phDstBmp, int nDstWidth, int nDstHeight, Bitmap *pSrcBmp, int nResizingX, int nResizingY, Bitmap *p01, Bitmap *p10, Bitmap *p11, Bitmap *p12, Bitmap *p21);
// for DPI
int GetDPIBitmap(Bitmap *pSrcBmp, Bitmap **phDstBmp);
Bitmap *GetDPIBitmap(Bitmap *pSrcBmp, BOOL bDeleteSrc = TRUE);
Bitmap *LoadBitmapFromRes(LPCTSTR lpszID, LPCTSTR lpszResType);
#endif

int CenterBitBltEx(HDC hDC, const CRect &rcDest, BITMAPOBJ hBmp, DWORD dwRop);

BOOL IsWinXPSp2ORLater();

void ASSERT_BITMAPOBJ(BITMAPOBJ obj);
void SafeDeleteBITMAPOBJ(BITMAPOBJ &obj);
void SafeDeleteHGDIOBJ(HGDIOBJ &obj);
int SafeDeleteHBITMAP(HBITMAP &hBmp);
int SafeDeleteCFont(CFont *&pFont);
template <class T>
void SafeDelete(T *&p)
{
	if (p != NULL)
	{
		delete p;
		p = NULL;
	}
}

template <class T>
void SafeArrayDelete(T *&p)
{
	if (p != NULL)
	{
		delete []p;
		p = NULL;
	}
}
BITMAPOBJ LoadBITMAPOBJ(LPCTSTR lpszFile);
BITMAPOBJ LoadBITMAPOBJ(UINT uID);
HBITMAP LoadHBITMAP(LPCTSTR lpszFile);
HICON LoadHICON(LPCTSTR lpszFile);

int GetHBITMAPSize(HBITMAP obj, LPSIZE size);
int GetBITMAPOBJSize(BITMAPOBJ obj, LPSIZE size);

#if(_MSC_VER <= 1310) // VC6.0 or VC7.1
typedef int errno_t;
#endif
int TSPLITPATH(LPCTSTR path, LPTSTR drive, size_t driveSizeInCharacters, LPTSTR dir, size_t dirSizeInCharacters, LPTSTR fname, size_t nameSizeInCharacters, LPTSTR ext, size_t extSizeInBytes);
errno_t TSTRCPY(LPTSTR strDestination, size_t numberOfElements, LPCTSTR strSource);	// Or using StrCpy
errno_t TSTRCAT(LPTSTR strDestination, size_t numberOfElements, LPCTSTR strSource);	// Or using StrCat
LPSTR nstrchr(LPCSTR pbyte, int ncb, int c);
LPWSTR wnstrchr(LPCWSTR pbyte, int ncb, int c);
BOOL AfxExtractSubStringA(std::string &rstring, LPCSTR lpszFullString, int nFullStringCount, int iSubString, CHAR chSep);
BOOL AfxExtractSubStringW(std::wstring &rstring, LPCWSTR lpszFullString, int nFullStringCount, int iSubString, WCHAR chSep);
FILE *TFOPEN(LPCTSTR filename, LPCTSTR mode);
errno_t FOPENW(FILE** pFile, LPCWSTR filename, LPCWSTR mode);

// for file
CString GetFileDrive(const CString &strFile);	// return drive name.
CString GetFilePath(const CString &strFile);	// return only path, not include title and ext.
CString GetFileName(const CString &strFile);	// return title and ext.
CString GetFileTitleEx(const CString &strFile);	// return only title, not include ext.
CString GetFileExt(const CString &strFile, BOOL bHasDot = TRUE);		// return ext.
int SplitPath(const CString &strFile, CString &strPath, CString &strTitle, CString &strExt);
int CheckFileWritable(const CString &strFile, BOOL bWarning = TRUE);
int CreateFileFolder(const CString &strFullPath);
CString GetExecutePath();
BOOL PathRemoveFileSpecEx(CString &rstrPath, BOOL bHasEndBackslash);
BOOL OpenForEditInPerforce(const CString &strFullPath);

// for data
CString StringFromInt(int nValue);
CString StringFromUINT(UINT n);

CString HexStringFromInt(int n, BOOL bHasPrefix, BOOL b0Fill, int nBits = 8);
CString HexStringFromUINT(UINT n, BOOL bHasPrefix, BOOL b0Fill, int nBits = 8);

// IntFromString returns the converted value, if any, or ULONG_MAX on overflow
unsigned long UINTFromString(LPCTSTR lpString);
unsigned long UINTFromHexString(LPCTSTR lpString);

// IntFromString returns the value represented in the string strValue,
// except when the representation would cause an overflow,
// in which case it returns LONG_MAX or LONG_MIN.
// IntFromString returns 0 if no conversion can be performed
int IntFromString(LPCTSTR lpString);
int IntFromHexString(LPCTSTR lpString);

long LongFromString(LPCTSTR lpString);

bool boolFromString(LPCTSTR lpString);

CString StringFromVariant(const _variant_t &rVariant);
int IntFromVariant(const _variant_t &rVariant);
_variant_t VariantFromInt(int nValue);

BOOL IsIntegerValue(const CString &strValue);

// _variant_t or VARIANT or double time to CTime
CTime VARIANT2CTime(_variant_t var);


// Big-endian, Little-endian
int SwitchWordEndian(const WORD *pszStream, WORD *pszTarget);

// For register
BOOL IUISetRegKey(LPCTSTR lpszKey, LPCTSTR lpszValue, LPCTSTR lpszValueName = NULL);

// For LibUIDK
int GetBackground2(const CTRLPROPERTIES *pCtrlProp, BITMAPOBJ *phBmpN, BITMAPOBJ *phBmpD);
int GetBackground4(const CTRLPROPERTIES *pCtrlProp, BITMAPOBJ *phBmpN, BITMAPOBJ *phBmpH, BITMAPOBJ *phBmpS, BITMAPOBJ *phBmpD);

int GetBackgroundFromParent2(const CTRLPROPERTIES *pCtrlProp, const CRect &rcCtrl, BITMAPOBJ hParentBKN, BITMAPOBJ hParentBKD, BITMAPOBJ *phCtrlBKN, BITMAPOBJ *phCtrlBKD);
int GetBackgroundFromParent4(const CTRLPROPERTIES *pCtrlProp, const CRect &rcCtrl, 
							 BITMAPOBJ hParentBKN, BITMAPOBJ hParentBKH, BITMAPOBJ hParentBKS, BITMAPOBJ hParentBKD,
							 BITMAPOBJ *phCtrlBKN, BITMAPOBJ *phCtrlBKH, BITMAPOBJ *phCtrlBKS, BITMAPOBJ *phCtrlBKD);

int GetButtonForeground(const BTNBASEPROPERTIES *pCtrlProp, BITMAPOBJ *phBmpN, BITMAPOBJ *phBmpH, BITMAPOBJ *phBmpS, BITMAPOBJ *phBmpD);
int GetToggleButtonBackground(const TOGGLEBTNPROPERTIES *pCtrlProp,
							  BITMAPOBJ *phBmpBKN, BITMAPOBJ *phBmpBKH, BITMAPOBJ *phBmpBKS, BITMAPOBJ *phBmpBKD,
							  BITMAPOBJ *phBmpBKCN, BITMAPOBJ *phBmpBKCH, BITMAPOBJ *phBmpBKCS, BITMAPOBJ *phBmpBKCD);
int GetToggleButtonForeground(const TOGGLEBTNPROPERTIES *pCtrlProp,
							  BITMAPOBJ *phBmpFGN, BITMAPOBJ *phBmpFGH, BITMAPOBJ *phBmpFGS, BITMAPOBJ *phBmpFGD,
							  BITMAPOBJ *phBmpFGCN, BITMAPOBJ *phBmpFGCH, BITMAPOBJ *phBmpFGCS, BITMAPOBJ *phBmpFGCD);
int GetStaticForeground(const TXTPROPERTIES *pCtrlProp, BITMAPOBJ *phBmpN, BITMAPOBJ *phBmpD);

int GetControlFont1(const CTRLPROPERTIES *pCtrlProp, CFont **ppFontN);
int GetControlFont2(const CTRLPROPERTIES *pCtrlProp, CFont **ppFontN, CFont **ppFontD);
int GetControlFont4(const CTRLPROPERTIES *pCtrlProp, CFont **ppFontN, CFont **ppFontH, CFont **ppFontS, CFont **ppFontD);
int GetControlFont8(const CTRLPROPERTIES *pCtrlProp,
					CFont **ppFontN, CFont **ppFontH, CFont **ppFontS, CFont **ppFontD,
					CFont **ppFontCN, CFont **ppFontCH, CFont **ppFontCS, CFont **ppFontCD);

int GetControlColor4(const CTRLPROPERTIES *pCtrlProp, COLORREF *pcrN, COLORREF *pcrH, COLORREF *pcrS, COLORREF *pcrD);
int GetControlColor8(const CTRLPROPERTIES *pCtrlProp, COLORREF *pcrN, COLORREF *pcrH, COLORREF *pcrS, COLORREF *pcrD, COLORREF *pcrCN, COLORREF *pcrCH, COLORREF *pcrCS, COLORREF *pcrCD);

int GetThumbImages(const HORSBPROPERTIES *pCtrlProp, BITMAPOBJ *phBmpN, BITMAPOBJ *phBmpH, BITMAPOBJ *phBmpS, BITMAPOBJ *phBmpD);
int GetThumbImages(const VERSBPROPERTIES *pCtrlProp, BITMAPOBJ *phBmpN, BITMAPOBJ *phBmpH, BITMAPOBJ *phBmpS, BITMAPOBJ *phBmpD);
int GetThumbImages(const SLDPROPERTIES *pCtrlProp, BITMAPOBJ *phBmpN, BITMAPOBJ *phBmpH, BITMAPOBJ *phBmpS, BITMAPOBJ *phBmpD);


// For combo box
int SelectComboBoxString(CComboBox *pBox, DWORD dwItemData);
int SelectComboBoxString(CComboBox *pBox, const CString &str);
int SelectComboBoxStringNoCase(CComboBox *pBox, const CString &str);

// For tree control
HTREEITEM FindTreeItemByData(CTreeCtrl *pTreeCtrl, HTREEITEM hParentItem, DWORD dwItemData);

// For CWaveCtrl
class CWaveItem;
class CWave;

CWaveItem *AllocWaveItem();
int FreeWaveItem(CWaveItem *pWaveItem);
CWave *AllocWave();
int FreeWave(CWave *pWave);

// For CSkinMenu
BOOL AfxInitSkinMenu();

//////////////////////////////////////////////////////////////////////////
// Window and Control

class CControlBase
{
public:
	CControlBase();
	virtual ~CControlBase();

	// Init control by specify style.
	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

	virtual int Release();

public:
	virtual int Redraw(CWnd *pCtrl);
	virtual BOOL IsUpdateLayeredWindow(CWnd *pCtrl);

	// If the parent has called UpdateLayeredWindow, draw the parent part.
	virtual int DrawParentPart(CWnd *pCtrl, CDC *pCtrlMemDC, const CRect &rcWin, BOOL *pbUpdateLayeredWindow);
};

class CSkinButton : public CButton, CControlBase
{
// Construction
public:
	CSkinButton();
	virtual ~CSkinButton();

	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);
	virtual int BindPushButtonStyle(const BTNPROPERTIES *pCtrlProp);
	virtual int BindCheckBoxStyle(const CHKPROPERTIES *pCtrlProp);
	virtual int BindRadioButtonStyle(const RADPROPERTIES *pCtrlProp);

	virtual int Release();

public:
	int SetToolTips(LPCTSTR lpszToolTips);
	CToolTipCtrl *GetToolTipCtrl();
	
	void SetTag(LPCTSTR lpszTag);
	void GetTag(CString &strTag);

	// color of button's text
	;
	void SetTextColor(COLORREF crN, COLORREF crH, COLORREF crS, COLORREF crD, BOOL bRedraw = TRUE);
	void GetTextColor(COLORREF *pcrN, COLORREF *pcrH, COLORREF *pcrS, COLORREF *pcrD);
	void SetCheckedTextColor(COLORREF crCN, COLORREF crCH, COLORREF crCS, COLORREF crCD, BOOL bRedraw = TRUE);
	void GetCheckedTextColor(COLORREF *pcrCN, COLORREF *pcrCH, COLORREF *pcrCS, COLORREF *pcrCD);

	// font of button's text
	;
	void SetTextFont(CFont *pFontN, CFont *pFontH, CFont *pFontS, CFont *pFontD, BOOL bRedraw = TRUE);
	void GetTextFont(CFont **pFontN, CFont **pFontH, CFont **pFontS, CFont **pFontD);
	void SetCheckedTextFont(CFont *pFontCN, CFont *pFontCH, CFont *pFontCS, CFont *pFontCD, BOOL bRedraw = TRUE);
	void GetCheckedTextFont(CFont **pFontCN, CFont **pFontCH, CFont **pFontCS, CFont **pFontCD);

	// offset of button's text
	;
	void SetTextOffsetHor(int nHOffsetN, int nHOffsetH, int nHOffsetS, int nHOffsetD, BOOL bRedraw = TRUE);
	void GetTextOffsetHor(int *pnHOffsetN, int *pnHOffsetH, int *pnHOffsetS, int *pnHOffsetD);
	void SetTextOffsetVer(int nVOffsetN, int nVOffsetH, int nVOffsetS, int nVOffsetD, BOOL bRedraw = TRUE);
	void GetTextOffsetVer(int *pnVOffsetN, int *pnVOffsetH, int *pnVOffsetS, int *pnVOffsetD);
	void SetCheckedTextOffsetHor(int nHOffsetCN, int nHOffsetCH, int nHOffsetCS, int nHOffsetCD, BOOL bRedraw = TRUE);
	void GetCheckedTextOffsetHor(int *pnHOffsetCN, int *pnHOffsetCH, int *pnHOffsetCS, int *pnHOffsetCD);
	void SetCheckedTextOffsetVer(int nVOffsetCN, int nVOffsetCH, int nVOffsetCS, int nVOffsetCD, BOOL bRedraw = TRUE);
	void GetCheckedTextOffsetVer(int *pnVOffsetCN, int *pnVOffsetCH, int *pnVOffsetCS, int *pnVOffsetCD);

	// align mode of the button
	;
	void SetTextAlignHor(TEXT_ALIGN_HOR eHorAlignModeN, TEXT_ALIGN_HOR eHorAlignModeH, TEXT_ALIGN_HOR eHorAlignModeS, TEXT_ALIGN_HOR eHorAlignModeD, BOOL bRedraw = TRUE);
	void GetTextAlignHor(TEXT_ALIGN_HOR *peHorAlignModeN, TEXT_ALIGN_HOR *peHorAlignModeH, TEXT_ALIGN_HOR *peHorAlignModeS, TEXT_ALIGN_HOR *peHorAlignModeD);
	void SetTextAlignVer(TEXT_ALIGN_VER eVerAlignModeN, TEXT_ALIGN_VER eVerAlignModeH, TEXT_ALIGN_VER eVerAlignModeS, TEXT_ALIGN_VER eVerAlignModeD, BOOL bRedraw = TRUE);
	void GetTextAlignVer(TEXT_ALIGN_VER *peVerAlignModeN, TEXT_ALIGN_VER *peVerAlignModeH, TEXT_ALIGN_VER *peVerAlignModeS, TEXT_ALIGN_VER *peVerAlignModeD);
	void SetCheckedTextAlignHor(TEXT_ALIGN_HOR eHorAlignModeCN, TEXT_ALIGN_HOR eHorAlignModeCH, TEXT_ALIGN_HOR eHorAlignModeCS, TEXT_ALIGN_HOR eHorAlignModeCD, BOOL bRedraw = TRUE);
	void GetCheckedTextAlignHor(TEXT_ALIGN_HOR *peHorAlignModeCN, TEXT_ALIGN_HOR *peHorAlignModeCH, TEXT_ALIGN_HOR *peHorAlignModeCS, TEXT_ALIGN_HOR *peHorAlignModeCD);
	void SetCheckedTextAlignVer(TEXT_ALIGN_VER eVerAlignModeCN, TEXT_ALIGN_VER eVerAlignModeCH, TEXT_ALIGN_VER eVerAlignModeCS, TEXT_ALIGN_VER eVerAlignModeCD, BOOL bRedraw = TRUE);
	void GetCheckedTextAlignVer(TEXT_ALIGN_VER *peVerAlignModeCN, TEXT_ALIGN_VER *peVerAlignModeCH, TEXT_ALIGN_VER *peVerAlignModeCS, TEXT_ALIGN_VER *peVerAlignModeCD);

	// bitmap and checked bitmap
	;
	void SetBitmap(BITMAPOBJ hbmpN, BITMAPOBJ hbmpH, BITMAPOBJ hbmpS, BITMAPOBJ hbmpD, BOOL bDeleteOld=TRUE, BOOL bRedraw=TRUE);
	void GetBitmap(BITMAPOBJ *phbmpN, BITMAPOBJ *phbmpH, BITMAPOBJ *phbmpS, BITMAPOBJ *phbmpD);
	void SetForegroundBitmap(BITMAPOBJ hBmpForegroundN, BITMAPOBJ hBmpForegroundH, BITMAPOBJ hBmpForegroundS, BITMAPOBJ hBmpForegroundD,
		int nDstX = 0, int nDstY = 0, FOREGROUND_ALIGN_HOR eAlignModeHor=FAH_LEFT, FOREGROUND_ALIGN_VER eAlignModeVer=FAV_CENTER, COLORREF crMask = RGB(255, 0, 255), BOOL bReDraw = TRUE);
	void GetForegroundBitmap(BITMAPOBJ *phBmpForegroundN, BITMAPOBJ *phBmpForegroundH, BITMAPOBJ *phBmpForegroundS, BITMAPOBJ *phBmpForegroundD,
		int *pnDstX, int *pnDstY, int *pnAlignModeHor, int *pnAlignModeVer, COLORREF *pcrMask);
	void SetForegroundIcon(HICON hIcon);
	HICON GetForegroundIcon() const;

	int  SetCheckedBitmap(BITMAPOBJ hbmpCN, BITMAPOBJ hbmpCH, BITMAPOBJ hbmpCS, BITMAPOBJ hbmpCD, BOOL bDeleteOld=TRUE, BOOL bRedraw=TRUE);
	int  SetCheckedBitmap(UINT uIDCN, UINT uIDCH, UINT uIDCS, UINT uIDCD, BOOL bDeleteOld=TRUE, BOOL bRedraw=TRUE);
	void GetCheckedBitmap(BITMAPOBJ *phbmpCN, BITMAPOBJ *phbmpCH, BITMAPOBJ *phbmpCS, BITMAPOBJ *phbmpCD);
	void SetCheckedForegroundBitmap(BITMAPOBJ hBmpForegroundCN, BITMAPOBJ hBmpForegroundCH, BITMAPOBJ hBmpForegroundCS, BITMAPOBJ hBmpForegroundCD,
		int nDstXC = 0, int nDstYC = 0, FOREGROUND_ALIGN_HOR eAlignModeHorC=FAH_LEFT, FOREGROUND_ALIGN_VER eAlignModeVerC=FAV_CENTER, COLORREF crMaskC = RGB(255, 0, 255), BOOL bReDraw = TRUE);
	void GetCheckedForegroundBitmap(BITMAPOBJ *phBmpForegroundCN, BITMAPOBJ *phBmpForegroundCH, BITMAPOBJ *phBmpForegroundCS, BITMAPOBJ *phBmpForegroundCD,
		int *pnDstXC, int *pnDstYC, int *pnAlignModeHorC, int *pnAlignModeVerC, COLORREF *pcrMaskC);
	void SetCheckedForegroundIcon(HICON hIcon);
	HICON GetCheckedForegroundIcon() const;

	// mask bitmap for checked and unchecked status
	;
	int SetMaskBitmap(LPCTSTR lpszMaskN, LPCTSTR lpszMaskH, LPCTSTR lpszMaskS, LPCTSTR lpszMaskD, BOOL bDeleteOld=TRUE, BOOL bRedraw=TRUE);
	int SetMaskBitmap(BITMAPOBJ hbmpMaskN, BITMAPOBJ hbmpMaskH, BITMAPOBJ hbmpMaskS, BITMAPOBJ hbmpMaskD, BOOL bDeleteOld=TRUE, BOOL bRedraw=TRUE);
	int GetMaskBitmap(BITMAPOBJ *phbmpMaskN, BITMAPOBJ *phbmpMaskH, BITMAPOBJ *phbmpMaskS, BITMAPOBJ *phbmpMaskD);
	int SetCheckedMaskBitmap(LPCTSTR lpszMaskCN, LPCTSTR lpszMaskCH, LPCTSTR lpszMaskCS, LPCTSTR lpszMaskCD, BOOL bDeleteOld=TRUE, BOOL bRedraw=TRUE);
	int SetCheckedMaskBitmap(BITMAPOBJ hbmpMaskCN, BITMAPOBJ hbmpMaskCH, BITMAPOBJ hbmpMaskCS, BITMAPOBJ hbmpMaskCD, BOOL bDeleteOld=TRUE, BOOL bRedraw=TRUE);
	int GetCheckedMaskBitmap(BITMAPOBJ *phbmpMaskCN, BITMAPOBJ *phbmpMaskCH, BITMAPOBJ *phbmpMaskCS, BITMAPOBJ *phbmpMaskCD);

	// set, get or remove resize point for button, if not set, the button will get it from parent
	;
	int SetResizePoint(LPPOINT pt);
	int GetResizePoint(LPPOINT pt);
	int RemoveResizePoint();

	// animate text
	;
	enum Direction
	{
		UNKNOWN,
		LEFT,
		TOP,
		RIGHT,
		BOTTOM,
	};
	int AnimateText(int nDirection, int nDelay, int nPixel = 1);
	int StopAnimateText();

	int SetEndEllipsis(BOOL bEndEllipsis);
	BOOL IsEndEllipsis();

	int SetTabStop(BOOL bTabStop);
	BOOL IsTabStop();

	int SetActiveArea(const CRect &rect);
	int GetActiveArea(LPRECT lpRect);
	BOOL IsHasActiveArea() const;
	int RemoveActiveArea();

	virtual void OnDraw(CDC *pMemDC);
	virtual int DrawButtonState(LONG lStyle, const CRect &rcClient, CDC *pDC, BITMAPOBJ hBmpBK, BITMAPOBJ hBmpMask,
		BITMAPOBJ hBmpFG, int nFGDstX, int nFGDstY, FOREGROUND_ALIGN_HOR eForegroundAlignHor, FOREGROUND_ALIGN_VER eForegroundAlignVer, COLORREF crFGMask,
		const CString &strText, TEXT_ALIGN_HOR eTextAlignHor, int nHorAlign, TEXT_ALIGN_VER eTextAlignVer, int nVerAlign,
		CFont **ppOldFont, CFont *pFont, CRect &rcText, COLORREF crText, UINT &uFormat, int nResizingX, int nResizingY);
	virtual int DrawText(CDC *pDC, const CString &strText, LPRECT lpRect, UINT uFormat);

	// hide the same name interface in base class
private:
	// DON'T call some interfaces in base class
	HBITMAP SetBitmap(HBITMAP hBitmap);
	HBITMAP GetBitmap() const;
	void SetFont(CFont* pFont, BOOL bRedraw = TRUE);
	CFont* GetFont() const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinButton)
	;
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinButton)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	void *m_pMember;
};

class CSkinEdit : public CEdit
{
// Construction
public:
	CSkinEdit();
	virtual ~CSkinEdit();

	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

	virtual int Release();

public:
	BOOL SetBkColor(COLORREF clrBkgnd);
	COLORREF GetBkColor();
	
	BOOL SetTextColor(COLORREF clrText);
	COLORREF GetTextColor();

	BOOL SetImages(BITMAPOBJ hbmpN, BITMAPOBJ hbmpH, BITMAPOBJ hbmpS, BITMAPOBJ hbmpD, BOOL bDeleteOld = TRUE);
	BOOL GetImages(BITMAPOBJ *phbmpN, BITMAPOBJ *phbmpH, BITMAPOBJ *phbmpS, BITMAPOBJ *phbmpD);
	
	void SetDeflateRight(int nDeflate);
	
	int SetTextFont(CFont *pFont);
	int GetTextFont(CFont **pFont);
	
	int SetTextAlign(int nAlignHor, int nAlignVer);
	int GetTextAlign(int *pnAlignHor, int *pnAlignVer);

	void SetTag(LPCTSTR lpszTag);
	void GetTag(CString &strTag);

	int SetResizePoint(LPPOINT pt);
	int GetResizePoint(LPPOINT pt);
	int RemoveResizePoint();

	BOOL IsHasBorder() const;

	// hide the same name interface in base class
private:
	void SetFont(CFont* pFont, BOOL bRedraw = TRUE);
	CFont* GetFont() const;

protected:
	int UpdateBackgroundBrush();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinEdit)
	public:
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	void *m_pMember;
};

class CSkinComboBox : public CComboBox
{
// Construction
public:
	CSkinComboBox();
	virtual ~CSkinComboBox();

	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:
	int GetBitmap(BITMAPOBJ *phbmpN, BITMAPOBJ *phbmpH, BITMAPOBJ *phbmpS, BITMAPOBJ *phbmpD);
	int SetBitmap(BITMAPOBJ hbmpN, BITMAPOBJ hbmpH, BITMAPOBJ hbmpS, BITMAPOBJ hbmpD, BOOL bDeleteOld=TRUE);

	void SetTextFont(CFont *pFontN);
	void GetTextFont(CFont **pFontN);

	BOOL SetTextColor(COLORREF clrText);
	COLORREF GetTextColor() const;
	BOOL SetDropdownListTextColor(COLORREF crText);
	COLORREF GetDropdownListTextColor() const;

	void SetTextOffsetN(int nHOffsetN, int nVOffsetN);
	void GetTextOffsetN(int *pnHOffsetN, int *pnVOffsetN);

	int SetButtonWidth(int nWidth);
	int GetButtonWidth(int *pnWidth) const;

	int SetSelectionFieldHeight(int nHeight);
	int GetSelectionFieldHeight(int *pnHeight) const;

	int SetItemHeight(int nHeight);
	int GetItemHeight(int *pnHeight) const;

	void SetTag(LPCTSTR lpszTag);
	void GetTag(CString &strTag);

	void DrawFocusRectangle(BOOL bDraw);
	BOOL IsDrawFocusRectangle();

	int SetResizePoint(LPPOINT pt);
	int GetResizePoint(LPPOINT pt);
	int RemoveResizePoint();

	// hide the same name interface in base class
private:
	void SetFont(CFont* pFont, BOOL bRedraw = TRUE);
	CFont* GetFont() const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinComboBox)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinComboBox)
	afx_msg void OnCloseup();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void *m_pMember;
	CSkinEdit m_ctrlEdit;
};

class CSkinSliderCtrl : public CSliderCtrl
{
// Construction
public:
	CSkinSliderCtrl();
	virtual ~CSkinSliderCtrl();

	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

protected:
	BOOL IsMouseOverThumb();

public:
	int SetImages(BITMAPOBJ hbmpN, BITMAPOBJ hbmpD, BOOL bDeleteOld=TRUE);
	int GetImages(BITMAPOBJ *phbmpN, BITMAPOBJ *phbmpD);

	int SetResizePoint(LPPOINT pt);
	int GetResizePoint(LPPOINT pt) const;
	int RemoveResizePoint();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinSliderCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CSkinSliderCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnCustomdraw(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg LRESULT OnGetThumbRect(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void *m_pMember;
};

class CSkinStatic : public CStatic, CControlBase
{
// Construction
public:
	CSkinStatic();
	virtual ~CSkinStatic();

	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:
	int SetBitmap(BITMAPOBJ hbmpN, BITMAPOBJ hbmpD, BOOL bDeleteOld=TRUE);
	int GetBitmap(BITMAPOBJ *phbmpN, BITMAPOBJ *phbmpD);
	void SetTextNoWrap(BOOL bNoWrap);
	BOOL GetTextNoWrap();
	int SetPathEllipsis(BOOL bPathEllipsis);
	BOOL IsPathEllipsis() const;
	int SetEndEllipsis(BOOL bEndEllipsis);
	BOOL IsEndEllipsis() const;
	void SetTextAlignHor(TEXT_ALIGN_HOR eHorAlignModeN, TEXT_ALIGN_HOR eHorAlignModeD);
	void GetTextAlignHor(TEXT_ALIGN_HOR *peHorAlignModeN, TEXT_ALIGN_HOR *peHorAlignModeD);
	void SetTextAlignVer(TEXT_ALIGN_VER eVerAlignModeN, TEXT_ALIGN_VER eVerAlignModeD);
	void GetTextAlignVer(TEXT_ALIGN_VER *peVerAlignModeN, TEXT_ALIGN_VER *peVerAlignModeD);
	void SetTextColor(COLORREF crN, COLORREF crD);
	void GetTextColor(COLORREF *pcrN, COLORREF *pcrD);
	void SetTextFont(CFont *pFontN, CFont *pFontD);
	void GetTextFont(CFont **ppFontN, CFont **ppFontD);
	void SetTextOffsetN(int nHOffsetN, int nVOffsetN); 
	void GetTextOffsetN(int *pnHOffsetN, int *pnVOffsetN);
	void SetTextOffsetD(int nHOffsetD, int nVOffsetD); 
	void GetTextOffsetD(int *pnHOffsetD, int *pnVOffsetD);

	void SetForegroundBitmap(BITMAPOBJ hBmpForegroundN, BITMAPOBJ hBmpForegroundD, int nDstX = 0, int nDstY = 0,
		FOREGROUND_ALIGN_HOR eAlignModeHor=FAH_LEFT, FOREGROUND_ALIGN_VER eAlignModeVer=FAV_CENTER, COLORREF crMask = RGB(255, 0, 255), BOOL bReDraw = TRUE);
	void GetForegroundBitmap(BITMAPOBJ *phBmpForegroundN, BITMAPOBJ *phBmpForegroundD, int *pnDstX, int *pnDstY,
		int *pnAlignModeHor, int *pnAlignModeVer, COLORREF *pcrMask);

	void SetToolTips(LPCTSTR lpszToolTips);
	CToolTipCtrl *GetToolTipCtrl();

	// set, get or remove resize point for control, if not set, the control will get it from parent
	;
	int SetResizePoint(LPPOINT pt);
	int GetResizePoint(LPPOINT pt);
	int RemoveResizePoint();

	// hide the same name interface in base class
private:
	void SetFont(CFont* pFont, BOOL bRedraw = TRUE);
	CFont* GetFont() const;

protected:
	virtual int OnDraw(CDC *pMemDC);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinStatic)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinStatic)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	void *m_pMember;
};

// The progress control has a border
class CSkinProgressCtrl : public CProgressCtrl
{
// Construction
public:
	CSkinProgressCtrl();
	virtual ~CSkinProgressCtrl();

	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

protected:
	virtual int DrawThumb(CDC *pMemDC);
	virtual int DrawHorizontalThumb(CDC *pMemDC);
	virtual int DrawVerticalThumb(CDC *pMemDC);
	virtual int DrawText(CDC *pMemDC);

public:
	void ShowText(BOOL bIsShow);
	BOOL IsShowText();

	int SetImages(BITMAPOBJ hbmpN, BITMAPOBJ hbmpD, BOOL bDeleteOld = TRUE);
	int GetImages(BITMAPOBJ *phbmpN, BITMAPOBJ *phbmpD);

	int SetResizePoint(LPPOINT pt);
	int GetResizePoint(LPPOINT pt) const;
	int RemoveResizePoint();

	int SetThumbImages(BITMAPOBJ hbmpThumbN, BITMAPOBJ hbmpThumbD, BOOL bDeleteOld = TRUE);
	int GetThumbImages(BITMAPOBJ *phbmpThumbN, BITMAPOBJ *phbmpThumbD);

	int SetThumbImageMode(PROGRESS_THUMB_MODE eMode);
	PROGRESS_THUMB_MODE GetThumbImageMode() const;

	int SetTextFont(CFont *pFontN, CFont *pFontD, BOOL bDeleteOld=TRUE);
	int GetTextFont(CFont **ppFontN, CFont **ppFontD);

	int SetThumbResizePoint(const LPPOINT lpPt);
	int GetThumbResizePoint(LPPOINT lpPt);

	// hide the same name interface in base class
private:
	void SetFont(CFont* pFont, BOOL bRedraw = TRUE);
	CFont* GetFont() const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinProgressCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinProgressCtrl)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
private:
	void *m_pMember;
};

class CSkinSpinButtonCtrl : public CSpinButtonCtrl
{
// Construction
public:
	CSkinSpinButtonCtrl();
	virtual ~CSkinSpinButtonCtrl();

	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:
	int SetImages(BITMAPOBJ hbmpN, BITMAPOBJ hbmpH, BITMAPOBJ hbmpS, BITMAPOBJ hbmpD, BOOL bDeleteOld = TRUE);
	int GetImages(BITMAPOBJ *phbmpN, BITMAPOBJ *phbmpH, BITMAPOBJ *phbmpS, BITMAPOBJ *phbmpD);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinSpinButtonCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinSpinButtonCtrl)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
protected:
	void *m_pMember;
};

class CSkinIPAddressCtrl : public CIPAddressCtrl
{
// Construction
public:
	CSkinIPAddressCtrl();
	virtual ~CSkinIPAddressCtrl();

	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:
	int SetImages(BITMAPOBJ hbmpN, BITMAPOBJ hbmpD, BOOL bDeleteOld = TRUE);
	int GetImages(BITMAPOBJ *phbmpN, BITMAPOBJ *phbmpD);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinIPAddressCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinIPAddressCtrl)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	void *m_pMember;
};

class CSkinHotKeyCtrl : public CHotKeyCtrl
{
// Construction
public:
	CSkinHotKeyCtrl();
	virtual ~CSkinHotKeyCtrl();

	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:
	int SetImages(BITMAPOBJ hbmpN, BITMAPOBJ hbmpD, BOOL bDeleteOld = TRUE);
	int GetImages(BITMAPOBJ *phbmpN, BITMAPOBJ *phbmpD);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinHotKeyCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinHotKeyCtrl)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void *m_pMember;
};

/////////////////////////////////////////////////////////////////////////////
// CSliderCtrlEx window

#ifdef _WIN32
#define WC_TRACKBAREXA            "msctls_trackbar32ex"
#define WC_TRACKBAREXW            L"msctls_trackbar32ex"

#ifdef UNICODE
#define  WC_TRACKBAREX            WC_TRACKBAREXW
#else
#define  WC_TRACKBAREX            WC_TRACKBAREXA
#endif

#else
#define WC_TRACKBAREX             "msctls_trackbarex"
#endif

#define WM_GETTOOLTIPS            WM_SLIDER+1	// wParam: point to a CString object; lParam, handle of the sliderex

#define TBS_EX_NORMAL             0x00000000
#define TBS_EX_PROGRESS           0x00001000
#define TBS_EX_SPLITPROGRESS      0x00002000
class CSliderCtrlEx : public CWnd
{
// Construction
public:
	CSliderCtrlEx();
	virtual ~CSliderCtrlEx();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:
	DWORD GetExtendedStyle();
	DWORD SetExtendedStyle(DWORD dwNewStyle);

	void SetRange(int nMin, int nMax, BOOL bRedraw = FALSE);
	void SetThumbSize(SIZE sizeThumb);
	int SetDeflate(UINT nLeftTop, UINT nRightBottom);
	int GetDeflate(UINT *pnLeftTop, UINT *pnRightBottom);
	void GetThumbRect(LPRECT lprc) const;

	int GetPos() const;	
	void SetPos(int nPos);

	int GetProgressPos() const;
	void SetProgressPos(int nPos);

	int SetImages(BITMAPOBJ hbmpN, BITMAPOBJ hbmpMarkN, BITMAPOBJ hbmpMarkD, BITMAPOBJ hbmpD, BOOL bDeleteOld = TRUE);
	int GetImages(BITMAPOBJ *phbmpN, BITMAPOBJ *phbmpMarkN, BITMAPOBJ *phbmpMarkD, BITMAPOBJ *phbmpD);

	int SetResizePoint(LPPOINT pt);
	int GetResizePoint(LPPOINT pt) const;
	int RemoveResizePoint();

	int SetThumbImages(BITMAPOBJ hbmpThumbN, BITMAPOBJ hbmpThumbH, BITMAPOBJ hbmpThumbS, BITMAPOBJ hbmpThumbD, BOOL bDeleteOld = TRUE);
	int GetThumbImages(BITMAPOBJ *phbmpThumbN, BITMAPOBJ *phbmpThumbH, BITMAPOBJ *phbmpThumbS, BITMAPOBJ *phbmpThumbD);

	int UseMarkBitmap(BOOL bUseMark);
	BOOL IsUseMarkBitmap() const;

	int SetSplitCount(int nCount);
	int GetSplitCount();
	int SetSplitList(const int *pnFirst, const int *pnLast, BOOL bRedraw=TRUE);
	int AddColorImage(int nValue, HBITMAP hbmpColor);
	int RemoveColorImage(int nValue);

	int EnableToolTipsEx(BOOL bEnable, BOOL bMouseMove = TRUE);
	int SetToolTips(LPCTSTR lpszToolTips);
	CToolTipCtrl *GetToolTipCtrl();

	// For tip window
	int EnableTipWindow(BOOL bEnable);
	BOOL IsEnableTipWindow() const;

	int SetTipWindow(CWnd *pTipWnd);
	CWnd *GetTipWindow();

	int SetTipWindowOffset(const LPSIZE lpsizeOffset);
	int GetTipWindowOffset(LPSIZE lpsizeOffset) const;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSliderCtrlEx)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	;
	virtual void DrawHorzSlider(CDC *pMemDC);
	virtual void DrawVertSlider(CDC *pMemDC);

	// Generated message map functions
protected:
	//{{AFX_MSG(CSliderCtrlEx)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void *m_pMember;
};

class CSkinHeaderCtrl : public CHeaderCtrl
{
// Construction
public:
	CSkinHeaderCtrl();
	virtual ~CSkinHeaderCtrl();

	// Init control by specify style.
	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:
	void SetTreeCtrlEx(CWnd *pWnd);
	CWnd *GetTreeCtrlEx();

	int SetBkImage(BITMAPOBJ hBackground);
	int GetBkImage(BITMAPOBJ *phBackground) const;

	int SetBkImageResizePoint(LPPOINT pt);
	int GetBkImageResizePoint(LPPOINT pt) const;

	int SetButtonImages(BITMAPOBJ hbmpBkN, BITMAPOBJ hbmpBkH, BITMAPOBJ hbmpBkS, BITMAPOBJ hbmpBkD, BOOL bDeleteOld=TRUE);
	int GetButtonImages(BITMAPOBJ *phbmpBkN, BITMAPOBJ *phbmpBkH, BITMAPOBJ *phbmpBkS, BITMAPOBJ *phbmpBkD) const;

	int SetTextColor(COLORREF crN, COLORREF crH, COLORREF crS, COLORREF crD, BOOL bRedraw = TRUE);
	int GetTextColor(COLORREF *pcrN, COLORREF *pcrH, COLORREF *pcrS, COLORREF *pcrD) const;

	int SetTextFont(CFont *pFontN, CFont *pFontH, CFont *pFontS, CFont *pFontD, BOOL bRedraw = TRUE);
	int GetTextFont(CFont **ppFontN, CFont **ppFontH, CFont **ppFontS, CFont **ppFontD) const;

	int SetHeaderHeight(int nHeight);
	int GetHeaderHeight() const;

	int SetButtonImageResizePoint(LPPOINT pt);
	int GetButtonImageResizePoint(LPPOINT pt) const;

	int HitTest(CPoint pt);

	// hide the same name interface in base class
private:
	void SetFont(CFont* pFont, BOOL bRedraw = TRUE);
	CFont* GetFont() const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinHeaderCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL
	;
	virtual void DrawItem(CDC *pDC, int nItem);

protected:
	//{{AFX_MSG(CSkinHeaderCtrl)
	afx_msg void OnPaint();
	//}}AFX_MSG
	afx_msg void OnNMEndTrack(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()

private:
	void *m_pMember;
};

/////////////////////////////////////////////////////////////////////////////
// CScrollBarEx window

//   _________________________________________
//  | 0 |    3     |////// 2 /////|   4   | 1 |
//  |___|__________|______________|_______|___|
//
//  0: Left or Up arrow
//  1: Right or Down arrow
//  2: Thumb
//  3: Space1
//  4: Space2

#define GIR_LTUP             0x00000001
#define GIR_RTDN             0x00000010
#define GIR_THUMB            0x00000100
#define GIR_ALL              GIR_LTUP|GIR_RTDN|GIR_THUMB

#ifdef _WIN32
#define WC_SCROLLBAREXA            "ScrollBarEx"
#define WC_SCROLLBAREXW            L"ScrollBarEx"

#ifdef UNICODE
#define  WC_SCROLLBAREX            WC_SCROLLBAREXW
#else
#define  WC_SCROLLBAREX            WC_SCROLLBAREXA
#endif

#else
#define WC_SCROLLBAREX             "ScrollBarEx"
#endif

class CScrollBarEx : public CWnd
{
// Construction
public:
	CScrollBarEx();
	virtual ~CScrollBarEx();

	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	// Init control by specify style.
	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);
	virtual int BindHorzScrollbarStyle(const HORSBPROPERTIES *pHorzScrollbarProp);
	virtual int BindVertScrollbarStyle(const VERSBPROPERTIES *pVertScrollbarProp);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollBarEx)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
	;
public:
	int SetBkBitmaps(BITMAPOBJ hbmpBkN, BITMAPOBJ hbmpBkH, BITMAPOBJ hbmpBkS, BITMAPOBJ hbmpBkD, BOOL bDeleteOld=TRUE);
	int GetButton1Images(BITMAPOBJ *phBmpN, BITMAPOBJ *phBmpH, BITMAPOBJ *phBmpS, BITMAPOBJ *phBmpD) const;
	int GetButton2Images(BITMAPOBJ *phBmpN, BITMAPOBJ *phBmpH, BITMAPOBJ *phBmpS, BITMAPOBJ *phBmpD) const;
	int GetSpaceImage(BITMAPOBJ *phBmpSpace) const;
	int SetSpaceResizePoint(LPPOINT lppt);
	int GetSpaceResizePoint(LPPOINT lppt) const;

	int SetThumbBitmaps(BITMAPOBJ hbmpThumbN, BITMAPOBJ hbmpThumbH, BITMAPOBJ hbmpThumbS, BITMAPOBJ hbmpThumbD, BOOL bDeleteOld=TRUE);
	int GetThumbBitmaps(BITMAPOBJ *phbmpThumbN, BITMAPOBJ *phbmpThumbH, BITMAPOBJ *phbmpThumbS, BITMAPOBJ *phbmpThumbD);
	int SetThumbResizePoint(LPPOINT lppt);
	int GetThumbResizePoint(LPPOINT lppt) const;

	void SetLTUPButton(int nValue);
	int GetLTUPButton();

	void SetRTDNButton(int nValue);
	int GetRTDNButton();

	void SetNotifyWnd(CWnd *pWnd);
	CWnd *GetNotifyWnd();

	virtual void DrawSizeBox(CDC *pDC, CDC *pMemDC);
	virtual void DrawHorzItem(CDC *pDC, CDC *pMemDC);
	virtual void DrawVertItem(CDC *pDC, CDC *pMemDC);

	void GetItemRect(LPRECT lprcLTUP, LPRECT lprcRTDN, LPRECT lprcThumb, UINT nMask = GIR_ALL);
	void ShowScrollBar(BOOL bShow = TRUE);
	BOOL EnableScrollBar(UINT nArrowFlags = ESB_ENABLE_BOTH);
	
	void SetScrollRange(int nMinPos, int nMaxPos, BOOL bRedraw = TRUE);
	void GetScrollRange(LPINT lpMinPos, LPINT lpMaxPos) const;
	
	BOOL SetScrollPos(int nPos, BOOL bRedraw = TRUE);
	int GetScrollPos() const;
	
	BOOL SetScrollInfo(LPCSCROLLINFO lpScrollInfo, BOOL bRedraw = TRUE);
	BOOL GetScrollInfo(LPSCROLLINFO lpScrollInfo, UINT nMask = SIF_ALL);
	
	int GetScrollLimit();

#if(WINVER >= 0x0500)
	BOOL GetScrollBarInfo(PSCROLLBARINFO pScrollInfo) const;
#endif //(WINVER >= 0x0500)

	// Generated message map functions
protected:
	//{{AFX_MSG(CScrollBarEx)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:
	UINT m_nLTUP; // Width of the left arrow of a horizontal scroll bar or Height of the up arrow of a vertical scroll bar
	UINT m_nRTDN; // Width of the right arrow of a horizontal scroll bar or Height of the down arrow of a vertical scroll bar
	SCROLLINFO m_si;
	DWORD m_dwStyle;

	BITMAPOBJ m_hbmpButton1[4];
	BITMAPOBJ m_hbmpButton2[4];
	BITMAPOBJ m_hbmpSpace;
	CPoint m_ptSpaceResize;

	BITMAPOBJ m_hbmpThumb[4];
	CPoint m_ptThumbResize;
	
	int m_nCapture;				// -1: mouse not be captrue; 0: captured by LTUP arrow; 1: captured by RTDN arrow;  2: captured by thumb; 3: captured by space1; 4: captured by space2;
								// 2: captured by thumb, 3: captured by space1; 4: captured by space2
	int m_nArrowFlags;			// disable or enable the arrow of the scroll
	CPoint m_ptDragThumb;		// record the point when drag the thumb
	SCROLLINFO m_siDrag;		// record the scroll information when drag the thumb
	int m_nDragOffset;			// record the offset from first position when drag the thumb
	CWnd *m_pNotifyWnd;
	BOOL m_bCaptureThumb;
	BOOL m_bIsMouseOverThumb;
	BOOL m_bCaptureLTUPButton;
	BOOL m_bIsMouseOverLTUPButton;
	BOOL m_bCaptureRTDNButton;
	BOOL m_bIsMouseOverRTDNButton;
};

/////////////////////////////////////////////////////////////////////////////
// CSkinListCtrl window

#define WM_DRAWLIST							WM_LISTCTRL+1		// WPARAM(CPaintDC *pDC), LPARAM((CSkinListCtrl *)this)
#define LVM_ITEM_TEXT_COLOR					WM_LISTCTRL+2		// WPARAM: not use; LPARAM: ITEMTEXTCOLOR *; return: non-zero if it processes this message

class CSkinListCtrl : public CListCtrl
{
// Construction
public:
	CSkinListCtrl();
	virtual ~CSkinListCtrl();

	// Init control by specify style.
	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:
#if(_MSC_VER <= 1400) // VC8.0
	BOOL GetItemSpacing(BOOL fSmall, int* pnHorzSpacing, int* pnVertSpacing) const;
#endif

public:
	// Header
	// ;
	void SetHeaderHeight(int nHeight);
	int GetHeaderHeight() const;

	int SetHeaderBkImage(BITMAPOBJ hBmpBk);
	int GetHeaderBkImage(BITMAPOBJ *phBmpBk) const;

	int SetHeaderBkImageResizePoint(LPPOINT lpPt);
	int GetHeaderBkImageResizePoint(LPPOINT lpPt) const;

	int SetHeaderButtonImages(BITMAPOBJ hbmpHeaderN, BITMAPOBJ hbmpHeaderH, BITMAPOBJ hbmpHeaderS, BITMAPOBJ hbmpHeaderD);
	int GetHeaderButtonImages(BITMAPOBJ *phbmpHeaderN, BITMAPOBJ *phbmpHeaderH, BITMAPOBJ *phbmpHeaderS, BITMAPOBJ *phbmpHeaderD) const;

	int SetHeaderButtonImageResizePoint(LPPOINT lpPt);
	int GetHeaderButtonImageResizePoint(LPPOINT lpPt) const;

	// for icon in other columns with report style
	int SetImageListEx(CImageList* pImageList);
	CImageList* GetImageListEx() const;
	CRect GetSubItemIconRect(int nItem, int nSubItem);

	BOOL SetItemTextEx(int nItem, int nSubItem, LPCTSTR lpszText, int nImageEx);
	int GetItemImage(int nIndex, int nSubItem) const;

	// for background image
	int EnableBkImage(BOOL bEnable);
	BOOL IsEnableBkImage() const;

	int SetImages(BITMAPOBJ hbmpBkN, BITMAPOBJ hbmpBkD, BOOL bDeleteOld=TRUE);
	int GetImages(BITMAPOBJ *phbmpBkN, BITMAPOBJ *phBmpBkD) const;

	int EnableOwnerDraw(BOOL bEnable);
	BOOL IsEnableOwnerDraw() const;

	// For grid line
	int ShowGridLine(BOOL bShow);
	BOOL IsGridLineVisible();

	int SetGridLineColor(COLORREF crGridLine);
	COLORREF GetGridLineColor() const;

	// For normal item
	int EnableNormalItemEffect(BOOL bEnable);
	BOOL IsEnableNormalItemEffect() const;

	int SetNormalItemBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetNormalItemBkType() const;

	int SetNormalItemBkColor(COLORREF cr);
	COLORREF GetNormalItemBkColor() const;

	int SetNormalItemBkImages(BITMAPOBJ hbmpItemBk, BOOL bDeleteOld = TRUE);
	int GetNormalItemBkImages(BITMAPOBJ *phbmpItemBk) const;

	int SetNormalItemBkImageResizePoint(LPPOINT lpPt);
	int GetNormalItemBkImageResizePoint(LPPOINT lpPt) const;

	int SetNormalItemTextColor(COLORREF cr);
	COLORREF GetNormalItemTextColor() const;

	// For highlight item
	int EnableHighlightItemEffect(BOOL bEnable);
	BOOL IsEnableHighlightItemEffect() const;

	int SetHighlightItemBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetHighlightItemBkType() const;

	int SetHighlightItemBkColor(COLORREF cr);
	COLORREF GetHighlightItemBkColor() const;

	int SetHighlightItemBkImages(BITMAPOBJ hbmpBk, BOOL bDeleteOld = TRUE);
	int GetHighlightItemBkImages(BITMAPOBJ *phbmpBk);

	int SetHighlightItemBkImageResizePoint(LPPOINT lpPt);
	int GetHighlightItemBkImageResizePoint(LPPOINT lpPt) const;

	int SetHighlightItemTextColor(COLORREF cr);
	COLORREF GetHighlightItemTextColor() const;

	int GetHighlightItem() const;

	// For selected item
	// draw selected background fit to the width of client, not to the right of last header item.
	// ;
	int EnableSelectedFitClient(BOOL bEnable);
	BOOL IsEnableSelectedFitClient() const;

	int SetSelectedItemBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetSelectedItemBkType() const;

	int SetSelectedItemBkColor(COLORREF cr);
	COLORREF GetSelectedItemBkColor() const;

	int SetSelectedItemBkImages(BITMAPOBJ hbmpBk, BOOL bDeleteOld = TRUE);
	int GetSelectedItemBkImages(BITMAPOBJ *phbmpBk);

	int SetSelectedItemBkImageResizePoint(LPPOINT lpPt);
	int GetSelectedItemBkImageResizePoint(LPPOINT lpPt) const;

	int SetSelectedItemTextColor(COLORREF cr);
	COLORREF GetSelectedItemTextColor() const;

	// For normal disabled item
	int EnableNormalDisabledItemEffect(BOOL bEnable);
	BOOL IsEnableNormalDisabledItemEffect() const;

	int SetNormalDisabledItemBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetNormalDisabledItemBkType() const;

	int SetNormalDisabledItemBkColor(COLORREF cr);
	COLORREF GetNormalDisabledItemBkColor() const;

	int SetNormalDisabledItemBkImages(BITMAPOBJ hbmpBk, BOOL bDeleteOld = TRUE);
	int GetNormalDisabledItemBkImages(BITMAPOBJ *phbmpBk);

	int SetNormalDisabledItemBkImageResizePoint(LPPOINT lpPt);
	int GetNormalDisabledItemBkImageResizePoint(LPPOINT lpPt) const;

	int SetNormalDisabledItemTextColor(COLORREF cr);
	COLORREF GetNormalDisabledItemTextColor() const;

	// For selected disabled item
	int EnableSelectedDisabledItemEffect(BOOL bEnable);
	BOOL IsEnableSelectedDisabledItemEffect() const;

	int SetSelectedDisabledItemBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetSelectedDisabledItemBkType() const;

	int SetSelectedDisabledItemBkColor(COLORREF cr);
	COLORREF GetSelectedDisabledItemBkColor() const;

	int SetSelectedDisabledItemBkImages(BITMAPOBJ hbmpBk, BOOL bDeleteOld = TRUE);
	int GetSelectedDisabledItemBkImages(BITMAPOBJ *phbmpBk);

	int SetSelectedDisabledItemBkImageResizePoint(LPPOINT lpPt);
	int GetSelectedDisabledItemBkImageResizePoint(LPPOINT lpPt) const;

	int SetSelectedDisabledItemTextColor(COLORREF cr);
	COLORREF GetSelectedDisabledItemTextColor() const;

	// For text font
	// ;
	int SetItemTextFont(CFont *pFontN, CFont *pFontH, CFont *pFontS, CFont *pFontND, CFont *pFontSD);
	int GetItemTextFont(CFont **ppFontN, CFont **ppFontH, CFont **ppFontS, CFont **ppFontND, CFont **ppFontSD) const;

	// For thumbnail view
	int SetThumbnailView(BOOL bThumbnailView);
	BOOL IsThumbnailView() const;

	int SetThumbnailItemTotalSize(SIZE sizeItem);
	int GetThumbnailItemTotalSize(LPSIZE lpSizeItem) const;

	int SetThumbnailItemBkPosition(LPCRECT lprcPositionN, LPCRECT lprcPositionH, LPCRECT lprcPositionS, LPCRECT lprcPositionD);
	int GetThumbnailItemBkPosition(LPRECT lprcPositionN, LPRECT lprcPositionH, LPRECT lprcPositionS, LPRECT lprcPositionD) const;

	int SetThumbnailItemPosition(LPCRECT lprcPositionN, LPCRECT lprcPositionH, LPCRECT lprcPositionS, LPCRECT lprcPositionD);
	int GetThumbnailItemPosition(LPRECT lprcPositionN, LPRECT lprcPositionH, LPRECT lprcPositionS, LPRECT lprcPositionD) const;

	int SetThumbnailItemLabelPosition(LPCRECT lprcPositionN, LPCRECT lprcPositionH, LPCRECT lprcPositionS, LPCRECT lprcPositionD);
	int GetThumbnailItemLabelPosition(LPRECT lprcPositionN, LPRECT lprcPositionH, LPRECT lprcPositionS, LPRECT lprcPositionD) const;

	int SetThumbnailItemIconPosition(LPCRECT lprcPositionN, LPCRECT lprcPositionH, LPCRECT lprcPositionS, LPCRECT lprcPositionD);
	int GetThumbnailItemIconPosition(LPRECT lprcPositionN, LPRECT lprcPositionH, LPRECT lprcPositionS, LPRECT lprcPositionD) const;

	int GetThumbnailItemTotalRect(int nItem, LPRECT lpRectTotal) const;
	int GetThumbnailItemRect(int nItem, LPRECT lpRect, UINT nCode, CONTROL_STATE eControlState) const;

	// Tag
	void SetTag(LPCTSTR lpszTag);
	void GetTag(CString &strTag);

	// Resize point
	int SetResizePoint(LPPOINT pt);
	int GetResizePoint(LPPOINT pt);
	int RemoveResizePoint();

	// for custom scroll bar
	int UseCustomScrollBar(BOOL bUseCustomScrollBar);
	BOOL IsUseCustomScrollBar() const;

	CScrollBarEx *GetHorzScrollBarEx() const;
	CScrollBarEx *GetVertScrollBarEx() const;

	int UpdateCustomScrollBar();

	// hide the same name interface in base class
private:
	void SetFont(CFont* pFont, BOOL bRedraw = TRUE);
	CFont* GetFont() const;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinListCtrl)
	public:
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL
#if(_MSC_VER <= 1200) // VC6.0
	virtual INT OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
#else
	virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
#endif

protected:
	virtual int DrawBackground(CDC *pDC);
	virtual int DrawGridLine(CDC *pDC);
	virtual int DrawItemEx(CDC *pDC, int nItem);
	virtual int DrawReportItem(CDC *pDC, int nItem, const CRect &rcItem);
	virtual int DrawIconItem(CDC *pDC, int nItem, const CRect &rcItem);
	virtual int DrawThumbnailItem(CDC *pDC, int nItem, const CRect &rcItem);

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinListCtrl)
	afx_msg BOOL OnSetTipText(UINT id, NMHDR *pNMHDR, LRESULT *pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void *m_pMember;
};

class CSkinTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CSkinTreeCtrl();
	virtual ~CSkinTreeCtrl();

	// Init control by specify style.
	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:
	int SetImages(BITMAPOBJ hbmpBkN, BITMAPOBJ hbmpBkD, BOOL bDeleteOld=TRUE);
	int GetImages(BITMAPOBJ *phbmpBkN, BITMAPOBJ *phBmpBkD);

	// Resize point
	int SetResizePoint(LPPOINT pt);
	int GetResizePoint(LPPOINT pt) const;
	int RemoveResizePoint();

	// For item line
	int EnableItemLine(BOOL bEnable);
	BOOL IsEnableItemLine() const;

	int SetItemLineColor(COLORREF cr);
	COLORREF GetItemLineColor() const;
	
	// for highlight item
	// ;
	int EnableHighlightItem(BOOL bEnable);
	BOOL IsEnableHighlightItem() const;
	HTREEITEM GetHighlightItem() const;

	int SetHighlightItemBkColor(COLORREF cr);
	COLORREF GetHighlightItemBkColor() const;

	int SetHighlightItemBkImages(BITMAPOBJ hbmpBkN, BITMAPOBJ hbmpBkD, BOOL bDeleteOld = TRUE);
	int GetHighlightItemBkImages(BITMAPOBJ *phbmpBkN, BITMAPOBJ *phbmpBkD);

	int SetHighlightItemBkResizePoint(LPPOINT pt);
	int GetHighlightItemBkResizePoint(LPPOINT pt);

	int SetHighlightItemTextColor(COLORREF cr);
	COLORREF GetHighlightItemTextColor() const;

	// for selected item
	// ;
	int SetSelectedItemBkColor(COLORREF cr);
	COLORREF GetSelectedItemBkColor() const;

	int SetSelectedItemBkImages(BITMAPOBJ hbmpBkN, BITMAPOBJ hbmpBkD, BOOL bDeleteOld = TRUE);
	int GetSelectedItemBkImages(BITMAPOBJ *phbmpBkN, BITMAPOBJ *phbmpBkD);

	int SetSelectedItemBkResizePoint(LPPOINT pt);
	int GetSelectedItemBkResizePoint(LPPOINT pt);

	int SetSelectedItemTextColor(COLORREF cr);
	COLORREF GetSelectedItemTextColor() const;

	// for disable text color
	// ;
	int SetDisabledItemTextColor(COLORREF cr);
	COLORREF GetDisabledItemTextColor() const;

	// for mouse hover
	// ;
	void SetHoverTime(DWORD dwHoverTime, BOOL bRepeat=FALSE);
	void GetHoverTime(DWORD *pdwHoverTime, BOOL *pbRepeat);

	// for custom scroll bar
	// ;
	int UseCustomScrollBar(BOOL bUseCustomScrollBar);
	BOOL IsUseCustomScrollBar();

	CScrollBarEx *GetHorzScrollBarEx() const;
	CScrollBarEx *GetVertScrollBarEx() const;

	int UpdateCustomScrollBar();

	int SetTextFont(CFont *pFontN, CFont *pFontD = NULL);
	int GetTextFont(CFont **ppFontN, CFont **ppFontD = NULL);

	int SetItemHeightEx(HTREEITEM hItem, UINT cyItemHeight);
	UINT GetItemHeightEx(HTREEITEM hItem);


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinTreeCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinTreeCtrl)
	afx_msg void OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	virtual int DrawBackground(CDC *pDC);
	virtual int DrawItem(CDC *pDC, HTREEITEM hItem);
	virtual int DrawItemLine(CDC *pDC, HTREEITEM hItem);

private:
	void *m_pMember;
};

class COleDropInfo : public CObject
{
public:
	COleDropInfo();
	COleDropInfo(COleDataObject* pDataObject,DWORD dwKeyState,
		DROPEFFECT dropEffect,DROPEFFECT dropEffectList,CPoint point );
	virtual ~COleDropInfo();

public:
	//COleDropTargetEx member functions params
	COleDataObject* m_pDataObject;
	DWORD m_dwKeyState;
	DROPEFFECT m_dropEffect;
	DROPEFFECT m_dropEffectList;
	CPoint m_point;
};

class COleDropTargetEx : public COleDropTarget
{
public:
	COleDropTargetEx();
	virtual ~COleDropTargetEx();

protected:
	virtual DROPEFFECT OnDragEnter(CWnd* pWnd, COleDataObject* pDataObject,
		DWORD dwKeyState, CPoint point);
	virtual DROPEFFECT OnDragOver(CWnd* pWnd, COleDataObject* pDataObject,
		DWORD dwKeyState, CPoint point);
	virtual BOOL OnDrop(CWnd* pWnd, COleDataObject* pDataObject,
		DROPEFFECT dropEffect, CPoint point);
	virtual DROPEFFECT OnDropEx(CWnd* pWnd, COleDataObject* pDataObject,
		DROPEFFECT dropEffect, DROPEFFECT dropEffectList, CPoint point);
	virtual void OnDragLeave(CWnd* pWnd);
	virtual DROPEFFECT OnDragScroll( CWnd* pWnd, DWORD dwKeyState, CPoint point );
		
};

/////////////////////////////////////////////////////////////////////////////
// CThumbnailCtrl window

#ifdef _WIN32
#define WC_THUMBNAILVIEWA            "SysThumbnailView32"
#define WC_THUMBNAILVIEWW            L"SysThumbnailView32"

#ifdef UNICODE
#define  WC_THUMBNAILVIEW            WC_THUMBNAILVIEWW
#else
#define  WC_THUMBNAILVIEW            WC_THUMBNAILVIEWA
#endif

#else
#define WC_THUMBNAILVIEW             "SysThumbnailView"
#endif

#define LVN_ENDDRAG                  1

class CThumbnailCtrl : public CWnd
{
// Construction
public:
	CThumbnailCtrl();
	virtual ~CThumbnailCtrl();
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

public:
	// must be call after the object is created and before the window is created
	BOOL SetItemBitmap(LPCTSTR lpszNormal, LPCTSTR lpszHighlight, LPCTSTR lpszSelected, LPCTSTR lpszDisabled = NULL);
	BOOL SetItemBitmap(HBITMAP hItemBkN, HBITMAP hItemBkH, HBITMAP hItemBkS, HBITMAP hItemBkD = NULL);

	//
	int GetItemBitmap(HBITMAP *phItemBKN, HBITMAP *phItemBKH, HBITMAP *phItemBKS, HBITMAP *phItemBKD = NULL) const;

	// must be call after the object is created and before the window is created.
	// the total size is one image take up, include all space, from one item's left side to another item's left side.
	// this interface only support non-list style
	BOOL SetItemSize(CSize sizeTotal);
	
	// must be call after the object is created.
	BOOL SetItemPosition(LPCRECT lprcThumbnail, LPCRECT lprcHLThumbnail, LPCRECT lprcLabel, LPCRECT lprcHLLabel);
	BOOL SetLinesPerItem(int nLines);

	// 
	int GetItemPosition(LPRECT lprcThumbnail, LPRECT lprcHLThumbnail, LPRECT lprcLabel, LPRECT lprcHLLabel) const;
	
	// if necessary, call before the CThumbnailCtrlEx object is created
	void SetScrollBarWidth(int nWidth); 

	int SetItemHeight(int nItemHeight);
	int GetItemHeight() const;
// Attributes
public:
	void ClientToWindow(LPRECT lpRect) const;
	void WindowToClient(LPRECT lpRect) const;

	int GetFocusItem();
	int SetFocusItem(int nItem);

	void GetScrollBarRect(CRect &rcScrollBar) const;
	void EnableDragDrop(BOOL bEnable = TRUE);// Enable Drag & Drop item in the view, muse call 	AfxOleInit() when app is init.
	void EnableScrollBarCtrl(int nBar, BOOL bEnable = TRUE);
	
	POSITION GetFirstSelectedItemPosition() const; // 
	int GetNextSelectedItem(POSITION& pos);// 
	int GetFirstVisibleItem(BOOL bPartialOK = TRUE);
	int GetLastVisibleItem(BOOL bPartialOK = TRUE);
	int GetItemCount() const;
	int GetItemText(int nItem, int nSubItem, LPTSTR lpszText, int nLen) const;
	int GetNextItem(int nItem, int nFlags);
	int GetHotItem() const;
	int GetTopIndex(); // only valid with list style
	UINT GetItemState(int nItem, UINT nMask) const;
	UINT GetSelectedCount();
	BOOL GetItem(LVITEM *pItem) const;
	BOOL GetItemRect(int nItem, LPRECT lpRect, UINT nCode) const; // relative to the pos return by GetViewRect
	HBITMAP GetItemThumbnail(int nItem);
	CString GetItemTooltip(int nItem) const;
	BOOL GetViewRect(LPRECT lpRect) const;
	CString GetItemText(int nItem, int nSubItem);
#if(_MSC_VER <= 1200) // VC6.0
	DWORD GetItemData(int nItem);
#else
	DWORD_PTR GetItemData(int nItem);
#endif
	COLORREF GetBkColor() const;
	COLORREF GetTextColor() const;
	int GetCountPerPage( ) const;

	BOOL SetBkColor(COLORREF cr);

	int GetBkImage(BITMAPOBJ *phbm);
	BOOL SetBkImage(BITMAPOBJ hbm, BOOL fTile=TRUE, BOOL bDeleteOld=TRUE);

	BOOL SetItem(const LVITEM *pItem);
	BOOL SetItemState(int nItem, LVITEM *pItem);
	BOOL SetItemState(int nItem, UINT nState, UINT nMask);
	BOOL SetItemData(int nItem, DWORD dwData);
	BOOL SetItemText(int nItem, int nSubItem, LPTSTR lpszText, BOOL bRedraw = TRUE);
	BOOL SetTextColor(COLORREF cr, BOOL bRedraw = TRUE);
	BOOL SetItemThumbnail(int nItem, HBITMAP hbmpThumbnail, BOOL bDeleteOld = TRUE, BOOL bRedraw = TRUE);
	BOOL SetItemTooltip(int nItem, LPCTSTR lpszTooltip);
	void SetShiftStart(int nShiftStart);

	// for CScrollBarEx's background
	CScrollBarEx *GetScrollBarEx();

	void SetScrollBarExBk(BITMAPOBJ hbmpScrollbarExN, BITMAPOBJ hbmpScrollbarExH, BITMAPOBJ hbmpScrollbarExS, BITMAPOBJ hbmpScrollbarExD);

	void SetScrollBarExThumb(BITMAPOBJ hbmpScrollbarExThumbN, BITMAPOBJ hbmpScrollbarExThumbH, BITMAPOBJ hbmpScrollbarExThumbS, BITMAPOBJ hbmpScrollbarExThumbD);
	void GetScrollBarExThumb(BITMAPOBJ *phbmpScrollbarExThumbN, BITMAPOBJ *phbmpScrollbarExThumbH, BITMAPOBJ *phbmpScrollbarExThumbS, BITMAPOBJ *phbmpScrollbarExThumbD);

	void SetScrollBarExLTUPButton(int nValue);
	int GetScrollBarExLTUPButton();

	void SetScrollBarExRTDNButton(int nValue);
	int GetScrollBarExRTDNButton();

	int HoldCtrlKey(BOOL bHold);
	BOOL IsHoldCtrlKey();

// Operations
public:
	void MoveItem(int nDest, int nSrc);
	BOOL DeleteSelectedItem();
	int  InsertItem(const LVITEM *pItem);
	int  InsertItem(int nItem, LPCTSTR lpszItem);
	int  InsertItem(int nItem, LPCTSTR lpszItem, HBITMAP hThumbnail);
	int  InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1);
	BOOL DeleteAllItems();
	BOOL DeleteItem(int nItem);
	BOOL EnsureVisible(int nItem, BOOL bPartialOK = TRUE);
	BOOL SelectAll(BOOL bSelected = TRUE);
	
	int HitTestDrop(CPoint point);
	int HitTest(CPoint pt, UINT *pFlags=NULL) const;
	void RefreshDisplay(BOOL bUpdateImmediately = TRUE);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThumbnailCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual int OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL


//Operations
protected:
	int GetSpace() const;
	void UpdateScrollingDisplay();
	BOOL IsValidIndex(int nIndex) const;
	void SelectByRect(LPRECT rcSel, BOOL bClear = TRUE);
	BOOL DoLButtonDown(UINT nFlags, CPoint point, BOOL bIsLButtonDown=TRUE);
	void DoMultipleSelection(BOOL bShift, BOOL bCtrl, int nPos, BOOL bIsLButtonDown=TRUE);
	CSize CalcThumbnailGrid() const;
	CDC *BeginRepaint();
	void EndRepaint(CDC* pDC);
	void BeginDrag(UINT nFlags, CPoint point);
	void EndDragSelect(POINT pt);
	BOOL OnMovementKey(UINT nChar);
	
	// Generated message map functions
protected:
	virtual void OnDraw(CDC* pDC);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	//{{AFX_MSG(CThumbnailCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	afx_msg BOOL OnToolTipNotify(UINT id, NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()

private:
	void *m_pMember;
};

/////////////////////////////////////////////////////////////////////////////
// CTreeListCtrl window

#ifdef _WIN32
#define WC_TREELISTVIEWA            "SysTreeListView32"
#define WC_TREELISTVIEWW            L"SysTreeListView32"

#ifdef UNICODE
#define  WC_TREELISTVIEW            WC_TREELISTVIEWW
#else
#define  WC_TREELISTVIEW            WC_TREELISTVIEWA
#endif

#else
#define WC_TREELISTVIEW             "SysTreeListView"
#endif


// Tree control's extended style
#define TVS_EX_GRIDLINES            0x00000001
#define TVS_EX_BKLINE               0x00000002
#define TVS_EX_OWNERDRAWFIXED       0x00000004

// Height of Header control
#define IDW_TREELIST                1
#define IDW_TREELISTHEADER          0

class CTreeList : public CTreeCtrl
{
// Construction
public:
	CTreeList();
	virtual ~CTreeList();

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeList)
	protected:
	;
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL
;
public:
	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1);

	BOOL SetItemTextEx(HTREEITEM hTI, int nCol, LPCTSTR lpszText);
	CString GetItemTextEx(HTREEITEM hTI, int nCol);

	void SetHeaderPtr(CSkinHeaderCtrl *pHeader);
	CSkinHeaderCtrl *GetHeaderCtrl();

	BOOL SetBkImage(BITMAPOBJ hbmN, BITMAPOBJ hbmD, BOOL bDeleteOld=TRUE);
	int GetBkImage(BITMAPOBJ *phbmN, BITMAPOBJ *phbmD);

	void SetTextFont(CFont *pFontN, CFont *pFontD = NULL);
	void GetTextFont(CFont **ppFontN, CFont **ppFontD = NULL);

	void SetHoverTime(DWORD dwHoverTime, BOOL bRepeat=FALSE);
	void GetHoverTime(DWORD *pdwHoverTime, BOOL *pbRepeat);

	int SetItemHeightEx(HTREEITEM hItem, UINT cyItemHeight);
	UINT GetItemHeightEx(HTREEITEM hItem);

	int ListIndexByHTREEITEM(HTREEITEM hTI);

	CListCtrl * GetListCtrl();

	// hide the same name interface in base class
private:
	// use SetTextFont
	void SetFont(CFont* pFont, BOOL bRedraw = TRUE);
	// use GetTextFont
	CFont* GetFont() const;
	// use SetItemTextEx
	BOOL SetItemText(HTREEITEM hItem, LPCTSTR lpszItem);
	// use GetItemTextEx
	CString GetItemText(HTREEITEM hItem) const;

	// Generated message map functions
protected:
	//{{AFX_MSG(CTreeList)
	;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	virtual void DrawItem(CDC *pDC, HTREEITEM hTI);

private:
	CListCtrl m_List; //temp to restor data
	CSkinHeaderCtrl *m_pHeader;
	COLORREF m_crSelectedBK;
	BITMAPOBJ m_hBackgroundBitmapN;
	BITMAPOBJ m_hBackgroundBitmapD;
	DWORD m_dwHoverTime;
	BOOL m_bHoverRepeat;
	CFont *m_pFontN;
	CFont *m_pFontD;
	BOOL m_bRedrawFlag; // only change this value by "USER", the CTreeList must not change it.
};

class CTreeListCtrl : public CWnd
{
	friend class CTreeList;
public:
	CTreeListCtrl();
	virtual ~CTreeListCtrl();
	BOOL Create(DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, UINT nID, 		int nHeaderHeight=24, BOOL bUseCustomScroll=FALSE, int nScrollWidth=16);

	// Init control by specify style.
	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeListCtrl)
	protected:
	;
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
;
public:
	CTreeList *GetTreeListWnd();
	CSkinHeaderCtrl *GetHeaderCtrl();
	CScrollBarEx *GetScrollBarEx();
	BOOL IsUseScrollBarEx();

	HTREEITEM InsertItem(LPCTSTR lpszItem, HTREEITEM hParent = TVI_ROOT, HTREEITEM hInsertAfter = TVI_LAST);
	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1);
	BOOL SetBkImage(BITMAPOBJ hbmpN, BITMAPOBJ hbmpD, BOOL bDeleteOld = TRUE);
	int GetBkImage(BITMAPOBJ *phbmpN, BITMAPOBJ *phbmpD);

	void SetScrollBarExBk(BITMAPOBJ hbmpScrollbarExN, BITMAPOBJ hbmpScrollbarExH, BITMAPOBJ hbmpScrollbarExS, BITMAPOBJ hbmpScrollbarExD);
	void SetScrollBarExThumb(BITMAPOBJ hbmpScrollbarExThumbN, BITMAPOBJ hbmpScrollbarExThumbH, BITMAPOBJ hbmpScrollbarExThumbS, BITMAPOBJ hbmpScrollbarExThumbD);
	void GetScrollBarExThumb(BITMAPOBJ *phbmpScrollbarExThumbN, BITMAPOBJ *phbmpScrollbarExThumbH, BITMAPOBJ *phbmpScrollbarExThumbS, BITMAPOBJ *phbmpScrollbarExThumbD);

	SHORT SetItemHeight(SHORT cyHeight);
	SHORT GetItemHeight() const;

	void UpdateScrollingDisplay();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTreeListCtrl)
	;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


private:
	void *m_pMember;
};

class CSkinRichEditCtrl : public CRichEditCtrl
{
// Construction
public:
	CSkinRichEditCtrl();
	virtual ~CSkinRichEditCtrl();

	// Init control by specify style.
	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinRichEditCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinRichEditCtrl)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////
// CHtmlCtrl

class CHtmlCtrl : public CHtmlView
{
public:
	CHtmlCtrl();
	virtual ~CHtmlCtrl();

	// Init control by specify style.
	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

// html Data
public:
	//{{AFX_DATA(CHtmlCtrl)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
;
public:
	void ShowBorder(BOOL bShow, BOOL bRedraw=TRUE);
	void ShowIEScrollBar(BOOL bShow, BOOL bRedraw=TRUE);
	void ShowContextMenu(BOOL bShow);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlCtrl)
	;
	public:
#if(_MSC_VER <= 1200)
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
#else
	virtual HRESULT OnGetHostInfo(DOCHOSTUIINFO *pInfo);
	virtual HRESULT OnShowContextMenu(DWORD dwID, LPPOINT ppt, LPUNKNOWN pcmdtReserved, LPDISPATCH pdispReserved);
#endif
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL
	virtual void PostNcDestroy(){}

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CHtmlCtrl)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void *m_pMember;
};

//////////////////////////////////////////////////////////////////////////
// class CSkinDateTimeCtrl

class CSkinDateTimeCtrl : public CDateTimeCtrl
{
public:
	CSkinDateTimeCtrl();
	virtual ~CSkinDateTimeCtrl();

	// Init control by specify style.
	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

public:

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinDateTimeCtrl)
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinDateTimeCtrl)
	// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////
// class CRectCtrl

class CRectCtrl : public CObject
{
public:
	CRectCtrl();
	~CRectCtrl();
	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	BOOL IsCreated() const;

public:
	int GetWindowText(CString& rString) const;
	CWnd *GetParent() const;

	int GetOrigWindowRect(LPRECT lpRect) const;
	int SetOrigWindowRect(LPCRECT lpRect);

	int GetWindowRect(LPRECT lpRect) const;
	int GetDlgCtrlID() const;

	int AddBindWindow(CWnd *pBindWindow);
	int DeleteBindWindow(CWnd *pBindWindow);

	int MoveWindow(LPCRECT lpRect);
	virtual BOOL DestroyWindow();

private:
	void *m_pMember;
};

class CWaveItem
{
public:
	CWaveItem();
	~CWaveItem();

public:
	LONGLONG m_llXOrdinate;
	LONGLONG m_llYOrdinate;
};

class CWave
{
public:
	CWave();
	~CWave();

public:
	int AddWaveItem(CWaveItem *pItem);
	CWaveItem *GetWaveItem(int nIndex);
	int GetWaveItemCount() const;
	int DeleteAllWaveItems();

	COLORREF SetWaveColor(COLORREF crWave);
	COLORREF GetWaveColor() const;

	UINT SetLineWidth(UINT nLineWidth);
	UINT GetLineWidth() const;

private:
	std::vector<CWaveItem *> m_vpWaveItem;
	COLORREF m_crWave;
	UINT m_nLineWidth;
};

enum WaveCtrl_Origin
{
	TOPLEFT,
	TOPRIGHT,
	BOTTOMLEFT,
	BOTTOMRIGHT,
};

class CWaveCtrl : public CWnd
{
	// Construction
public:
	CWaveCtrl();
	virtual ~CWaveCtrl();

	// Init control by specify style.
	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);

protected:
	virtual void OnDraw(CDC *pDC);
	virtual void DrawBackgroundAndGrid(CDC *pDC);
	virtual void DrawWaves(CDC *pDC);

public:
	// Properties
	WaveCtrl_Origin SetOrigin(WaveCtrl_Origin ewo, BOOL bRedraw = TRUE);
	WaveCtrl_Origin GetOrigin() const;

	int SetGridWidht(int nGridWidht, BOOL bRedraw = TRUE);
	int GetGridWidth() const;

	int SetGridHeight(int nGridHeight, BOOL bRedraw = TRUE);
	int GetGridHeight() const;

	int SetInfoAreaWidth(int nInfoAreaWidth, BOOL bRedraw = TRUE);
	int GetInfoAreaWidth() const;

	int SetInfoAreaHeight(int nInfoAreaHeight, BOOL bRedraw = TRUE);
	int GetInfoAreaHeight() const;

	COLORREF SetBkColor(COLORREF cr, BOOL bRedraw = TRUE);
	COLORREF GetBkColor() const;

	COLORREF SetGridLineColor(COLORREF cr, BOOL bRedraw = TRUE);
	COLORREF GetGridLineColor() const;

	int SetGridUnitX(int nX, BOOL bRedraw = TRUE);
	int GetGridUnitX() const;

	int SetGridUnitY(int nY, BOOL bRedraw = TRUE);
	int GetGridUnitY() const;

#ifdef USEGDIPLUS
	int EnableAntiAliasing(BOOL bEnableAntiAliasing);
	BOOL IsEnableAntiAliasing() const;
#endif

	// Scroll
	int SetScrollPos(int nPixel, BOOL bRedraw = TRUE);
	int GetScrollPos() const;

	int EnableDragMove(BOOL bEnableDragMove);
	BOOL IsEnableDragMove() const;

	// Wave
	int AddWave(CWave *pWave);
	CWave *GetWave(int nIndex);
	int DeleteWave(int nIndex);
	int DeleteWave(CWave *pWave);
	int DeleteAllWaves();
	int GetWaveCount() const;

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWaveCtrl)
protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CWaveCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	// 
	WaveCtrl_Origin m_eWaveCtrlOrigin;

	// Properties
	COLORREF m_crBackground;
	COLORREF m_crGridLine;
	int m_nInfoWidth;
	int m_nInfoHeight;
	int m_nGridWidth;
	int m_nGridHeight;
	int m_nGridUnitX;
	int m_nGridUnitY;
#ifdef USEGDIPLUS
	BOOL m_bEnableAntiAliasing;
#endif

	// Scroll control
	int m_nScrollPos;

	BOOL m_bEnableDragMove;
	BOOL m_bLButtonDown;
	CPoint m_ptLButtonDown;
	int m_nScrollPosOnLButtonDown;

	// for data
	std::vector<CWave *> m_vWaves;
};

#ifdef USEGDIPLUS

class CClockCtrl : public CWnd
{
// Construction
public:
	CClockCtrl();
	virtual ~CClockCtrl();

// Operations
public:
	int SetBitmap(BITMAPOBJ hbmpBk);
	BITMAPOBJ GetBitmap();
	int SetPointer(BITMAPOBJ hbmpPointer);
	BITMAPOBJ GetPointer();

	int SetRange(int nMix, int nMax);
	int GetRange(int *pnMix, int *pnMax);
	int SetPos(int nPos);
	int GetPos();

	int SetBkCenter(LPPOINT pt);
	int GetBkCenter(LPPOINT pt);
	int SetPtCenter(LPPOINT pt);
	int GetPtCenter(LPPOINT pt);

protected:
	virtual void OnDraw(CDC *pDC);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClockCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CClockCtrl)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


private:
	void *m_pMember;
};

#endif // USEGDIPLUS


class CSkinMenuItem
{
public:
	DWORD m_dwMagicNum;	// A magic number to distingush our data
	DWORD m_dwID;		// Menu ID
	bool m_bSeparator;	// Separator
	bool m_bSideBar;	// A gradient sidebar
	CString m_strText;	// Menu item text
	HICON m_hIcon;		// Menu icon
	int m_nSize;		// Height of the item(Width of the sidebar if m_bSideBar is true)
	class CSkinMenu *m_pSkinMenu;	// The pointer of pop-up menu

public:
	CSkinMenuItem() 
	{
		m_dwMagicNum = 0x0505a0a0;
		m_dwID = 0;
		m_bSeparator = false;
		m_bSideBar = false;
		m_hIcon = NULL;
		m_nSize = 16;
		m_pSkinMenu = NULL;
	};

	virtual ~CSkinMenuItem()
	{
		if (m_hIcon)
			::DestroyIcon(m_hIcon);
	}

	BOOL IsMyData() { return m_dwMagicNum == 0x0505a0a0; };
};

class CSkinMenu : public CMenu  
{
	DECLARE_DYNAMIC(CSkinMenu)

public:
	CSkinMenu();
	virtual ~CSkinMenu();

	// Call if need before the menu bar be created.
	virtual int BindStyle(LPCTSTR lpszStyleID);
	virtual int BindStyle(const CTRLPROPERTIES *pCtrlProp);
	virtual int BindStyle(const MENUMEMBER *pMenuMember);

	int Release(); //Clean all memory and handles

protected:
	int FillRect(CDC *pDC, const CRect& rc, COLORREF color);

protected:
	// Message and virtual
	static LRESULT OnMenuChar(UINT nChar, UINT nFlags, CMenu* pMenu);

	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

protected:
	virtual int DrawSideBar(CDC *pDC, const CRect &rcItem, HICON hIcon, CString strText);
	virtual int DrawSeparator(CDC *pDC, const CRect &rcItem);
	virtual int DrawGeneralItem(CDC *pDC, const CRect &rcItem, LPDRAWITEMSTRUCT lpdis);
	virtual int DrawGeneralItemState(CDC *pDC, const CRect &rcItem, LPDRAWITEMSTRUCT lpdis, const MENU_ITEM_PROPERTIES *pmip);

	virtual int DrawColorBackGround(CDC *pDC, CRect rect, BOOL bSelected, BOOL bDisabled);
	virtual int DrawIconArea(CDC *pDC, CRect rect, BOOL bSelected, BOOL bDisabled, BOOL bChecked);
	virtual int DrawButton(CDC *pDC, CRect rect, BOOL bSelected, BOOL bDisabled, BOOL bChecked);
	virtual int DrawIcon(CDC *pDC, CRect rect, HICON hIcon, BOOL bSelected, BOOL bDisabled);
	virtual int DrawEmbossed(CDC *pDC, HICON hIcon, CRect rect, BOOL bColor = FALSE);
	virtual int DrawCheckMark(CDC *pDC, CRect rect, BOOL bSelected);
	virtual int DrawMenuText(CDC& dc, CRect rc, CString text, COLORREF color);
	virtual int DrawText(CDC *pDC, CRect rect, CString strText, BOOL bSelected, BOOL bDisabled, BOOL bBold);

	// Below is the functions to build the menu
public:
	// Hide CMenu::LoadMenu
	BOOL LoadMenu(UINT nIDResource);
	BOOL LoadMenu(LPCTSTR lpszResourceName);

	CSkinMenu* CopyMenu(HMENU hMenuFrom, CSkinMenu *pMenuTo);
	BOOL AppendSkinPopup(UINT nFlags, CSkinMenu *pPopupMenuTo, DWORD dwID, LPCTSTR strText);
	BOOL AppendSkinMenuString(UINT nFlags, DWORD dwID, LPCTSTR strText, HICON hIcon = NULL, ACCEL *pAccel = 0);
	BOOL AppendSkinSeparator();

	BOOL AddSideBar(int nSize = 32, LPCTSTR strText = NULL, HICON hIcon = NULL, DWORD dwID = 0);
	BOOL InsertSkinMenu(UINT nPos, UINT nFlags, CSkinMenuItem *pItem);

	void Break();		//change a column(the next item added will be in a new column)
	void BreakBar();	//change a column with a break line(same as Break, except that a break line is drawn between two columns)

	BOOL SetIcon(UINT nID, HICON *hIcon, BOOL bByPos=FALSE); //add an icon to the given item

	// Hide the CMenu::TrackPopupMenu
	BOOL TrackPopupMenu(UINT nFlags, int x, int y, CWnd* pWnd, LPCRECT lpRect = NULL);

	// Find the pop-up menu from a menu item id, you may not need it
	CSkinMenu *FindSubMenuFromID(DWORD dwID);

public:
	// Menu border
	int SetMenuBorderStyle(MENU_BORDER_STYLE eMbs);
	MENU_BORDER_STYLE GetMenuBorderStyle() const;

	int SetFlatMenuBorderColor(COLORREF crBorder);
	COLORREF GetFlatMenuBorderColor() const;

	// Height of the menu item
	int SetItemHeight(int nHeight);
	int GetItemHeight() const;

	// Normal item
	int SetNormalItemTextColor(COLORREF crItemText);
	COLORREF GetNormalItemTextColor() const;

	int SetNormalItemFont(const LOGFONT *plf);
	int GetNormalItemFont(LOGFONT *plf) const;

	int SetNormalItemBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetNormalItemBkType() const;

	int SetNormalItemBkColor(COLORREF crItemBk);
	COLORREF GetNormalItemBkColor() const;

	int SetNormalItemBkImage(BITMAPOBJ hBmpItem, BOOL bDeleteOld = TRUE);
	int GetNormalItemBkImage(BITMAPOBJ *phBmpItem) const;

	int SetNormalItemResizePoint(LPPOINT lpPt);
	int GetNormalItemResizePoint(LPPOINT lpPt) const;

	// Highlight item
	int SetHighlightItemTextColor(COLORREF crItemText);
	COLORREF GetHighlightItemTextColor() const;

	int SetHighlightItemFont(const LOGFONT *plf);
	int GetHighlightItemFont(LOGFONT *plf) const;

	int SetHighlightItemBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetHighlightItemBkType() const;

	int SetHighlightItemBkColor(COLORREF crItemBk);
	COLORREF GetHighlightItemBkColor() const;

	int SetHighlightItemBkImage(BITMAPOBJ hBmpItem, BOOL bDeleteOld = TRUE);
	int GetHighlightItemBkImage(BITMAPOBJ *phBmpItem) const;

	int SetHighlightItemResizePoint(LPPOINT lpPt);
	int GetHighlightItemResizePoint(LPPOINT lpPt) const;

	// Disabled item
	int SetDisabledItemTextColor(COLORREF crItemText);
	COLORREF GetDisabledItemTextColor() const;

	int SetDisabledItemFont(const LOGFONT *plf);
	int GetDisabledItemFont(LOGFONT *plf) const;

	int SetDisabledItemBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetDisabledItemBkType() const;

	int SetDisabledItemBkColor(COLORREF crItemBk);
	COLORREF GetDisabledItemBkColor() const;

	int SetDisabledItemBkImage(BITMAPOBJ hBmpItem, BOOL bDeleteOld = TRUE);
	int GetDisabledItemBkImage(BITMAPOBJ *phBmpItem) const;

	int SetDisabledItemResizePoint(LPPOINT lpPt);
	int GetDisabledItemResizePoint(LPPOINT lpPt) const;

	// SideBar
	int SetSideBarStartColor(COLORREF crSideBarStart);
	COLORREF GetSideBarStartColor() const;

	int SetSideBarEndColor(COLORREF crSideBarEnd);
	COLORREF GetSideBarEndColor() const;

	// Separator
	int SetSeparatorBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetSeparatorBkType() const;

	int SetSeparatorColor(COLORREF crSeparator);
	COLORREF GetSeparatorColor() const;

	int SetSeparatorLeftMargin(int nLeftMargin);
	int GetSeparatorLeftMargin() const;

	int SetSeparatorRightMargin(int nRightMargin);
	int GetSeparatorRightMargin() const;

	int SetSeparatorBkImage(BITMAPOBJ hBmpSeparator, BOOL bDeleteOld = TRUE);
	int GetSeparatorBkImage(BITMAPOBJ *phBmpSeparator) const;

	int SetSeparatorBkImageResizePoint(LPPOINT lpPt);
	int GetSeparatorBkImageResizePoint(LPPOINT lpPt) const;

	// Icon area
	int SetIconAreaWidth(int nWidth);
	int GetIconAreaWidth() const;

	int SetIconAreaStartColor(COLORREF crIconAreaStart);
	COLORREF GetIconAreaStartColor() const;

	int SetIconAreaEndColor(COLORREF crIconAreaEnd);
	COLORREF GetIconAreaEndColor() const;

protected:
	MENUMEMBER m_MenuMember;
};

//////////////////////////////////////////////////////////////////////////
// CMemStdioFile

class CMemStdioFile : public CMemFile  
{
public:
	CMemStdioFile();
	virtual ~CMemStdioFile();
	virtual BOOL OpenResource(LPCTSTR lpszID, LPCTSTR lpszType);

public:
	BOOL IsUnicode();

	virtual BOOL ReadString(CString& rString);
	virtual BOOL ReadStringA(std::string &rstring);
	virtual BOOL ReadStringW(std::wstring &rstring);
};

//////////////////////////////////////////////////////////////////////////
// CUIWndBase

class CUIWndBase : public CWnd
{
	DECLARE_DYNCREATE(CUIWndBase)

public:
	CUIWndBase(CWnd* pParentWnd = NULL);	// pParentWnd only for modal window
	virtual ~CUIWndBase();

protected:
	HWND PreModal();
	void PostModal();

	// Hit Test the point for resizing the window, if bSetCursor is TRUE, set the cursor for the window
	int HitTest(CPoint pt, BOOL bSetCursor);

	int SetLayeredWindow(BOOL bSet);
	virtual void OnDraw(CDC *pMemDC);
	virtual int UpdateUIWindow(int nTransparent = 255);

public:
	int DoModal(DWORD dwStyle = 0);
	void EndDialog(int nResult);

public:
	int SetTitleBarHeight(int nTitleBarHeight);
	int GetTitleBarHeight() const;

	int SetScrollSize(CSize size);
	int GetScrollSize(CSize *pSize) const;

	int SetCXBorder(int cx);
	int GetCXBorder() const;

	int SetCYBorder(int cy);
	int GetCYBorder() const;

	int SetDragResizeFlag(BOOL bDragResize);
	BOOL GetDragResizeFlag() const;

	int UseLayeredWindow(BOOL bUsed);
	BOOL IsUseLayeredWindow() const;

	int Refresh();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUIWndBase)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CUIWndBase)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
private:
	void *m_pMember;
	CWnd* m_pParentWnd;             // parent/owner window
};

//////////////////////////////////////////////////////////////////////////
// CUIWnd

class CIUIMultiDocTemplate;
class CIUIFrameWnd;
class CIUIMDIFrameWnd;
class CIUIMDIClientWnd;
class CIUIView;
class CTaskWndMgr;

class CUIWnd : public CWnd
{
	DECLARE_DYNCREATE(CUIWnd)

public:
	CUIWnd(CWnd* pParentWnd = NULL);	// pParentWnd only for modal window
	virtual ~CUIWnd();

public:
	BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, CRectCtrl *pRectCtrl, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, BOOL bLoadBkImageFromFile=TRUE, BOOL bUseLayeredWindow=TRUE);
	DWORD GetLastCreateError();

	// As dialog
	int DoModal(DWORD dwStyle = 0);
	void EndDialog(int nResult);

protected:
	// As dialog
	virtual void OnOK();
	virtual void OnCancel();

public:
	;
	int SetScrollSize(CSize size);
	int GetScrollSize(CSize *pSize);
	int GetCXBorder();
	int SetCXBorder(int cx);
	int GetCYBorder();
	int SetCYBorder(int cy);

	int SetDragResizeFlag(BOOL bDragResize);
	BOOL GetDragResizeFlag() const;

	// Set the repeat pixel while stretch the background image
	int SetXRepeatPixel(UINT nPixel);
	UINT GetXPepeatPixel() const;
	int SetYRepeatPixel(UINT nPixel);
	UINT GetYPepeatPixel() const;

	int GetBackgroundImageSize(CSize *pSize);
	int GetOriginalClientAreaRect(LPRECT lpRect);
	int GetClientAreaRect(LPRECT lpRect);
	int ResizeRect(LPCRECT lpRectSrc, LPRECT lpRectResized);
	CRectCtrl *GetRectChild(int nRectID);

	int SetBkImage(UINT uID, UINT uIDN, UINT uIDH, UINT uIDS, UINT uIDD, BOOL bDeleteOld=TRUE, BOOL bResetSize=TRUE);
	int SetBkImage(BITMAPOBJ hbmp, BITMAPOBJ hbmpN, BITMAPOBJ hbmpH, BITMAPOBJ hbmpS, BITMAPOBJ hbmpD, BOOL bDeleteOld=TRUE, BOOL bResetSize=TRUE);
	int SetBkImage(BITMAPOBJ hbmp, BOOL bDeleteOld=TRUE);
	BITMAPOBJ GetBkImage();

	int SetUIWndProperties(const UIWNDPROPERTIES *pProperties);
	const UIWNDPROPERTIES *GetUIWndProperties();

	int SetLoadBkImageFromFile(BOOL bFromFile);
	BOOL IsLoadBkImageFromFile() const;

	int UseLayeredWindow(BOOL bUsed);
	BOOL IsUseLayeredWindow() const;

	int AutoResetRgn(BOOL bAuto);
	BOOL IsAutoResetRgn() const;

	int Refresh();

	UINT GetDefaultMenuID();
	CIUIFrameWnd* GetParentFrame() const;

	// for CTaskWndMgr
	int AddTaskWndMgr(CTaskWndMgr *pMgr);

	// for frame
	// Get the top CIUIFrameWnd from this to its parent.
	CIUIFrameWnd* GetTopLevelFrame() const; ///
	// Get the top CIUIFrameWnd from its children.
	CIUIFrameWnd* GetTopIUIFrame() const;

protected:
	virtual void WindowID() { ASSERT(FALSE); } 
	HWND PreModal();
	void PostModal();

protected:
	virtual void OnDraw(CDC *pMemDC);
	virtual int DrawChildren(CDC *pMemDC);
	virtual int RelayoutElements(const CRect &rcChild, const CPoint &ptResize, CRect &rcNew, int nWindowWidth, int nWindowHeight, CONTROL_LAYOUT_HOR eHorLayoutMode, CONTROL_LAYOUT_VER eVerLayoutMode);

	int SetLayeredWindow(BOOL bSet);
public:
	virtual int UpdateUIWindow(int nTransparent = 255);

protected:
	// provide your own images for background, by default, LibUIDK get theme from the path set in .ui file.
	virtual int InitGdiObject(BITMAPOBJ *pbmpBase, BITMAPOBJ *pbmpN, BITMAPOBJ *pbmpH, BITMAPOBJ *pbmpS, BITMAPOBJ *pbmpD, BOOL *pbDeleteObjAfterUsed);

	// When resizing the window, reset images for child. if bForceSet is TRUE, always set the image, otherwise, only set that needed.
	int SetChildImage(BITMAPOBJ bmpN, BITMAPOBJ bmpH, BITMAPOBJ bmpS, BITMAPOBJ bmpD);

	// Hit Test the point for resizing the window, if bSetCursor is TRUE, set the cursor for the window
	int HitTest(CPoint pt, BOOL bSetCursor);

	BOOL IsChildNeedResize(LPCRECT rect);

	void ReleaseGdiObject();
	void InitPath();
	int Init();

private:
	BOOL AdjustChildControls();
	BOOL CreateChildControls(BITMAPOBJ bmpN, BITMAPOBJ bmpH, BITMAPOBJ bmpS, BITMAPOBJ bmpD);
	BOOL DestroyChildControls();

protected:
	UINT IDD;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUIWnd)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CUIWnd)
	afx_msg void OnPaint();
	afx_msg LRESULT OnChildMove(WPARAM wParam, LPARAM lParam);
	afx_msg void OnInitMenuPopup(CMenu*, UINT, BOOL);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
private:
	void *m_pMember;
	CWnd* m_pParentWnd;             // parent/owner window
};

/////////////////////////////////////////////////////////////////////////////
// CMenuBar window. Support attach or load menu.

class CMenuBar : public CWnd, CControlBase
{
	friend class CIUIMultiDocTemplate;
	friend class CIUIDocument;

// Construction
public:
	CMenuBar();
	virtual ~CMenuBar();

	BOOL Create(DWORD dwStyle, CRect rect, CWnd* pParentWnd, UINT nWinID);
	BOOL Create(DWORD dwStyle, CRect rect, CWnd* pParentWnd, UINT nWinID, UINT nMenuID, BITMAPOBJ hCombineImage);
	BOOL Create(DWORD dwStyle, CRect rect, CWnd* pParentWnd, UINT nWinID, UINT nMenuID, BITMAPOBJ hBmpN, BITMAPOBJ hBmpH, BITMAPOBJ hBmpS, BITMAPOBJ hBmpD);

	// Call if need before the menu bar be created.
	virtual int BindMenuStyle(LPCTSTR lpszStyleID);
	virtual int BindMenuStyle(const CTRLPROPERTIES *pCtrlProp);
	CTRLPROPERTIES *GetBindMenuStyle() const;

	int ReleaseMenuButton();

protected:
	int RebuildMenuBar();
	int RelayoutMenuBarButton(CSkinButton *pMenuButton, int nImageHeight, int &nLeft, int &nTotalWidth);
	int SetMenuButtonProperty(CSkinButton *pMenuButton);

	// For menu bar and menu bar button
public:
	int SetMenuID(UINT uMenuID);
	int SetHMENU(HMENU hMenu);
	CSkinMenu *GetSkinMenu();

	// Pop-up menu
	int PopupMenu(UINT uButtonID);

	int SetMenuButtonImages(BITMAPOBJ hBmpN, BITMAPOBJ hBmpH, BITMAPOBJ hBmpS, BITMAPOBJ hBmpD, BOOL bDeleteOld = TRUE);
	int SetMenuButtonImages(BITMAPOBJ hCombineImage, BOOL bDeleteOld = TRUE);
	int GetMenuButtonImages(BITMAPOBJ *phBmpN, BITMAPOBJ *phBmpH, BITMAPOBJ *phBmpS, BITMAPOBJ *phBmpD) const;

	int SetMenuButtonTextColor(COLORREF crN, COLORREF crH, COLORREF crS, COLORREF crD, BOOL bRedraw = TRUE);
	int GetMenuButtonTextColor(COLORREF *pcrN, COLORREF *pcrH, COLORREF *pcrS, COLORREF *pcrD) const;

	// font of button's text
	int SetMenuButtonTextFont(CFont *pFontN, CFont *pFontH, CFont *pFontS, CFont *pFontD, BOOL bRedraw = TRUE);
	int GetMenuButtonTextFont(CFont **pFontN, CFont **pFontH, CFont **pFontS, CFont **pFontD) const;

	int SetMenuButtonImageResizePoint(LPPOINT pt);
	int GetMenuButtonImageResizePoint(LPPOINT pt) const;

	// For menu and menu item
public:
	// Menu border
	int SetMenuBorderStyle(MENU_BORDER_STYLE eMbs);
	MENU_BORDER_STYLE GetMenuBorderStyle() const;

	int SetFlatMenuBorderColor(COLORREF crBorder);
	COLORREF GetFlatMenuBorderColor() const;

	// Height of the menu item
	int SetMenuItemHeight(int nHeight);
	int GetMenuItemHeight() const;

	// Normal item
	int SetNormalMenuItemTextColor(COLORREF crMenuItemText);
	COLORREF GetNormalMenuItemTextColor() const;

	int SetNormalMenuItemFont(const LOGFONT *plf);
	int GetNormalMenuItemFont(LOGFONT *plf) const;

	int SetNormalMenuItemBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetNormalMenuItemBkType() const;

	int SetNormalMenuItemBkColor(COLORREF crMenuItemBk);
	COLORREF GetNormalMenuItemBkColor() const;

	int SetNormalMenuItemBkImage(BITMAPOBJ hBmpMenuItem, BOOL bDeleteOld = TRUE);
	int GetNormalMenuItemBkImage(BITMAPOBJ *phBmpMenuItem) const;

	int SetNormalMenuItemResizePoint(LPPOINT lpPt);
	int GetNormalMenuItemResizePoint(LPPOINT lpPt) const;

	// Highlight item
	int SetHighlightMenuItemTextColor(COLORREF crMenuItemText);
	COLORREF GetHighlightMenuItemTextColor() const;

	int SetHighlightMenuItemFont(const LOGFONT *plf);
	int GetHighlightMenuItemFont(LOGFONT *plf) const;

	int SetHighlightMenuItemBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetHighlightMenuItemBkType() const;

	int SetHighlightMenuItemBkColor(COLORREF crMenuItemBk) const;
	COLORREF GetHighlightMenuItemBkColor() const;

	int SetHighlightMenuItemBkImage(BITMAPOBJ hBmpMenuItem, BOOL bDeleteOld = TRUE);
	int GetHighlightMenuItemBkImage(BITMAPOBJ *phBmpMenuItem) const;

	int SetHighlightMenuItemResizePoint(LPPOINT lpPt);
	int GetHighlightMenuItemResizePoint(LPPOINT lpPt) const;

	// Disabled item
	int SetDisabledMenuItemTextColor(COLORREF crMenuItemText);
	COLORREF GetDisabledMenuItemTextColor() const;

	int SetDisabledMenuItemFont(const LOGFONT *plf);
	int GetDisabledMenuItemFont(LOGFONT *plf) const;

	int SetDisabledMenuItemBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetDisabledMenuItemBkType() const;

	int SetDisabledMenuItemBkColor(COLORREF crMenuItemBk) const;
	COLORREF GetDisabledMenuItemBkColor() const;

	int SetDisabledMenuItemBkImage(BITMAPOBJ hBmpMenuItem, BOOL bDeleteOld = TRUE);
	int GetDisabledMenuItemBkImage(BITMAPOBJ *phBmpMenuItem) const;

	int SetDisabledMenuItemResizePoint(LPPOINT lpPt);
	int GetDisabledMenuItemResizePoint(LPPOINT lpPt) const;

	// SideBar
	int SetSideBarStartColor(COLORREF crSideBarStart);
	COLORREF GetSideBarStartColor() const;

	int SetSideBarEndColor(COLORREF crSideBarEnd);
	COLORREF GetSideBarEndColor() const;

	// Separator
	int SetSeparatorBkType(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetSeparatorBkType() const;

	int SetSeparatorColor(COLORREF crSeparator);
	COLORREF GetSeparatorColor() const;

	int SetSeparatorLeftMargin(int nLeftMargin);
	int GetSeparatorLeftMargin() const;

	int SetSeparatorRightMargin(int nRightMargin);
	int GetSeparatorRightMargin() const;

	int SetSeparatorBkImage(BITMAPOBJ hBmpSeparator, BOOL bDeleteOld = TRUE);
	int GetSeparatorBkImage(BITMAPOBJ *phBmpSeparator) const;

	int SetSeparatorBkImageResizePoint(LPPOINT lpPt);
	int GetSeparatorBkImageResizePoint(LPPOINT lpPt) const;

	// Icon area
	int SetIconAreaWidth(int nWidth);
	int GetIconAreaWidth() const;

	int SetIconAreaStartColor(COLORREF crIconAreaStart);
	COLORREF GetIconAreaStartColor() const;

	int SetIconAreaEndColor(COLORREF crIconAreaEnd);
	COLORREF GetIconAreaEndColor() const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuBar)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL


	// Generated message map functions
protected:
	//{{AFX_MSG(CMenuBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEnterMenuLoop(BOOL bIsTrackPopupMenu);
	afx_msg void OnExitMenuLoop(BOOL bIsTrackPopupMenu);
	afx_msg LRESULT OnMenuMouseMove(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CSkinMenu m_menuBar;
	void *m_pMember;
};

//////////////////////////////////////////////////////////////////////////
// CMenuWnd

class CMenuWnd : public CUIWnd
{
public:
	CMenuWnd();
	virtual ~CMenuWnd();
	virtual BOOL Create(CWnd *pParentWnd);

public:
	virtual int Popup(int x, int y);	// CPoint(x, y): the arrow point
	virtual int Hide();

	void SetNotifyWnd(CWnd *pWnd);
	CWnd *GetNotifyWnd();


	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuWnd)
protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CMenuWnd)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CWnd *m_pNotifyWnd;
};

#ifdef USEGDIPLUS

class CSubtitleWnd : public CUIWndBase
{
// Construction
public:
	CSubtitleWnd();
	virtual ~CSubtitleWnd();

	BOOL Create(DWORD dwExStyle, DWORD dwStyle, LPCTSTR lpszWindowName, const RECT& rect, CWnd* pParentWnd, CCreateContext* pContext = NULL);

public:
	// Window background
	int ShowWindowBackground(BOOL bShow);
	BOOL IsWindowBackgroundVisible() const;

	int SetWindowTransparent(int nTransparent);	// 0-255
	int GetWindowTransparent() const;

	int SetWindowBkColor(Color crBk);
	Color GetWindowBkColor() const;

	// Line
	int SetLineCount(int nCount);
	int GetLineCount() const;

	int SetLineSpacing(int nLineSpacing);
	int GetLineSpacing() const;

	// Stroke
	int EnableStroke(BOOL bEnable);
	BOOL IsStrokeEnabled() const;

	int SetStrokeColor(Color crStroke);
	Color GetStrokeColor() const;

	int SetStrokeCount(int nCount);
	int GetStrokeCount() const;

	// Shadow
	int EnableShadow(BOOL bEnable);
	BOOL IsShadowEnabled() const;

	// Text
	int SetSubtitle(int nLine, LPCTSTR lpszSubtitle, BOOL bRedraw = TRUE);
	int GetSubtitle(int nLine, CString &strSubtitle) const;

	int SetFont(CFont *pFont);
	int GetFont(CFont *pFont) const;

	int EnableKaraokeMode(BOOL bEnable);
	BOOL IsKaraokeModeEnabled() const;

	// Set background of played text
	int SetPlayedTextBackgroundMode(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetPlayedTextBackgroundMode() const;

	int SetPlayedTextBkColor(const std::vector<Color> *pvColors);
	int GetPlayedTextBkColor(std::vector<Color> *pvColors) const;

	int SetPlayedTextBkImage(BITMAPOBJ hBmpBk);
	int GetPlayedTextBkImage(BITMAPOBJ *phBmpBk) const;

	// Set background of will be playing text
	int SetPlayingTextBackgroundMode(BACKGROUND_TYPE eBkType);
	BACKGROUND_TYPE GetPlayingTextBackgroundMode() const;

	int SetPlayingTextBkColor(const std::vector<Color> *pvColors);
	int GetPlayingTextBkColor(std::vector<Color> *pvColors) const;

	int SetPlayingTextBkImage(BITMAPOBJ hBmpBk);
	int GetPlayingTextBkImage(BITMAPOBJ *phBmpBk) const;

	// Scroll
	int SetRange(int nMix, int nMax);
	int GetRange(int *pnMix, int *pnMax) const;

	int SetPos(int nPos);
	int GetPos() const;

public:
	int Refresh();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubtitleWnd)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CSubtitleWnd)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void *m_pMember;
};

#endif // USEGDIPLUS

//////////////////////////////////////////////////////////////////////////
// CUIMgr parse and save *.xui

class CUIMgr
{
public:
	CUIMgr();
	virtual ~CUIMgr();

public:
	// Path
	static int SetUIPath(LPCTSTR lpszUIPath, BOOL bCheckVersion = TRUE);
	static int SetUIPath(LPCTSTR lpszUIID, LPCTSTR lpszResouceID, LPCTSTR lpszResourceType);
	static int SetSource(LPCTSTR lpszUIPath);

	static CString GetUIPath();
	static CString GetUIResourcePath();
	static CString GetUIPathWithoutTitle();

	// Load, save and release skin
	static int LoadSkin();
	static int LoadIDDefined();
	static int SaveSkin(int nChangeListNumber);
	static int SaveIDDefined();
	static int ReleaseSkin();

	// Version
	static LONG GetCurrentMajorVersion();
	static LONG GetCurrentMinorVersion();
	static LONG GetCurrentBuildVersion();
	static LONG GetHighestMajorVersion();
	static LONG GetHighestMinorVersion();
	static LONG GetHighestBuildVersion();

	// DPI
	static LONG GetLogPixelsX();
	static LONG GetLogPixelsY();
	static int EnableDPI(BOOL bEnable);
	static BOOL IsEnableDPI();

	// Window
	static UIWNDPROPERTIES *AllocUIWNDPROPERTIES();
	static int FreeUIWNDPROPERTIES(UIWNDPROPERTIES *pUIProp);
	static int GetWindowCount();
	static UIWNDPROPERTIES *GetWindowItem(int nIndex);
	static int AddWindowItem(UIWNDPROPERTIES *pWindow);
	static int DeleteWindowItem(int nIndex);
	static int DeleteAllWindowItems();
	static int GetWindowIndex(const UIWNDPROPERTIES *pUIProp);
	static int GetWindowIndex(const CString &strWindowID);
	static int SwapWindowItem(int nFirst, int nLast);
	static std::vector<UIWNDPROPERTIES *> *GetUIWndPropertiesList();
	static UIWNDPROPERTIES *GetUIWNDPROPERTIES(LPCTSTR lpszWindowID);
	static int InitRunningUIWnd();

	// Resource
	static int GetResourceCount(RESOURCE_TYPE eResType);
	
	static int AddResourceItem(RESOURCE_TYPE eResType, CTRLPROPERTIES *pResource);

	static int DeleteResourceItem(RESOURCE_TYPE eResType, int nIndex);
	static int DeleteResourceItem(RESOURCE_TYPE eResType, const CTRLPROPERTIES *pResProp);

	static CTRLPROPERTIES *GetResourceItem(RESOURCE_TYPE eResType, int nIndex);
	static CTRLPROPERTIES *GetResourceItem(RESOURCE_TYPE eResType, LPCTSTR lpszResID);

	// Font
	static int GetFontResource(LPCTSTR lpszResID, LOGFONT *plf);
	static RESFONTPROPERTIES *FindFontResource(const IUI_VARIANT &varFont);

	// Color
	static int GetColorResource(LPCTSTR lpszResID, COLORREF *pcr);
	static RESCOLORPROPERTIES *FindColorResource(const IUI_VARIANT &varColor);

	// Style
	static int GetStyleCount(STYLE_TYPE eStyleType);

	static int AddStyleItem(STYLE_TYPE eStyleType, CTRLPROPERTIES *pStyle);

	static int DeleteStyleItem(STYLE_TYPE eStyleType, int nIndex);
	static int DeleteStyleItem(STYLE_TYPE eStyleType, const CTRLPROPERTIES *pStyleProp);

	static CTRLPROPERTIES *GetStyleItem(STYLE_TYPE eStyleType, int nIndex);
	static CTRLPROPERTIES *GetStyleItem(STYLE_TYPE eStyleType, LPCTSTR lpszStyleID);

	// Control
	// Get the first control by lpszCtrlID within window lpszWindowID.
	static CTRLPROPERTIES *GetCONTROL(LPCTSTR lpszWindowID, LPCTSTR lpszCtrlID);
	// Get the first control use the image 'lpszImage'.
	static CTRLPROPERTIES *GetCONTROL(LPCTSTR lpszImage);

	// Multi-Language
	static int CreateIniLanguageFile(LPCTSTR lpszLanguageFile);
	static int LoadIniLanguageFile(LPCTSTR lpszLanguageFile);
	static int SwitchIniLanguage(LPCTSTR lpszLanguageFile);
	static int SwitchIniLanguageOnRunTime(LPCTSTR lpszLanguageFile);

	static RECT MAKERECT(LPCTSTR lpszRect);
	static int StringIDToInt(LPCTSTR lpszIDs);
	static CString StringIDFromInt(int nID);
protected:

	static int ConvertUI2CurVer();	// convert *.ui to *.xui and save it
	static int ConvertXUI2CurVer();	// convert old version of xui file to current version.
	static int PromptConvert();

private:
	static void LicenseWarning()
	{
		AfxMessageBox(_T("This libarary hasn't been licensed! register it from http://www.iuishop.com"));
		ASSERT(FALSE);
	}

private:
	static BOOL m_bLoadFromFile;
	static BOOL m_bConverting;

	// for hard disk skin
	static CString m_strUIPath;
	static CString m_strUIPathWithoutTitle;
	static CString m_strUIResourcePath;

	// for resource skin
	static CString m_strUIID;
	static CString m_strUIResourcehID;
	static CString m_strUIResourceType;

	// for version
	static LONG m_lCurrentMajorVersion;
	static LONG m_lCurrentMinorVersion;
	static LONG m_lCurrentBuildVersion;
	static LONG m_lHighestMajorVersion;
	static LONG m_lHighestMinorVersion;
	static LONG m_lHighestBuildVersion;

	// for DPI
	static BOOL m_bEnableDPI;
	static LONG m_lLogPixelsX;
	static LONG m_lLogPixelsY;

	// for *.xui and resource.h
	static std::vector<UIWNDPROPERTIES *> m_vpWindows;
	static std::vector<std::pair<CString, int> > m_vIDs;
	static CMemStdioFile m_fileResourceH;

	// Resource
	static std::vector<RESFONTPROPERTIES *> m_vpFontRes;
	static std::vector<RESCOLORPROPERTIES *> m_vpColorRes;

	// Style
	static std::vector<BTNPROPERTIES *> m_vpStylePushButton;
	static std::vector<CHKPROPERTIES *> m_vpStyleCheckBox;
	static std::vector<RADPROPERTIES *> m_vpStyleRadioButton;
	static std::vector<CMBPROPERTIES *> m_vpStyleComboBox;
	static std::vector<TXTPROPERTIES *> m_vpStyleStatic;
	static std::vector<EDTPROPERTIES *> m_vpStyleEdit;
	static std::vector<SLDPROPERTIES *> m_vpStyleSlider;
	static std::vector<PRGPROPERTIES *> m_vpStyleProgress;
	static std::vector<SPNPROPERTIES *> m_vpStyleSpin;
	static std::vector<HOTPROPERTIES *> m_vpStyleHotKey;
	static std::vector<IPAPROPERTIES *> m_vpStyleIPAddress;
	static std::vector<SLDEXPROPERTIES *> m_vpStyleSliderEx;
	static std::vector<LSTCTRLPROPERTIES *> m_vpStyleListCtrl;
	static std::vector<TREECTRLPROPERTIES *> m_vpStyleTreeCtrl;
	static std::vector<TREELISTPROPERTIES *> m_vpStyleTreeList;
	static std::vector<RICHEDITPROPERTIES *> m_vpStyleRichEdit;
	static std::vector<HTMLCTRLPROPERTIES *> m_vpStyleHtmlCtrl;
	static std::vector<DATETIMECTRLPROPERTIES *> m_vpStyleDateTime;
	static std::vector<WAVECTRLPROPERTIES *> m_vpStyleWaveCtrl;
	static std::vector<RESMENUPROPERTIES *> m_vpStyleMenu;
	static std::vector<MENUBARPROPERTIES *> m_vpStyleMenuBar;
	static std::vector<RESHEADERPROPERTIES *> m_vpStyleHeader;
	static std::vector<HORSBPROPERTIES *> m_vpStyleHorScrollBar;
	static std::vector<VERSBPROPERTIES *> m_vpStyleVerScrollBar;

	// for multi-language
	static std::map<CString, CString> m_mapLanguage;			// m_mapLanguage["WindowID/ControlID"] = Caption
	static std::map<HWND, CString> m_mapCreatedHWndStringID;	// m_mapCreatedHWndStringID[HWND] = "WindowStringID"

public:
	// Next font resource ID for convert.
	static int m_nNextFontResID;
	// Next color resource ID for convert.
	static int m_nNextColorResID;
	// Next header resource ID for convert.
	static int m_nNextHeaderResID;
};

//////////////////////////////////////////////////////////////////////////
// CTaskWndMgr

#define WS_TASKSTYLE WS_VISIBLE|WS_CHILD|WS_CLIPCHILDREN|WS_CLIPSIBLINGS

class CTaskWndInfo
{
public:
	CTaskWndInfo();
	~CTaskWndInfo();

public:
	CWnd *m_pTaskWnd;
	UINT m_nTaskWndID;
	DWORD m_dwTaskWndCreateStyle;
	CString m_strWindowName;
};


class CTaskWndMgr
{
public:
	CTaskWndMgr(BOOL bVirtualTaskRadio=TRUE);	// bVirtualTaskRadio is TRUE: not use radio button to switch task window.
	virtual ~CTaskWndMgr();

public:
	int SetParent(CUIWnd *pParent);
	CUIWnd *GetParent();
	int SetPosWindow(CWnd *pPosWnd);
	CWnd *GetPosWindow();
	int SetPosRect(LPCRECT lpRect);
	int GetPosRect(LPRECT lpRect);
	BOOL IsPosRect();

	int AddTaskWindow(UINT nTaskRadioButton, CWnd *pTaskPanel, UINT nTaskWndID, LPCTSTR lpszWindowName = NULL, DWORD dwStyle = WS_TASKSTYLE);
	int RemoveTaskWindow(UINT nTaskRadioButton, BOOL bDestroyTaskWindow);
	int RemoveAllTaskWindows(BOOL bDestroyTaskWindow);
	int DestroyTaskWindow(UINT nTaskRadioButton);
	int GetTaskWindowCount();
	int SwitchToTaskWindow(UINT nID);
	int SwitchToTaskWindow(CSkinButton *pRadTask);
	int SwitchToTaskWindow(const CWnd *pTaskWnd);
	const CTaskWndInfo *FindTaskWindow(UINT nTaskRadioButton) const;
	CTaskWndInfo *FindTaskWindow(UINT nTaskRadioButton);
	const CTaskWndInfo *FindTaskWindow(CWnd *pTaskPaenl) const;
	CTaskWndInfo *FindTaskWindow(CWnd *pTaskPaenl);
	UINT GetTaskRadioButtonID(CWnd *pTaskPaenl);
	UINT GetCurrentTaskWindow() const;
	int AdjustTaskWindowPos(LPCRECT lpRect);

private:
	void *m_pMember;
};

//////////////////////////////////////////////////////////////////////////
// Panel

class CPanel : public CObject
{
public:
	CPanel();
	virtual ~CPanel();

public:
	virtual int InsertPanel(CPanel *pChildPanel, UINT nPos);
	virtual int RelayoutElements();

	BOOL IsCreated();
	CWnd *GetParent();

	int SetRect(LPCRECT lpcRect);
	int GetRect(LPRECT lpRect) const;

	int SetParentPanel(CPanel *pParentPanel);
	CPanel *GetParentPanel();

	int SetRedraw(BOOL bRedraw);
	int Redraw();

protected:
	CRect m_rect;
	CWnd *m_pParent;
	CPanel *m_pParentPanel;
	BOOL m_bRedraw;
};

struct STACK_ELEMENT
{
	STACK_ELEMENT_TYPE m_eSet;
	void *m_pElement;
};

class CStackPanel : public CPanel  
{
public:
	CStackPanel();
	virtual ~CStackPanel();
	BOOL Create(LPCRECT lpRect, CWnd *pParentWnd);

protected:
	static LRESULT ElementWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	virtual int RelayoutElements();

	int SetOrientation(STACK_PANEL_ORIENTATION eOrientation);

	int AddElement(CWnd *pWnd);
	int AddElement(CPanel *pPanel);
	int RemoveElement(int nIndex);
	int RemoveElement(CWnd *pWnd);
	int GetElementCount();
	int RemoveAllElements();

	int EnsureVisible(int nObjID, BOOL bPartialOK);
	int EnsureVisible(CWnd *pWnd, BOOL bPartialOK);
protected:
	STACK_PANEL_ORIENTATION m_eOrientation;
	std::vector<STACK_ELEMENT> m_vElements;
	SCROLLINFO m_si;
};

//////////////////////////////////////////////////////////////////////////
// CGridPanel

class CGridPanel : public CPanel  
{
public:
	CGridPanel();
	virtual ~CGridPanel();
	BOOL Create(LPRECT lpRect, CWnd *pParent, CPanel *pParentGridPanel = NULL, UINT nParentRowColID = MAKELPARAM(0, 0));
	BOOL CreateStatic(LPRECT lpRect, int nRows, int nCols, CWnd *pParent, CPanel *pParentGridPanel = NULL, UINT nParentRowColID = MAKELPARAM(0, 0));

protected:
	static LRESULT ElementWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	virtual int RelayoutElements();
	virtual int InsertPanel(CPanel *pChildPanel, UINT nPos);
	virtual int GetCellRect(int nRow, int nCol, LPRECT lpRect) const;

	int SetGridUnit(GRID_PANEL_UINT eGpu);
	GRID_PANEL_UINT GetGridUnit() const;

	// Row
	int InsertRow(int nIndex, int nHeight);
	int GetRowCount() const;
	int SetRowHeight(int nIndex, int nHeight);
	int GetRowHeight(int nIndex) const;
	int DeleteRow(int nIndex);

	// Column
	int InsertColumn(int nIndex, int nWidth);
	int GetColumnCount() const;
	int SetColumnWidth(int nIndex, int nWidth);
	int GetColumnWidth(int nIndex) const;
	int DeleteColumn(int nIndex);

	int AddElement(CWnd *pWnd, int nRow, int nColumn, GRID_ELEMENT_ALIGN_HOR eHorAlign, GRID_ELEMENT_ALIGN_VER eVerAlign);
	int RemoveElement(int nRow, int nColumn);
	int RemoveElement(CWnd *pWnd);
	int RemoveAllElements();

protected:
	CGrid m_Data;
	GRID_PANEL_UINT m_eGpu;
};

//////////////////////////////////////////////////////////////////////////
// CUniformGridPanel

class CUniformGridPanel : public CGridPanel
{
public:
	CUniformGridPanel();
	virtual ~CUniformGridPanel();

public:
	virtual int RelayoutElements();

	int InsertRow(int nIndex);
	int GetRowHeight();
	int InsertColumn(int nIndex);
	int GetColumnWidth();

private:
	int InsertRow(int nIndex, int nHeight);
	int GetRowHeight(int nIndex);
	int InsertColumn(int nIndex, int nWidth);
	int GetColumnWidth(int nIndex);

};

//////////////////////////////////////////////////////////////////////////
// CIUIDocument

class CIUIDocument : public CDocument
{
	friend CIUIMultiDocTemplate;
	friend CIUIFrameWnd;
	friend CIUIMDIFrameWnd;
	friend CIUIMDIClientWnd;
	friend CIUIView;
	DECLARE_DYNCREATE(CIUIDocument)

	// Don't call the following private interface
private:
	virtual BOOL CanCloseFrame(CFrameWnd* pFrame) { ASSERT(FALSE); return FALSE; }
	virtual void PreCloseFrame(CFrameWnd* pFrame) { ASSERT(FALSE); }

protected:
	CIUIDocument();           // protected constructor used by dynamic creation
	virtual ~CIUIDocument();

public:
	void AddView(CIUIView* pView);


// Overrides
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	virtual BOOL CanCloseIUIFrame(CIUIFrameWnd* pIUIFrame); ///
	virtual void PreCloseIUIFrame(CIUIFrameWnd* pIUIFrame); ///
	virtual void UpdateFrameCounts();
	virtual CIUIView* GetNextIUIView(POSITION& rPosition) const;
	protected:
	virtual BOOL OnNewDocument();
	virtual void OnCloseDocument();

// Implementation
public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CIUIDocument)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////
// CIUIWinApp

class CIUIWinApp : public CWinApp
{
	friend class CIUIMDIFrameWnd;
public:
	CIUIWinApp();

protected:
	void OnFileNew();
	void OnFileOpen();

	void AddDocTemplate(CDocTemplate* pTemplate);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIUIWinApp)
	//}}AFX_VIRTUAL

public:
	//{{AFX_MSG(CIUIWinApp)
	afx_msg void OnUpdateRecentFileMenu(CCmdUI* pCmdUI);
	afx_msg BOOL OnOpenRecentFile(UINT nID);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////
// CIUIView

class CIUIView : public CUIWnd
{
	friend class CIUIDocument;
	DECLARE_DYNCREATE(CIUIView)

public:
	CIUIView();
	virtual ~CIUIView();
	void WindowID() { ASSERT(FALSE); }

public:
	CIUIDocument *GetDocument();

public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIUIView)
	virtual void PostNcDestroy();   // default to delete this.
	virtual void OnActivateView(BOOL bActivate, CIUIView* pActivateView, CIUIView* pDeactiveView); ///
	virtual void OnActivateFrame(UINT nState, CIUIFrameWnd* pFrameWnd); ///
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CIUIView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMDIActivate(BOOL bActivate, CWnd*, CWnd*);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
protected:
	CIUIDocument* m_pDocument;
};

//////////////////////////////////////////////////////////////////////////
// CIUIFrameWnd

class CIUIFrameWnd : public CUIWnd
{
	friend class CIUIDocument;
	DECLARE_DYNCREATE(CIUIFrameWnd)

public:
	static AFX_DATA const CRect rectDefault;
	CIUIFrameWnd();
	virtual ~CIUIFrameWnd();
	void WindowID() { ASSERT(FALSE); }

	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, BOOL bLoadBkImageFromFile=TRUE, BOOL bUseLayeredWindow=TRUE);

protected:
	LPCTSTR GetIconWndClass(DWORD dwDefaultStyle, UINT nIDResource); ///
	int OnCreateHelper(LPCREATESTRUCT lpcs, CCreateContext* pContext);	///

public:
	CIUIMDIFrameWnd* GetMDIFrame();
	void MDIDestroy();
	virtual CIUIDocument* GetActiveDocument();	///
	CString GetTitle() const { return m_strTitle; } ///
	CIUIView* GetActiveView() const;           /// active view or NULL
	void SetActiveView(CIUIView* pViewNew, BOOL bNotify); ///
	void InitialUpdateFrame(CDocument* pDoc, BOOL bMakeVisible);	///
	void BringToTop(int nCmdShow); ///
	CWnd* CreateView(CCreateContext* pContext, UINT nID = AFX_IDW_PANE_FIRST); ///

public:
// Overrides
	virtual void ActivateFrame(int nCmdShow = -1);	///
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle);	///
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);	///
	virtual void RecalcLayout(BOOL bNotify = TRUE); ///
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs); ///
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	// customize if using an 'Window' menu with non-standard IDs
	virtual HMENU GetWindowMenuPopup(HMENU hMenuBar);	///

	// Generated message map functions
protected:
	//{{AFX_MSG(CIUIFrameWnd)
	afx_msg void OnClose();	///
	afx_msg void OnMDIActivate(BOOL bActivate, CWnd*, CWnd*);
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
protected:
	CString m_strTitle;			/// default title (original)
	HMENU m_hMenuDefault;		/// default menu resource for this frame
	HACCEL m_hAccelTable;		/// accelerator table
	int m_nWindow;	///  // general purpose window number - display as ":n"
					// -1 => unknown, 0 => only window viewing document
					// 1 => first of many windows viewing document, 2=> second
	CIUIView* m_pViewActive;       // current active view
	BOOL m_bAutoMenuEnable;
		// TRUE => menu items without handlers will be disabled
};

//////////////////////////////////////////////////////////////////////////
// CIUIMDIChildWnd

class CIUIMDIChildWnd : public CIUIFrameWnd
{
	friend class CIUIMDIFrameWnd;
	DECLARE_DYNCREATE(CIUIMDIChildWnd)

public:
	CIUIMDIChildWnd();
	virtual ~CIUIMDIChildWnd();
	void WindowID() { ASSERT(FALSE); }
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext = NULL);	///
	virtual BOOL Create(LPCTSTR lpszClassName,
				LPCTSTR lpszWindowName,
				DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW,
				const RECT& rect = rectDefault,
				CIUIMDIFrameWnd* pParentWnd = NULL,
				CCreateContext* pContext = NULL);	///

public:
	CIUIMDIFrameWnd* GetMDIFrame();
	void MDIDestroy();
	virtual void ActivateFrame(int nCmdShow = -1); ///
	void AfxSetWindowText2(LPCTSTR lpszNew);

public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIUIMDIChildWnd)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs); ///
	virtual BOOL DestroyWindow();
	virtual void PostNcDestroy();   // default to delete this.
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle);	///
	protected:
	virtual LRESULT DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam);	///
	virtual void OnUpdateFrameMenu(BOOL bActive, CWnd* pActivateWnd, HMENU hMenuAlt); ///
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CIUIMDIChildWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);	///
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMDIActivate(BOOL bActivate, CWnd*, CWnd*); ///
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
protected:
	CIUIDocument* m_pDocument;
	BOOL m_bPseudoInactive;     // TRUE if window is MDI active according to
								//  windows, but not according to MFC...
	BOOL m_bVisible;
	HMENU m_hMenuShared;        /// menu when we are active
};

/////////////////////////////////////////////////////////////////////////////
// CIUIMDIClientWnd window

class CIUIMDIClientWnd : public CUIWnd
{
	friend class CIUIMDIChildWnd;
	friend class CIUIMDIFrameWnd;
public:
	CIUIMDIClientWnd();
	virtual ~CIUIMDIClientWnd();
	void WindowID() {}

public:
	CIUIMDIChildWnd *GetActiveChildFrame();
	int SetCloseButtonInTab(BOOL bCloseBtnInTab);
	BOOL IsCloseButtonInTab();
	int UpdateMDIClientTitleBar();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIUIMDIClientWnd)
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL


	// Generated message map functions
protected:
	//{{AFX_MSG(CIUIMDIClientWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pDeactivateWnd);
	afx_msg LRESULT OnMDICreate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMDIDestroy(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMDIGetActive(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMDISetMenu(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnParentEvent(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CTaskWndMgr m_TaskChildFrameMgr;
	CStackPanel m_stackPanel;
	UINT m_nMDITabID;
	UINT m_nNextChildFrameID;
	UINT m_nSwitchDocumentButtonID;
	UINT m_nCloseDocumentButtonID;
	BOOL m_bCloseBtnInTab;
};

//////////////////////////////////////////////////////////////////////////
// CIUIMDIFrameWnd

class CIUIMDIFrameWnd : public CIUIFrameWnd
{
	friend CIUIDocument;
	friend CIUIMDIClientWnd;
	friend CIUIFrameWnd;
	friend CIUIMDIChildWnd;
public:
	DECLARE_DYNCREATE(CIUIMDIFrameWnd)

	CIUIMDIFrameWnd();
	virtual ~CIUIMDIFrameWnd();

public:
	void MDIActivate(CWnd* pWndActivate);	///
	CIUIMDIChildWnd* MDIGetActive(BOOL* pbMaximized = NULL) const;
	void UpdateFrameTitleForDocument(LPCTSTR lpszDocName);
	void MDINext();	/// 

// Overrides
	// for menu bar
	virtual CMenuBar *GetDefaultMenuBar() { return m_pMenuBarDefault; }
	int SetDefaultMenuBar(CMenuBar *pMenuBar);

	// for create CIUIMDIClientWnd object
	virtual BOOL GetMDIClientWindowID(UINT *puID) { return FALSE; }
	virtual BOOL OnGetMDIClientRect(LPRECT lpRect) { return FALSE; }

	// for create tab in CIUIMDIClientWnd object
	virtual BOOL GetMDITabImages(BITMAPOBJ *phBmpN, BITMAPOBJ *phBmpH, BITMAPOBJ *phBmpS, BITMAPOBJ *phBmpD, BITMAPOBJ *phBmpCN, BITMAPOBJ *phBmpCH, BITMAPOBJ *phBmpCS, BITMAPOBJ *phBmpCD) { ASSERT(FALSE); return FALSE; }
	virtual BOOL GetMDITabsRect(LPRECT lpRect) { ASSERT(FALSE); return FALSE; }
	virtual BOOL GetSwitchDocumentButtonID(UINT *puID)  { ASSERT(FALSE); return FALSE; }
	virtual BOOL GetCloseDocumentButtonID(UINT *puID) { ASSERT(FALSE); return FALSE; }

	// for position of CIUIView
	virtual BOOL GetMDIViewRect(LPRECT lpRect) { return FALSE; }

	virtual void OnUpdateFrameTitle(BOOL bAddToTitle); ///

// Generated message map functions
protected:
	//{{AFX_MSG(CIUIMDIFrameWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFileClose();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnAppExit();
	afx_msg LRESULT OnGetDocumentViewClientRect(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMDIRefreshMenu(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetMenuBar(WPARAM wParam, LPARAM lParam);
#if(_MSC_VER <= 1200) // VC6.0
	afx_msg void OnFileMruFile(UINT uID);
#else
	afx_msg BOOL OnFileMruFile(UINT uID);
#endif
	afx_msg void OnUpdateFileMruFile1(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CIUIMDIClientWnd m_wndMDIClient;
	CString m_strTitle;				// default title (original)
	CMenuBar *m_pMenuBarDefault;	// default menu bar
};

//////////////////////////////////////////////////////////////////////////
// CIUIDocManager

class CIUIDocManager : public CDocManager  
{
	DECLARE_DYNAMIC(CIUIDocManager)

public:
	CIUIDocManager();
	virtual ~CIUIDocManager();

public:
	virtual void RegisterShellFileTypes(BOOL bCompat);
};

//////////////////////////////////////////////////////////////////////////
// CIUIMultiDocTemplate

class CIUIMultiDocTemplate : public CMultiDocTemplate  
{
	friend CIUIMDIFrameWnd;
	friend CIUIMDIClientWnd;

public:
	CIUIMultiDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);
	virtual ~CIUIMultiDocTemplate();

	// the following private interface shouldn't be called.
private:
	virtual void InitialUpdateFrame(CFrameWnd* pFrame, CDocument* pDoc, BOOL bMakeVisible = TRUE) { ASSERT(FALSE); }
	virtual CFrameWnd* CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther)  { ASSERT(FALSE); return NULL; }

public:
	// override CDocTemplate::InitialUpdateFrame
	virtual void InitialUpdateFrame(CIUIMDIChildWnd* pFame, CIUIDocument* pDoc, BOOL bMakeVisible = TRUE);
	virtual CIUIMDIChildWnd* CreateNewIUIFrame(CIUIDocument* pDoc);

	virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE);

private:
	UINT m_uViewID;
};

}// name space LibUIDK


#endif //_CONTROLS_H_
