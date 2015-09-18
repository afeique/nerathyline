#include <windows.h>

LRESULT CALLBACK 
MainWindowProc(HWND   wnd,
  			   UINT   msg,
  			   WPARAM wParam,
			   LPARAM lParam)
{

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
WinMain(HINSTANCE curInst,
		HINSTANCE prvInst,
		LPSTR cmd,
		int showCmd) 
{
	WNDCLASS MainWnd = {};
	MainWnd.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
	MainWnd.lpfnWndProc;
	MainWnd.hInstance = curInst;
	MainWnd.lpszClassName = "MainWndClass";
	
	// unused properties
	// MainWnd.cbClsExtra;
	// MainWnd.cbWndExtra;
	// MainWnd.hIcon;
	// MainWnd.hCursor;
	// MainWnd.hbrBackground;
	// MainWnd.lpszMenuName;

	MessageBoxA(NULL, 
		"This is a test", 
		"Nerathyline", 
		MB_OK|MB_ICONINFORMATION);

	RegisterClass(MainWnd);

	return(0);
}

