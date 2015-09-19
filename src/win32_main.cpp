#include <windows.h>

LRESULT CALLBACK 
MainWndCallback(
	HWND   wnd,
	UINT   msg,
	WPARAM wParam,	
	LPARAM lParam
) {

	// assume we handle all messages by default
	LRESULT retval = 0;

	switch (msg) 
	{
		case WM_SIZE: 
		{
			OutputDebugStringA("WM_SIZE\n");
		} break;

		case WM_DESTROY:
		{
			OutputDebugStringA("WM_DESTROY\n");

		} break;

		case WM_CLOSE:
		{
			OutputDebugStringA("WM_CLOSE\n");

		} break;

		case WM_ACTIVATEAPP:
		{
			OutputDebugStringA("WM_ACTIVATEAPP\n");

		} break;

		default:
		{
			// default window proc return
			retval = DefWindowProc(wnd, msg, wParam, lParam);

		} break;
	}

	return(retval);
}

int CALLBACK 
WinMain(
	HINSTANCE hCurInst,
	HINSTANCE hPrevInst,
	LPSTR cmd,
	int showCmd
) {
	WNDCLASS cMainWnd = {};
	cMainWnd.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
	cMainWnd.lpfnWndProc = MainWndCallback;
	cMainWnd.hInstance = hCurInst;
	cMainWnd.lpszClassName = "NerathylineWndClass";
	
	// unused properties
	// cMainWnd.cbClsExtra;
	// cMainWnd.cbWndExtra;
	// cMainWnd.hIcon;
	// cMainWnd.hCursor;
	// cMainWnd.hbrBackground;
	// cMainWnd.lpszMenuName;

	// MessageBoxA(
	// 	0, 
	// 	"This is a test", 
	// 	"Nerathyline", 
	// 	MB_OK|MB_ICONINFORMATION
	// );

	if (RegisterClass(&cMainWnd))
	{
		HWND hWnd = CreateWindowEx(
			0, 
			cMainWnd.lpszClassName,
			"Nerathyline",
			WS_OVERLAPPEDWINDOW|WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			0,
			0,
			hCurInst,
			0
		);

		if (hWnd)
		{
			MSG msg;
			BOOL msgRet;
			while ( (msgRet = GetMessage(&msg, hWnd, 0, 0)) != 0 )
			{
				if (msgRet == -1)
				{
					// hWnd is an invalid param
					// chaos, destruction, etc.
					break;
				} 
				else
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		}
		else
		{

		}
	}

	return(0);
}

