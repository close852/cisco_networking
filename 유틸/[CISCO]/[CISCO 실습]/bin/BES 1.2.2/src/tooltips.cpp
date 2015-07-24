#include "BattleEnc.h"

#define BES_TRAY_MENU( x ) (\
	IDM_STOP_FROM_TRAY - IDM_MENU_BASE ==  ( x ) ||\
	IDM_SHOWWINDOW     - IDM_MENU_BASE ==  ( x ) ||\
	IDM_EXIT_FROM_TRAY - IDM_MENU_BASE ==  ( x ) ||\
	IDM_CROW           - IDM_MENU_BASE ==  ( x ) )


HWND CreateTooltip( const HINSTANCE hInst, const HWND hwndBase, LPCTSTR str )
{
	INITCOMMONCONTROLSEX iccex; 
	iccex.dwICC = ICC_WIN95_CLASSES;
	iccex.dwSize = sizeof( INITCOMMONCONTROLSEX );
	InitCommonControlsEx( &iccex );

	HWND hwndToolTip = CreateWindowEx(
		WS_EX_TOPMOST,
		TOOLTIPS_CLASS,
		NULL,
		WS_POPUP | TTS_NOPREFIX | TTS_ALWAYSTIP,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		hwndBase,
		NULL,
		hInst,
		NULL
	);

	SetWindowPos(
		hwndToolTip,
		HWND_TOPMOST,
		0,
		0,
		0,
		0,
		SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE
	);

	TCHAR lpszText[ 256 ];
	lstrcpy( lpszText, str );
	RECT rectClient;
	GetClientRect ( hwndBase, &rectClient );
	TOOLINFO ti;
	ZeroMemory( &ti, sizeof( TOOLINFO ) );
	ti.cbSize = sizeof( TOOLINFO );
	ti.uFlags = TTF_SUBCLASS;
	ti.hwnd = hwndBase;
	ti.hinst = hInst;
	ti.uId = 0U;
	ti.lpszText = lpszText;
	ti.rect = rectClient;

	SendMessage( hwndToolTip, TTM_ADDTOOL, 0U, (LPARAM) &ti );

	return hwndToolTip;
}

VOID UpdateTooltip( const HINSTANCE hInst, const HWND hwndBase, LPCTSTR str, const HWND hwndToolTip )
{
	TCHAR lpszText[ 256 ];
	lstrcpy( lpszText, str );
	TOOLINFO ti;
	ZeroMemory( &ti, sizeof( TOOLINFO ) );
	ti.cbSize = sizeof( TOOLINFO );
	ti.hwnd = hwndBase;
	ti.hinst = hInst;
	ti.uId = 0U;
	ti.lpszText = lpszText;
	SendMessage( hwndToolTip, TTM_UPDATETIPTEXT, 0U, (LPARAM) &ti );
}

#ifdef _UNICODE
VOID InitToolTipsFin( WCHAR str[ 4 ][ 256 ] )
{
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_FIN0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_FIN1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_FIN2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_FIN3, -1, str[ 3 ], 255 );
}

VOID InitToolTipsSpa( WCHAR str[ 4 ][ 256 ] )
{
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_SPA0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_SPA1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_SPA2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_SPA3, -1, str[ 3 ], 255 );
}

VOID InitToolTipsChiT( WCHAR str[ 4 ][ 256 ] )
{
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_CHI0T, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_CHI1T, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_CHI2T, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_CHI3T, -1, str[ 3 ], 255 );
}

VOID InitToolTipsChiS( WCHAR str[ 4 ][ 256 ] )
{
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_CHI0S, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_CHI1S, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_CHI2S, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_CHI3S, -1, str[ 3 ], 255 );
}

VOID InitToolTipsJpn( WCHAR str[ 4 ][ 256 ] )
{
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_JPN0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_JPN1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_JPN2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_JPN3, -1, str[ 3 ], 255 );
}

