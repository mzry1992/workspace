#include <windows.h>

LRESULT _stdcall WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HDC hDC = GetWindowDC(hWnd);
    static HRGN hRgn = CreateRectRgn(120, 70, 280, 230);

    switch(uMsg)
    {
    case WM_ERASEBKGND:
         {
             DefWindowProc(hWnd, uMsg, wParam, lParam);
             FillRgn(hDC, hRgn, CreateSolidBrush(RGB(255, 165, 0))); // Orange
             SelectObject(hDC, hRgn);
             return 0;
         }

     case WM_CREATE:
         {
             HRGN hRgn1 = CreateEllipticRgn(0, 0, 400, 300);
             HRGN hRgn2 = CreateEllipticRgn(150, 100, 250, 200);
             CombineRgn(hRgn1, hRgn1, hRgn2, RGN_XOR);
             SetWindowRgn(hWnd, hRgn1, TRUE);
             DeleteObject(hRgn1);
             DeleteObject(hRgn2);
             break;
         }

     case WM_LBUTTONDOWN:
         {
             SendMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);
             break;
         }

     case WM_DESTROY:
         {
             DeleteObject(hRgn);
             ReleaseDC(hWnd, hDC);
             PostQuitMessage(0);
             break;
         }
     }
     return DefWindowProc(hWnd, uMsg, wParam, lParam);;
 }

 int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, BOOL)
 {
     WNDCLASS wc = {0};
     wc.lpszClassName = L"wndclass";
     wc.hbrBackground = CreateSolidBrush(RGB(255, 99, 71));
     wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
     wc.hCursor = LoadCursor(NULL, IDC_ARROW);
     wc.lpfnWndProc = WinProc;
     RegisterClass(&wc);

     HWND hWnd = CreateWindowExW(WS_EX_LAYERED, L"wndclass", L"Window", WS_POPUP|WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, 0, 0, hInstance, 0);
     if (hWnd == NULL)
         return 1;

     SetLayeredWindowAttributes(hWnd, NULL, 178, LWA_ALPHA); // Tomato

     MSG msg = {0};
     while (GetMessage(&msg, 0, 0, 0))
     {
        DispatchMessage(&msg);
   }

    return 0;
}
