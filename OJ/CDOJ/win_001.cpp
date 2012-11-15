#include <windows.h>

int _stdcall WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
                               LPSTR lpszCmdLine,int nCmdShow)
{
             HWND h;
             h = CreateWindow("BUTTON","Press Me",WS_OVERLAPPEDWINDOW,10,10,150,100,0,0,h,0);
             ShowWindow(h,nCmdShow);
             MessageBox(0,"Hi!","Waiting",MB_OK);
             return 0;
}