VOID InitToolTipsFre( TCHAR str[ 4 ][ 256 ] )
{
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_FRE0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_FRE1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_FRE2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_TOOLTIP_FRE3, -1, str[ 3 ], 255 );
}


VOID InitMenuFin( const HWND hWnd )
{
	HMENU hMenu = GetMenu( hWnd );

	UINT flagRealtime = ( ( GetMenuState( hMenu, IDM_REALTIME, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;
	UINT flagLogging = ( ( GetMenuState( hMenu, IDM_LOGGING, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;

	TCHAR str[ 50 ][ 256 ];
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_FIN0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_FIN1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_FIN2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_FIN3, -1, str[ 3 ], 255 );

	for( UINT u = 0U; u < 4U; u++ )
	{
		ModifyMenu( hMenu, u, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hMenu, (int) u ), str[ u ] );
	}

	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_3, -1, str[ 3 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_4, -1, str[ 4 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_5, -1, str[ 5 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_6, -1, str[ 6 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_7, -1, str[ 7 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_8, -1, str[ 8 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_9, -1, str[ 9 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_10, -1, str[ 10 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_11, -1, str[ 11 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_12, -1, str[ 12 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_13, -1, str[ 13 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_14, -1, str[ 14 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_15, -1, str[ 15 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_16, -1, str[ 16 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_17, -1, str[ 17 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_18, -1, str[ 18 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_19, -1, str[ 19 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_20, -1, str[ 20 ], 255 );
	//
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_21, -1, str[ 21 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_22, -1, str[ 22 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_23, -1, str[ 23 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_24, -1, str[ 24 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_25, -1, str[ 25 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_26, -1, str[ 26 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_27, -1, str[ 27 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_28, -1, str[ 28 ], 255 );
	for( int i = 0; i <= 28; i++ )
	{
		if( BES_TRAY_MENU( i ) ) continue;
		UINT uMenuId = (UINT) ( IDM_MENU_BASE  +  i );
		ModifyMenu( hMenu, uMenuId, MF_BYCOMMAND, uMenuId, str[ i ] );
	}
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_29, -1, str[ 29 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FIN_30, -1, str[ 30 ], 255 );
	HMENU hSubMenu;
	hSubMenu = GetSubMenu( hMenu, 2 );
	ModifyMenu( hSubMenu, 4U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 4 ), str[ 29] );
	hSubMenu = GetSubMenu( hMenu, 3 );
	ModifyMenu( hSubMenu, 6U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 6 ), str[ 30 ] );
	
	DrawMenuBar( hWnd );
	UpdateStatus( hWnd );
	CheckMenuItem( hMenu, IDM_REALTIME, MF_BYCOMMAND | flagRealtime );
	CheckMenuItem( hMenu, IDM_LOGGING, MF_BYCOMMAND | flagLogging );
}

VOID InitMenuSpa( const HWND hWnd )
{
	HMENU hMenu = GetMenu( hWnd );

	UINT flagRealtime = ( ( GetMenuState( hMenu, IDM_REALTIME, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;
	UINT flagLogging = ( ( GetMenuState( hMenu, IDM_LOGGING, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;

	TCHAR str[ 50 ][ 256 ];
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_SPA0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_SPA1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_SPA2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_SPA3, -1, str[ 3 ], 255 );

	for( UINT u = 0U; u < 4U; u++ )
	{
		ModifyMenu( hMenu, u, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hMenu, (int) u ), str[ u ] );
	}

	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_3, -1, str[ 3 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_4, -1, str[ 4 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_5, -1, str[ 5 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_6, -1, str[ 6 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_7, -1, str[ 7 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_8, -1, str[ 8 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_9, -1, str[ 9 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_10, -1, str[ 10 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_11, -1, str[ 11 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_12, -1, str[ 12 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_13, -1, str[ 13 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_14, -1, str[ 14 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_15, -1, str[ 15 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_16, -1, str[ 16 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_17, -1, str[ 17 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_18, -1, str[ 18 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_19, -1, str[ 19 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_20, -1, str[ 20 ], 255 );
	//
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_21, -1, str[ 21 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_22, -1, str[ 22 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_23, -1, str[ 23 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_24, -1, str[ 24 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_25, -1, str[ 25 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_26, -1, str[ 26 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_27, -1, str[ 27 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_28, -1, str[ 28 ], 255 );
	for( int i = 0; i <= 28; i++ )
	{
		if( BES_TRAY_MENU( i ) ) continue;
		UINT uMenuId = (UINT) ( IDM_MENU_BASE  +  i );
		ModifyMenu( hMenu, uMenuId, MF_BYCOMMAND, uMenuId, str[ i ] );
	}
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_29, -1, str[ 29 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, SPA_30, -1, str[ 30 ], 255 );
	
	
	HMENU hSubMenu;
	hSubMenu = GetSubMenu( hMenu, 2 );
	ModifyMenu( hSubMenu, 4U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 4 ), str[ 29 ] );
	hSubMenu = GetSubMenu( hMenu, 3 );
	ModifyMenu( hSubMenu, 6U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 6 ), str[ 30 ] );
	
	DrawMenuBar( hWnd );
	UpdateStatus( hWnd );
	CheckMenuItem( hMenu, IDM_REALTIME, MF_BYCOMMAND | flagRealtime );
	CheckMenuItem( hMenu, IDM_LOGGING, MF_BYCOMMAND | flagLogging );
}





VOID InitMenuFre( const HWND hWnd )
{
	HMENU hMenu = GetMenu( hWnd );

	UINT flagRealtime = ( ( GetMenuState( hMenu, IDM_REALTIME, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;
	UINT flagLogging = ( ( GetMenuState( hMenu, IDM_LOGGING, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;

	TCHAR str[ 50 ][ 256 ];
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_FRE0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_FRE1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_FRE2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_FRE3, -1, str[ 3 ], 255 );

	for( UINT u = 0U; u < 4U; u++ )
	{
		ModifyMenu( hMenu, u, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hMenu, (int) u ), str[ u ] );
	}

	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_3, -1, str[ 3 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_4, -1, str[ 4 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_5, -1, str[ 5 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_6, -1, str[ 6 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_7, -1, str[ 7 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_8, -1, str[ 8 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_9, -1, str[ 9 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_10, -1, str[ 10 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_11, -1, str[ 11 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_12, -1, str[ 12 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_13, -1, str[ 13 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_14, -1, str[ 14 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_15, -1, str[ 15 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_16, -1, str[ 16 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_17, -1, str[ 17 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_18, -1, str[ 18 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_19, -1, str[ 19 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_20, -1, str[ 20 ], 255 );
	//
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_21, -1, str[ 21 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_22, -1, str[ 22 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_23, -1, str[ 23 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_24, -1, str[ 24 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_25, -1, str[ 25 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_26, -1, str[ 26 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_27, -1, str[ 27 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_28, -1, str[ 28 ], 255 );
	
	for( int i = 0; i <= 28; i++ )
	{
		if( BES_TRAY_MENU( i ) ) continue;
		UINT uMenuId = (UINT) ( IDM_MENU_BASE  +  i );
		ModifyMenu( hMenu, uMenuId, MF_BYCOMMAND, uMenuId, str[ i ] );
	}
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_29, -1, str[ 29 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, FRE_30, -1, str[ 30 ], 255 );
	
	
	HMENU hSubMenu;
	hSubMenu = GetSubMenu( hMenu, 2 );
	ModifyMenu( hSubMenu, 4U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 4 ), str[ 29 ] );
	hSubMenu = GetSubMenu( hMenu, 3 );
	ModifyMenu( hSubMenu, 6U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 6 ), str[ 30 ] );
	
	DrawMenuBar( hWnd );
	UpdateStatus( hWnd );
	CheckMenuItem( hMenu, IDM_REALTIME, MF_BYCOMMAND | flagRealtime );
	CheckMenuItem( hMenu, IDM_LOGGING, MF_BYCOMMAND | flagLogging );
}




VOID InitMenuJpn( const HWND hWnd )
{
	HMENU hMenu = GetMenu( hWnd );

	UINT flagRealtime = ( ( GetMenuState( hMenu, IDM_REALTIME, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;

	UINT flagLogging = ( ( GetMenuState( hMenu, IDM_LOGGING, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;

	
	TCHAR str[ 50 ][ 256 ];
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_JPN0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_JPN1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_JPN2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_JPN3, -1, str[ 3 ], 255 );
	for( UINT u = 0U; u < 4U; u++ )
	{
		ModifyMenu( hMenu, u, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hMenu, (int) u ), str[ u ] );
	}


	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_3, -1, str[ 3 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_4, -1, str[ 4 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_5, -1, str[ 5 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_6, -1, str[ 6 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_7, -1, str[ 7 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_8, -1, str[ 8 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_9, -1, str[ 9 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_10, -1, str[ 10 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_11, -1, str[ 11 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_12, -1, str[ 12 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_13, -1, str[ 13 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_14, -1, str[ 14 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_15, -1, str[ 15 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_16, -1, str[ 16 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_17, -1, str[ 17 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_18, -1, str[ 18 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_19, -1, str[ 19 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_20, -1, str[ 20 ], 255 );
	//
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_21, -1, str[ 21 ], 255 );

	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_22, -1, str[ 22 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_23, -1, str[ 23 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_24, -1, str[ 24 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_25, -1, str[ 25 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_26, -1, str[ 26 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_27, -1, str[ 27 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_28, -1, str[ 28 ], 255 );
	for( int i = 0; i <= 28; i++ )
	{
		if( BES_TRAY_MENU( i ) ) continue;
		UINT uMenuId = (UINT) ( IDM_MENU_BASE  +  i );
		ModifyMenu( hMenu, uMenuId, MF_BYCOMMAND, uMenuId, str[ i ] );
	}
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_29, -1, str[ 29 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, JPN_30, -1, str[ 30 ], 255 );

	HMENU hSubMenu;
	hSubMenu = GetSubMenu( hMenu, 2 );
	ModifyMenu( hSubMenu, 
		4U,
		MF_BYPOSITION | MF_POPUP | MF_ENABLED | MF_STRING,
		(UINT) GetSubMenu( hSubMenu, 4 ),
		str[ 29 ]
	);
	hSubMenu = GetSubMenu( hMenu, 3 );
	ModifyMenu( hSubMenu, 6U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 6 ), str[ 30 ] );

	
	DrawMenuBar( hWnd );
	UpdateStatus( hWnd );
	CheckMenuItem( hMenu, IDM_REALTIME, MF_BYCOMMAND | flagRealtime );
	CheckMenuItem( hMenu, IDM_LOGGING, MF_BYCOMMAND | flagLogging );
}

VOID InitMenuChiT( const HWND hWnd )
{
	HMENU hMenu = GetMenu( hWnd );

	UINT flagRealtime = ( ( GetMenuState( hMenu, IDM_REALTIME, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;
	
	UINT flagLogging = ( ( GetMenuState( hMenu, IDM_LOGGING, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;

	TCHAR str[ 50 ][ 256 ];
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_CHI0T, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_CHI1T, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_CHI2T, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_CHI3T, -1, str[ 3 ], 255 );

	for( UINT u = 0U; u < 4U; u++ )
	{
		ModifyMenu( hMenu, u, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hMenu, (int) u ), str[ u ] );
	}

	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_3, -1, str[ 3 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_4, -1, str[ 4 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_5, -1, str[ 5 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_6, -1, str[ 6 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_7, -1, str[ 7 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_8, -1, str[ 8 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_9, -1, str[ 9 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_10, -1, str[ 10 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_11, -1, str[ 11 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_12, -1, str[ 12 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_13, -1, str[ 13 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_14, -1, str[ 14 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_15, -1, str[ 15 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_16, -1, str[ 16 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_17, -1, str[ 17 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_18, -1, str[ 18 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_19, -1, str[ 19 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_20, -1, str[ 20 ], 255 );
	
//
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_21, -1, str[ 21 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_22, -1, str[ 22 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_23, -1, str[ 23 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_24, -1, str[ 24 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_25, -1, str[ 25 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_26, -1, str[ 26 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_27, -1, str[ 27 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_28, -1, str[ 28 ], 255 );
	for( int i = 0; i <= 28; i++ )
	{
		if( BES_TRAY_MENU( i ) ) continue;
		UINT uMenuId = (UINT) ( IDM_MENU_BASE  +  i );
		ModifyMenu( hMenu, uMenuId, MF_BYCOMMAND, uMenuId, str[ i ] );
	}
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_29, -1, str[ 29 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHT_30, -1, str[ 30 ], 255 );

	HMENU hSubMenu;
	hSubMenu = GetSubMenu( hMenu, 2 );
	ModifyMenu( hSubMenu, 4U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 4 ), str[ 29 ] );
	hSubMenu = GetSubMenu( hMenu, 3 );
	ModifyMenu( hSubMenu, 6U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 6 ), str[ 30 ] );
	
	DrawMenuBar( hWnd );
	UpdateStatus( hWnd );
	CheckMenuItem( hMenu, IDM_REALTIME, MF_BYCOMMAND | flagRealtime );
	CheckMenuItem( hMenu, IDM_LOGGING, MF_BYCOMMAND | flagLogging );
}

VOID InitMenuChiS( const HWND hWnd )
{
	HMENU hMenu = GetMenu( hWnd );

	UINT flagRealtime = ( ( GetMenuState( hMenu, IDM_REALTIME, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;
	
	UINT flagLogging = ( ( GetMenuState( hMenu, IDM_LOGGING, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;

	TCHAR str[ 50 ][ 256 ];
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_CHI0S, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_CHI1S, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_CHI2S, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, S_MENU_CHI3S, -1, str[ 3 ], 255 );

	for( UINT u = 0U; u < 4U; u++ )
	{
		ModifyMenu( hMenu, u, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hMenu, (int) u ), str[ u ] );

	}

	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_3, -1, str[ 3 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_4, -1, str[ 4 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_5, -1, str[ 5 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_6, -1, str[ 6 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_7, -1, str[ 7 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_8, -1, str[ 8 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_9, -1, str[ 9 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_10, -1, str[ 10 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_11, -1, str[ 11 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_12, -1, str[ 12 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_13, -1, str[ 13 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_14, -1, str[ 14 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_15, -1, str[ 15 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_16, -1, str[ 16 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_17, -1, str[ 17 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_18, -1, str[ 18 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_19, -1, str[ 19 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_20, -1, str[ 20 ], 255 );
	//
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_21, -1, str[ 21 ], 255 );

	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_22, -1, str[ 22 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_23, -1, str[ 23 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_24, -1, str[ 24 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_25, -1, str[ 25 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_26, -1, str[ 26 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_27, -1, str[ 27 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_28, -1, str[ 28 ], 255 );
	for( int i = 0; i <= 28; i++ )
	{
		if( BES_TRAY_MENU( i ) ) continue;
		UINT uMenuId = (UINT) ( IDM_MENU_BASE  +  i );
		ModifyMenu( hMenu, uMenuId, MF_BYCOMMAND, uMenuId, str[ i ] );
	}
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_29, -1, str[ 29 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, CHS_30, -1, str[ 30 ], 255 );

	HMENU hSubMenu;
	hSubMenu = GetSubMenu( hMenu, 2 );
	ModifyMenu( hSubMenu, 4U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 4 ), str[ 29 ] );
	hSubMenu = GetSubMenu( hMenu, 3 );
	ModifyMenu( hSubMenu, 6U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 6 ), str[ 30 ] );
	
	DrawMenuBar( hWnd );
	UpdateStatus( hWnd );
	CheckMenuItem( hMenu, IDM_REALTIME, MF_BYCOMMAND | flagRealtime );
	CheckMenuItem( hMenu, IDM_LOGGING, MF_BYCOMMAND | flagLogging );
}

#endif

VOID InitToolTipsEng( TCHAR strToolTips[ 4 ][ 256 ] )
{
	lstrcpy( strToolTips[ 0 ], TEXT( "Select the target process" ) );
	lstrcpy( strToolTips[ 1 ], TEXT( "Stop limiting and/or watching totally" ) );
	lstrcpy( strToolTips[ 2 ], TEXT( "Control how much to limit the process" ) );
	lstrcpy( strToolTips[ 3 ], TEXT( "End the program" ) );
}



VOID InitMenuEng( const HWND hWnd )
{
	HMENU hMenu = GetMenu( hWnd );

	UINT flagRealtime = ( ( GetMenuState( hMenu, IDM_REALTIME, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;

	UINT flagLogging = ( ( GetMenuState( hMenu, IDM_LOGGING, MF_BYCOMMAND ) ) & MFS_CHECKED ) ? MFS_CHECKED : MFS_UNCHECKED ;

	TCHAR str[ 50 ][ 256 ] = {
		TEXT( "&File" ),
		TEXT( "&Do" ),
		TEXT( "&Options" ),
		TEXT( "&Help" )
	};
	for( UINT u = 0U; u < 4U; u++ )
	{
		ModifyMenu( hMenu, u, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hMenu, (int) u ), str[ u ] );
	}
#ifdef _UNICODE
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_0, -1, str[ 0 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_1, -1, str[ 1 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_2, -1, str[ 2 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_3, -1, str[ 3 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_4, -1, str[ 4 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_5, -1, str[ 5 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_6, -1, str[ 6 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_7, -1, str[ 7 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_8, -1, str[ 8 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_9, -1, str[ 9 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_10, -1, str[ 10 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_11, -1, str[ 11 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_12, -1, str[ 12 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_13, -1, str[ 13 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_14, -1, str[ 14 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_15, -1, str[ 15 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_16, -1, str[ 16 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_17, -1, str[ 17 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_18, -1, str[ 18 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_19, -1, str[ 19 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_20, -1, str[ 20 ], 255 );
	//
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_21, -1, str[ 21 ], 255 );

	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_22, -1, str[ 22 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_23, -1, str[ 23 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_24, -1, str[ 24 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_25, -1, str[ 25 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_26, -1, str[ 26 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_27, -1, str[ 27 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_28, -1, str[ 28 ], 255 );
	for( int i = 0; i <= 28; i++ )
	{
		if( BES_TRAY_MENU( i ) ) continue;
		UINT uMenuId = (UINT) ( IDM_MENU_BASE  +  i );
		ModifyMenu( hMenu, uMenuId, MF_BYCOMMAND, uMenuId, str[ i ] );
	}
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_29, -1, str[ 29 ], 255 );
	MultiByteToWideChar( CP_UTF8, MB_CUTE, ENG_30, -1, str[ 30 ], 255 );

	
	HMENU hSubMenu;
	hSubMenu = GetSubMenu( hMenu, 2 );
	ModifyMenu( hSubMenu, 4U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 4 ), str[ 29 ] );
	hSubMenu = GetSubMenu( hMenu, 3 );
	ModifyMenu( hSubMenu, 6U, MF_BYPOSITION | MF_POPUP, (UINT) GetSubMenu( hSubMenu, 6 ), str[ 30 ] );
#endif


	DrawMenuBar( hWnd );
	UpdateStatus( hWnd );
	CheckMenuItem( hMenu, IDM_REALTIME, MF_BYCOMMAND | flagRealtime );
	CheckMenuItem( hMenu, IDM_LOGGING, MF_BYCOMMAND | flagLogging );
}
