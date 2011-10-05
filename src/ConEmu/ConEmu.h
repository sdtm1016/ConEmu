
/*
Copyright (c) 2009-2011 Maximus5
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#pragma once

//#define HDCWND 'ghWnd DC'

#ifndef __ITaskbarList3_FWD_DEFINED__
#define __ITaskbarList3_FWD_DEFINED__
typedef interface ITaskbarList3 ITaskbarList3;
#endif 	/* __ITaskbarList3_FWD_DEFINED__ */

#ifndef __ITaskbarList2_FWD_DEFINED__
#define __ITaskbarList2_FWD_DEFINED__
typedef interface ITaskbarList2 ITaskbarList2;
#endif 	/* __ITaskbarList2_FWD_DEFINED__ */

#define WM_TRAYNOTIFY WM_USER+1
#define ID_TOMONITOR 0xABBD
#define ID_NEWCONSOLE 0xABBE
#define ID_DUMPPROCESS 0xABBF
#define ID_DEBUG_SHOWRECTS 0xABC0
//#define ID_MONITOR_SHELLACTIVITY 0xABC1
#define ID_CON_COPY 0xABC2
#define ID_CON_MARKTEXT 0xABC3
#define ID_CON_MARKBLOCK 0xABC4
#define ID_ALWAYSONTOP 0xABC5
#define ID_DEBUGGUI 0xABC6
#define ID_HELP 0xABC7
#define ID_CON_TOGGLE_VISIBLE 0xABC8
#define ID_CON_PASTE 0xABC9
#define ID_AUTOSCROLL 0xABCA
#define ID_DUMPCONSOLE 0xABCB
#define ID_CONPROP 0xABCC
#define ID_SETTINGS 0xABCD
#define ID_ABOUT 0xABCE
#define ID_TOTRAY 0xABCF
#define ID_DEBUGCON 0xABD0 // ���� ����������, ��� 0xABBC Win7 ���� �����...
// VCon menu items
#define IDM_VCONCMD_FIRST 0xABD1
#define IDM_CLOSE IDM_VCONCMD_FIRST
#define IDM_RESTART 0xABD2
#define IDM_RESTARTAS 0xABD3
#define IDM_TERMINATE 0xABD4
#define IDM_NEW 0xABD5
#define IDM_ADMIN_DUPLICATE 0xABD6
#define IDM_SAVE 0xABD7
#define IDM_SAVEALL 0xABD8
#define IDM_DETACH 0xABD9
#define IDM_VCONCMD_LAST IDM_DETACH
// Consoles // DWORD MAKELONG(WORD wLow,WORD wHigh);
#define IDM_VCON_FIRST MAKELONG(1,1)
#define IDM_VCON_LAST  MAKELONG(0,MAX_CONSOLE_COUNT+1)


#define IID_IShellLink IID_IShellLinkW

#define GET_X_LPARAM(inPx) ((int)(short)LOWORD(inPx))
#define GET_Y_LPARAM(inPy) ((int)(short)HIWORD(inPy))

//#define RCLICKAPPSTIMEOUT 600
//#define RCLICKAPPS_START 100 // ������ ��������� ������ ������ �������
//#define RCLICKAPPSTIMEOUT_MAX 10000
//#define RCLICKAPPSDELTA 3
#define DRAG_DELTA 5

//typedef DWORD (WINAPI* FGetModuleFileNameEx)(HANDLE hProcess,HMODULE hModule,LPWSTR lpFilename,DWORD nSize);

typedef HRESULT(WINAPI* FDwmIsCompositionEnabled)(BOOL *pfEnabled);

class CConEmuChild;
class CConEmuBack;
class TabBarClass;
class CConEmuMacro;

