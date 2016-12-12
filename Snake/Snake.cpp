#include "stdafx.h"
#include "Snake.h"

#define MAX_LOADSTRING 100

HINSTANCE instanta_curenta;                                
WCHAR titlu_fereastra[] = L"                          Main Menu";                  
WCHAR nume_clasa_fereastra[] = L"Fereastra_Principala";           
HWND fereastra_meniu;

ATOM                MyRegisterClass(HINSTANCE hInstance);
void                Initializare(HINSTANCE, int);
LRESULT CALLBACK    Procesare_Comenzi_Fereastra(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{

    MyRegisterClass(hInstance);

	Initializare(hInstance, nCmdShow);

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SNAKE));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = Procesare_Comenzi_Fereastra;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SNAKE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = CreateSolidBrush(RGB(210, 210, 210)); // coloreaza fereastra gri
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SNAKE);
    wcex.lpszClassName  = nume_clasa_fereastra;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

void Initializare(HINSTANCE hInstance, int nCmdShow)
{
   instanta_curenta = hInstance;

   RECT desktop;

   const HWND hDesktop = GetDesktopWindow();
   GetWindowRect(hDesktop, &desktop);

   fereastra_meniu = CreateWindow(nume_clasa_fereastra, titlu_fereastra, WS_SYSMENU,
      desktop.right/2 - 150, desktop.bottom/2 - 200, 300, 400, nullptr, nullptr, hInstance, nullptr); // creeaza fereastra pe mijlocul ecranului
   SetMenu(fereastra_meniu, NULL); // elimina meniul de sus

   ShowWindow(fereastra_meniu, nCmdShow);
   UpdateWindow(fereastra_meniu);
}

LRESULT CALLBACK Procesare_Comenzi_Fereastra(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