WARNING("���������, ����� DC ��������� �������������� ����� �������� CEM_BACK");
enum ConEmuMargins
{
	// ������� ����� �������� ����� ���� � ���������� ������� ���� (����� + ���������)
	CEM_FRAME = 0x0001,
	// ������ ���� (���� ������ .top)
	CEM_TAB = 0x0002,
	CEM_TABACTIVATE = 0x1002,   // ������������� �������, ��� ��� ���� (��� ��������� ����)
	CEM_TABDEACTIVATE = 0x2002, // ������������� �������, ��� ���� ��� (��� ���������� ����)
	CEM_TAB_MASK = (CEM_TAB|CEM_TABACTIVATE|CEM_TABDEACTIVATE),
	// ���� ������ ��������� ������ ����� - �� �� ������
	CEM_SCROLL = 0x0004,
};

enum ConEmuRect
{
	CER_MAIN = 0,   // ������ ������ ����
	// ����� ��� ���������� ��������� ������������ ���������� ������� {0,0}
	CER_MAINCLIENT, // ���������� ������� �������� ���� (��� ��������� �����, ���������, DoubleView � �������. �������)
	CER_TAB,        // ��������� �������� � ���������� (�����)
	CER_BACK,       // ��������� ���� � �����
	CER_WORKSPACE,  // ���� - �� �� ��� � CER_BACK, �� ��� DoubleView CER_BACK ����� ���� ������
	CER_SCROLL,     // ��������� ������ ���������
	CER_DC,         // ��������� ���� ���������
	CER_CONSOLE,    // !!! _ ������ � �������� _ !!!
	CER_CONSOLE_NTVDMOFF, // same as CER_CONSOLE, �� �� ����� ���������� ������ 16���
	CER_FULLSCREEN, // ������ ������ � pix �������� �������� (����������� ghWnd)
	CER_MAXIMIZED,  // ������ ������������������ ���� �� ������� �������� (����������� ghWnd)
	CER_RESTORE,    // ������ "����������������" ���� ����� ������������ (��������� �� ������� ��������?)
//	CER_CORRECTED   // ����������������� ��������� (����� ���� ���� ����� �� ������� ��������)
};

enum DragPanelBorder
{
	DPB_NONE = 0,
	DPB_SPLIT,    // ���� �����/������
	DPB_LEFT,     // ������ �����
	DPB_RIGHT,    // ������ ������
};

class CConEmuMain
{
	public:
		//HMODULE mh_Psapi;
		//FGetModuleFileNameEx GetModuleFileNameEx;
		wchar_t ms_ConEmuVer[32];               // �������� � �������, �������� "ConEmu 110117"
		wchar_t ms_ConEmuExe[MAX_PATH+1];       // ������ ���� � ConEmu.exe (GUI)
		wchar_t ms_ConEmuExeDir[MAX_PATH+1];    // ��� ������������ �����. ����� �������� ConEmu.exe
		wchar_t ms_ConEmuBaseDir[MAX_PATH+1];   // ��� ������������ �����. ����� �������� ConEmuC.exe, ConEmuHk.dll, ConEmu.xml
		BOOL mb_DosBoxExists;
		// Portable Far Registry
		BOOL mb_PortableRegExist;
		wchar_t ms_PortableRegHive[MAX_PATH]; // ������ ���� � "Portable.S-x-x-..."
		wchar_t ms_PortableRegHiveOrg[MAX_PATH]; // ���� � "Portable.S-x-x-..." (� ConEmu). ���� ���� ��� ���� ���������� � ms_PortableRegHive
		wchar_t ms_PortableReg[MAX_PATH]; // "Portable.reg"
		HKEY mh_PortableMountRoot; // ��� HKEY_CURRENT_USER ��� HKEY_USERS
		wchar_t ms_PortableMountKey[MAX_PATH];
		BOOL mb_PortableKeyMounted;
		wchar_t ms_PortableTempDir[MAX_PATH];
		HKEY mh_PortableRoot; // ��� �������� ����
		bool PreparePortableReg();
	private:
		BOOL CheckDosBoxExists();
		void CheckPortableReg();
		void FinalizePortableReg();
		wchar_t ms_ConEmuXml[MAX_PATH+1];       // ������ ���� � ������������ ����������
	public:
		LPWSTR ConEmuXml();
		wchar_t ms_ConEmuChm[MAX_PATH+1];       // ������ ���� � chm-����� (help)
		//wchar_t ms_ConEmuCExe[MAX_PATH+12];     // ������ ���� � ������� (ConEmuC.exe) � ��������� ������� (��� ComSpec)
		wchar_t ms_ConEmuCExeFull[MAX_PATH+12]; // ������ ���� � ������� (ConEmuC.exe) � �������� �������
		//wchar_t ms_ConEmuCExeName[32];        // ��� ������� (ConEmuC.exe ��� ConEmuC64.exe) -- �� ��������
		wchar_t ms_ConEmuCurDir[MAX_PATH+1];    // ��� ������������ �����. ����� ������� ConEmu.exe (GetCurrentDirectory)
		wchar_t *mpsz_ConEmuArgs;    // ���������
	private:
		ConEmuGuiMapping m_GuiInfo;
		MFileMapping<ConEmuGuiMapping> m_GuiInfoMapping;
		void FillConEmuMainFont(ConEmuMainFont* pFont);
		void UpdateGuiInfoMapping();
	public:
		//CConEmuChild *m_Child;
		CConEmuBack  *m_Back;
		CConEmuMacro *m_Macro;
		TabBarClass *mp_TabBar;
		//POINT cwShift; // difference between window size and client area size for main ConEmu window
		POINT ptFullScreenSize; // size for GetMinMaxInfo in Fullscreen mode
		//DWORD gnLastProcessCount;
		//uint cBlinkNext;
		DWORD WindowMode, change2WindowMode;
		BOOL mb_ExternalHidden;
		//HANDLE hPipe;
		//HANDLE hPipeEvent;
		bool isWndNotFSMaximized;
		BOOL mb_StartDetached;
		//bool isShowConsole;
		//bool mb_FullWindowDrag;
		//bool isLBDown, /*isInDrag,*/ isDragProcessed,
		//mb_InSizing, -> state&MOUSE_SIZING
		//mb_IgnoreMouseMove;
		//bool isRBDown, ibSkipRDblClk; DWORD dwRBDownTick;
		struct
		{
			WORD  state;
			bool  bSkipRDblClk;
			bool  bIgnoreMouseMove;

			COORD LClkDC, LClkCon;
			DWORD LClkTick;
			COORD RClkDC, RClkCon;
			DWORD RClkTick;

			// ����� �� ����� � ������� ����������� WM_MOUSEMOVE
			WPARAM lastMMW;
			LPARAM lastMML;

			// ���������� ���� ������ (���� ���� ���������)
			UINT nSkipEvents[2]; UINT nReplaceDblClk;
			// �� ���������� ��������� ���� � �������!
			BOOL bForceSkipActivation;
		} mouse;
		bool isPiewUpdate;
		bool gbPostUpdateWindowSize;
		HWND hPictureView; bool bPicViewSlideShow; DWORD dwLastSlideShowTick; RECT mrc_WndPosOnPicView;
		HWND mh_ShellWindow; // ���� Progman ��� Desktop ������
		DWORD mn_ShellWindowPID;
		BOOL mb_FocusOnDesktop;
		//bool gb_ConsoleSelectMode;
		//bool setParent, setParent2;
		//BOOL mb_InClose;
		//int RBDownNewX, RBDownNewY;
		POINT cursor, Rcursor;
		//WPARAM lastMMW;
		//LPARAM lastMML;
		COORD m_LastConSize; // console size after last resize (in columns and lines)
		bool mb_IgnoreSizeChange;
		//bool mb_IgnoreStoreNormalRect;
		TCHAR szConEmuVersion[32];
		DWORD m_ProcCount;
		//DWORD mn_ActiveStatus;
		//TCHAR ms_EditorRus[16], ms_ViewerRus[16], ms_TempPanel[32], ms_TempPanelRus[32];
		OSVERSIONINFO m_osv;
		BOOL mb_IsUacAdmin;
		HCURSOR mh_CursorWait, mh_CursorArrow, mh_CursorAppStarting, mh_CursorMove;
		HCURSOR mh_SplitV, mh_SplitH;
		HCURSOR mh_DragCursor;
		CDragDrop *mp_DragDrop;
	protected:
		//CProgressBars *ProgressBars;
		HMENU mh_DebugPopup, mh_EditPopup, mh_ActiveVConPopup, mh_VConListPopup; // Popup's ��� SystemMenu
		TCHAR Title[MAX_TITLE_SIZE], TitleCmp[MAX_TITLE_SIZE]; //, MultiTitle[MAX_TITLE_SIZE+30];
		short mn_Progress;
		LPTSTR GetTitleStart();
		BOOL mb_InTimer;
		BOOL mb_ProcessCreated, mb_WorkspaceErasedOnClose; //DWORD mn_StartTick;
		HWINEVENTHOOK mh_WinHook; //, mh_PopupHook;
		static VOID CALLBACK WinEventProc(HWINEVENTHOOK hWinEventHook, DWORD anEvent, HWND hwnd, LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime);
		CVirtualConsole *mp_VCon[MAX_CONSOLE_COUNT];
		CVirtualConsole *mp_VActive, *mp_VCon1, *mp_VCon2;
		bool mb_SkipSyncSize, mb_PassSysCommand, mb_CreatingActive;
		BOOL mb_WaitCursor, mb_InTrackSysMenu;
		BOOL mb_LastRgnWasNull;
		BOOL mb_CaptionWasRestored; // ��������� ������������ �� ����� �������
		BOOL mb_ForceShowFrame;     // ������������ ��������� �� ��������
		//wchar_t *mpsz_RecreateCmd;
		ITaskbarList3 *mp_TaskBar3;
		ITaskbarList2 *mp_TaskBar2;
		typedef BOOL (WINAPI* FRegisterShellHookWindow)(HWND);
		RECT mrc_Ideal;
		BOOL mn_InResize;
		RECT mrc_StoredNormalRect;
		void StoreNormalRect(RECT* prcWnd);
		BOOL mb_MaximizedHideCaption; // � ������ HideCaption
		BOOL mb_InRestore; // �� ����� �������������� �� Maximized
		BOOL mb_MouseCaptured;
		//BYTE m_KeybStates[256];
		DWORD_PTR m_ActiveKeybLayout;
		struct
		{
			BOOL      bUsed;
			//wchar_t   klName[KL_NAMELENGTH/*==9*/];
			DWORD     klName;
			DWORD_PTR hkl;
		} m_LayoutNames[20];
		struct
		{
			wchar_t szTranslatedChars[16];
		} m_TranslatedChars[256];
		BYTE mn_LastPressedVK;
		bool mb_InImeComposition, mb_ImeMethodChanged;
		wchar_t ms_ConEmuAliveEvent[MAX_PATH+64];
		HANDLE mh_ConEmuAliveEvent; BOOL mb_ConEmuAliveOwned, mb_AliveInitialized;
		//
		BOOL mb_HotKeyRegistered;
		HHOOK mh_LLKeyHook;
		HMODULE mh_LLKeyHookDll;
		HMODULE LoadConEmuCD();
		void RegisterHotKeys();
		void UnRegisterHotKeys(BOOL abFinal=FALSE);
		int mn_MinRestoreRegistered; UINT mn_MinRestore_VK, mn_MinRestore_MOD;
		HMODULE mh_DwmApi;
		FDwmIsCompositionEnabled DwmIsCompositionEnabled;
		HBITMAP mh_RightClickingBmp; HDC mh_RightClickingDC;
		POINT m_RightClickingSize; // {384 x 16} 24 ������, �������, ��� �������� ����������� ������� ������ �� ������ ������
		int m_RightClickingFrames, m_RightClickingCurrent;
		BOOL mb_RightClickingPaint, mb_RightClickingLSent;
		void StartRightClickingPaint();
		void StopRightClickingPaint();
	public:
		void RightClickingPaint(HDC hdc, CVirtualConsole* apVCon);
		void RegisterMinRestore(bool abRegister);
		void RegisterHoooks();
		void UnRegisterHoooks(BOOL abFinal=FALSE);
		void UpdateWinHookSettings();
	protected:
		void CtrlWinAltSpace();
		//BOOL LowLevelKeyHook(UINT nMsg, UINT nVkKeyCode);
		//DWORD_PTR mn_CurrentKeybLayout;
		// Registered messages
		DWORD mn_MainThreadId;
		UINT mn_MsgPostCreate;
		UINT mn_MsgPostCopy;
		UINT mn_MsgMyDestroy;
		UINT mn_MsgUpdateSizes;
		UINT mn_MsgUpdateCursorInfo;
		UINT mn_MsgSetWindowMode;
		UINT mn_MsgUpdateTitle;
		//UINT mn_MsgAttach;
		UINT mn_MsgSrvStarted;
		UINT mn_MsgVConTerminated;
		UINT mn_MsgUpdateScrollInfo;
		UINT mn_MsgUpdateTabs; // = RegisterWindowMessage(CONEMUMSG_UPDATETABS);
		UINT mn_MsgOldCmdVer; BOOL mb_InShowOldCmdVersion;
		UINT mn_MsgTabCommand;
		UINT mn_MsgTabSwitchFromHook; BOOL mb_InWinTabSwitch; // = RegisterWindowMessage(CONEMUMSG_ACTIVATECON);
		UINT mn_MsgWinKeyFromHook;
		UINT mn_MsgSheelHook;
		UINT mn_ShellExecuteEx;
		UINT mn_PostConsoleResize;
		UINT mn_ConsoleLangChanged;
		UINT mn_MsgPostOnBufferHeight;
		UINT mn_MsgPostAltF9;
		//UINT mn_MsgPostSetBackground;
		UINT mn_MsgInitInactiveDC;
		//UINT mn_MsgSetForeground;
		UINT mn_MsgFlashWindow; // = RegisterWindowMessage(CONEMUMSG_FLASHWINDOW);
		UINT mn_MsgActivateCon; // = RegisterWindowMessage(CONEMUMSG_ACTIVATECON);
		UINT mn_MsgUpdateProcDisplay;
		//UINT wmInputLangChange;
		UINT mn_MsgAutoSizeFont;
		UINT mn_MsgDisplayRConError;
		UINT mn_MsgMacroFontSetName;
		UINT mn_MsgCreateViewWindow;

		//
		static DWORD CALLBACK GuiServerThread(LPVOID lpvParam);
		void GuiServerThreadCommand(HANDLE hPipe);
		DWORD mn_GuiServerThreadId; HANDLE mh_GuiServerThread, mh_GuiServerThreadTerminate;

	public:
		DWORD CheckProcesses();
		DWORD GetFarPID(BOOL abPluginRequired=FALSE);

	public:
		LPCTSTR GetLastTitle(bool abUseDefault=true);
		LPCTSTR GetVConTitle(int nIdx);
		int GetActiveVCon();
		CVirtualConsole* GetVCon(int nIdx);
		int IsVConValid(CVirtualConsole* apVCon);
		CVirtualConsole* GetVConFromPoint(POINT ptScreen);
		void UpdateCursorInfo(COORD crCursor, CONSOLE_CURSOR_INFO cInfo);
		void UpdateProcessDisplay(BOOL abForce);
		void UpdateSizes();

	public:
		CConEmuMain();
		~CConEmuMain();

	public:
		CVirtualConsole* ActiveCon();
		BOOL Activate(CVirtualConsole* apVCon);
		int ActiveConNum(); // 0-based
		static void AddMargins(RECT& rc, RECT& rcAddShift, BOOL abExpand=FALSE);
		void AskChangeBufferHeight();
		BOOL AttachRequested(HWND ahConWnd, CESERVER_REQ_STARTSTOP pStartStop, CESERVER_REQ_STARTSTOPRET* pRet);
		CRealConsole* AttachRequestedGui(LPCWSTR asAppFileName, DWORD anAppPID);
		void AutoSizeFont(const RECT &rFrom, enum ConEmuRect tFrom);
		static RECT CalcMargins(DWORD/*enum ConEmuMargins*/ mg, CVirtualConsole* apVCon=NULL);
		static RECT CalcRect(enum ConEmuRect tWhat, const RECT &rFrom, enum ConEmuRect tFrom, CVirtualConsole* pVCon=NULL, RECT* prDC=NULL, enum ConEmuMargins tTabAction=CEM_TAB);
		void CheckFocus(LPCWSTR asFrom);
		enum DragPanelBorder CheckPanelDrag(COORD crCon);
		bool ConActivate(int nCon);
		bool ConActivateNext(BOOL abNext);
		bool CorrectWindowPos(WINDOWPOS *wp);
		//void CheckGuiBarsCreated();
		CVirtualConsole* CreateCon(RConStartArgs *args);
		BOOL CreateMainWindow();
		HRGN CreateWindowRgn(bool abTestOnly=false);
		HRGN CreateWindowRgn(bool abTestOnly,bool abRoundTitle,int anX, int anY, int anWndWidth, int anWndHeight);
		void Destroy();
		void DebugStep(LPCWSTR asMsg, BOOL abErrorSeverity=FALSE);
		void ForceShowTabs(BOOL abShow);
		DWORD_PTR GetActiveKeyboardLayout();
		RECT GetDefaultRect();
		RECT GetIdealRect() { return mrc_Ideal; };
		HMENU GetSystemMenu(BOOL abInitial = FALSE);
		RECT GetVirtualScreenRect(BOOL abFullScreen);
		static DWORD_PTR GetWindowStyle();
		static DWORD_PTR GetWindowStyleEx();
		LRESULT GuiShellExecuteEx(SHELLEXECUTEINFO* lpShellExecute, BOOL abAllowAsync);
		BOOL Init();
		void InitInactiveDC(CVirtualConsole* apVCon);
		void Invalidate(CVirtualConsole* apVCon);
		void InvalidateAll();
		void UpdateWindowChild(CVirtualConsole* apVCon);
		bool isActive(CVirtualConsole* apVCon);
		bool isConSelectMode();
		bool isDragging();
		bool isEditor();
		bool isFar();
		bool isFilePanel(bool abPluginAllowed=false);
		bool isFirstInstance();
		bool IsGlass();
		bool isIconic();
		bool isInImeComposition();
		bool isLBDown();
		bool isMainThread();
		bool isMeForeground(bool abRealAlso=false);
		bool isMouseOverFrame(bool abReal=false);
		bool isNtvdm(BOOL abCheckAllConsoles=FALSE);
		bool isPictureView();
		bool isProcessCreated();
		bool isRightClickingPaint();
		bool isSizing();
		bool isValid(CRealConsole* apRCon);
		bool isValid(CVirtualConsole* apVCon);
		bool isViewer();
		bool isVisible(CVirtualConsole* apVCon);
		bool isWindowNormal();
		bool isZoomed();
		void LoadIcons();
		bool LoadVersionInfo(wchar_t* pFullPath);
		static RECT MapRect(RECT rFrom, BOOL bFrame2Client);
		//void PaintCon(HDC hPaintDC);
		void PaintGaps(HDC hDC);
		void PostCopy(wchar_t* apszMacro, BOOL abRecieved=FALSE);
		void PostMacro(LPCWSTR asMacro);
		void PostCreate(BOOL abRecieved=FALSE);
		HWND PostCreateView(CConEmuChild* pChild);
		void PostAutoSizeFont(int nRelative/*0/1*/, int nValue/*��� nRelative==0 - ������, ��� ==1 - +-1, +-2,...*/);
		void PostMacroFontSetName(wchar_t* pszFontName, WORD anHeight /*= 0*/, WORD anWidth /*= 0*/, BOOL abPosted);
		void PostDisplayRConError(CRealConsole* mp_VCon, wchar_t* pszErrMsg);
		//void PostSetBackground(CVirtualConsole* apVCon, CESERVER_REQ_SETBACKGROUND* apImgData);
		bool PtDiffTest(POINT C, int aX, int aY, UINT D); //(((abs(C.x-LOWORD(lParam)))<D) && ((abs(C.y-HIWORD(lParam)))<D))
		void Recreate(BOOL abRecreate, BOOL abConfirm, BOOL abRunAs = FALSE);
		HHOOK mh_RecreateDlgKeyHook;
		BOOL mb_SkipAppsInRecreate;
		int RecreateDlg(LPARAM lParam);
		static LRESULT CALLBACK RecreateDlgKeyHook(int code, WPARAM wParam, LPARAM lParam);
		static INT_PTR CALLBACK RecreateDlgProc(HWND hDlg, UINT messg, WPARAM wParam, LPARAM lParam);
		static int CALLBACK BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);
		void RePaint();
		void ReSize(BOOL abCorrect2Ideal = FALSE);
		BOOL RunSingleInstance();
		bool ScreenToVCon(LPPOINT pt, CVirtualConsole** ppVCon);
		void SetConsoleWindowSize(const COORD& size, bool updateInfo, CVirtualConsole* apVCon);
		void SetDragCursor(HCURSOR hCur);
		void SetWaitCursor(BOOL abWait);
		bool SetWindowMode(uint inMode, BOOL abForce = FALSE);
		void ShowOldCmdVersion(DWORD nCmd, DWORD nVersion, int bFromServer, DWORD nFromProcess, u64 hFromModule, DWORD nBits);
		void ShowSysmenu(int x=-32000, int y=-32000);
		HMENU CreateDebugMenuPopup();
		HMENU CreateEditMenuPopup(CVirtualConsole* apVCon, HMENU ahExist = NULL);
		HMENU CreateVConListPopupMenu(HMENU ahExist, BOOL abFirstTabOnly);
		HMENU CreateVConPopupMenu(CVirtualConsole* apVCon, HMENU ahExist, BOOL abAddNew);
		void StartDebugLogConsole();
		void StartDebugActiveProcess();
		//void StartLogCreateProcess();
		//void StopLogCreateProcess();
		//void UpdateLogCreateProcess();
		//wchar_t ms_LogCreateProcess[MAX_PATH]; bool mb_CreateProcessLogged;
		void SyncConsoleToWindow();
		void SyncNtvdm();
		void SyncWindowToConsole();
		void SwitchKeyboardLayout(DWORD_PTR dwNewKeybLayout);
		void TabCommand(UINT nTabCmd);
		void Update(bool isForce = false);
		void UpdateFarSettings();
		void UpdateIdealRect(BOOL abAllowUseConSize=FALSE);
		void UpdateTitle(/*LPCTSTR asNewTitle*/);
		void UpdateProgress(/*BOOL abUpdateTitle*/);
		void UpdateWindowRgn(int anX=-1, int anY=-1, int anWndWidth=-1, int anWndHeight=-1);
		static LRESULT CALLBACK MainWndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam);
		LRESULT WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam);
	public:
		void OnAltEnter();
		void OnAltF9(BOOL abPosted=FALSE);
		void OnMinimizeRestore();
		void OnAlwaysOnTop();
		void OnBufferHeight(); //BOOL abBufferHeight);
		LRESULT OnClose(HWND hWnd);
		BOOL OnCloseQuery();
		//BOOL mb_InConsoleResize;
		void OnConsoleResize(BOOL abPosted=FALSE);
		void OnCopyingState();
		LRESULT OnCreate(HWND hWnd, LPCREATESTRUCT lpCreate);
		void OnDesktopMode();
		LRESULT OnDestroy(HWND hWnd);
		LRESULT OnFlashWindow(DWORD nFlags, DWORD nCount, HWND hCon);
		LRESULT OnFocus(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam);
		LRESULT OnGetMinMaxInfo(LPMINMAXINFO pInfo);
		void OnHideCaption();
		LRESULT OnInitMenuPopup(HWND hWnd, HMENU hMenu, LPARAM lParam);
		LRESULT OnKeyboard(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam);
		LRESULT OnKeyboardHook(WORD vk, BOOL abReverse);
		LRESULT OnKeyboardIme(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam);
		LRESULT OnLangChange(UINT messg, WPARAM wParam, LPARAM lParam);
		LRESULT OnLangChangeConsole(CVirtualConsole *apVCon, DWORD dwLayoutName);
		LRESULT OnMouse(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam);
		LRESULT OnMouse_Move(CVirtualConsole* pVCon, HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam, POINT ptCur, COORD cr);
		LRESULT OnMouse_LBtnDown(CVirtualConsole* pVCon, HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam, POINT ptCur, COORD cr);
		LRESULT OnMouse_LBtnUp(CVirtualConsole* pVCon, HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam, POINT ptCur, COORD cr);
		LRESULT OnMouse_LBtnDblClk(CVirtualConsole* pVCon, HWND hWnd, UINT& messg, WPARAM wParam, LPARAM lParam, POINT ptCur, COORD cr);
		LRESULT OnMouse_RBtnDown(CVirtualConsole* pVCon, HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam, POINT ptCur, COORD cr);
		LRESULT OnMouse_RBtnUp(CVirtualConsole* pVCon, HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam, POINT ptCur, COORD cr);
		LRESULT OnMouse_RBtnDblClk(CVirtualConsole* pVCon, HWND hWnd, UINT& messg, WPARAM wParam, LPARAM lParam, POINT ptCur, COORD cr);
		BOOL OnMouse_NCBtnDblClk(HWND hWnd, UINT& messg, WPARAM wParam, LPARAM lParam);
		LRESULT OnNcMessage(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam);
		LRESULT OnNcPaint(HRGN hRgn);
		LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
		LRESULT OnSetCursor(WPARAM wParam=-1, LPARAM lParam=-1);
		LRESULT OnSize(WPARAM wParam=0, WORD newClientWidth=(WORD)-1, WORD newClientHeight=(WORD)-1);
		LRESULT OnSizing(WPARAM wParam, LPARAM lParam);
		void OnSizePanels(COORD cr);
		LRESULT OnShellHook(WPARAM wParam, LPARAM lParam);
		LRESULT OnSysCommand(HWND hWnd, WPARAM wParam, LPARAM lParam);
		LRESULT OnTimer(WPARAM wParam, LPARAM lParam);
		void OnTransparent();
		void OnVConCreated(CVirtualConsole* apVCon);
		LRESULT OnVConTerminated(CVirtualConsole* apVCon, BOOL abPosted = FALSE);
		void OnAllVConClosed();
		void OnRConStartedSuccess(CRealConsole* apRCon);
		LRESULT OnUpdateScrollInfo(BOOL abPosted = FALSE);
		void OnPanelViewSettingsChanged(BOOL abSendChanges=TRUE);
		void OnGlobalSettingsChanged();
};

extern CConEmuMain *gpConEmu;
