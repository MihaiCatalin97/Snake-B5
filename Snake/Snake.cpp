#include "stdafx.h"
#include "Snake.h"

#define MAX_LOADSTRING 100
#define			BUTTON_IDENTIFIER	1

int nCmdShowG;
HINSTANCE instanta_curenta;                                
WCHAR titlu_fereastra[] = L"                          Main Menu";                  
WCHAR nume_clasa_fereastra[] = L"Fereastra_Principala";           
HWND fereastra_meniu;
HWND startsingleplayer, startdoubleplayer, scor, exitbutton;

ATOM                MyRegisterClass(HINSTANCE hInstance);
void                Initializare(HINSTANCE, int);
LRESULT CALLBACK    Procesare_Comenzi_Fereastra(HWND, UINT, WPARAM, LPARAM);
HWND Creare_Buton(WCHAR text_buton[], int x, int y, int inaltime, int latime);
HWND fereastra_joc;

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	nCmdShowG = nCmdShow;
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
    wcex.hbrBackground  = CreateSolidBrush(RGB(255, 255, 255)); // coloreaza fereastra gri
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

   startsingleplayer = Creare_Buton(L"Single Player", 75, 60, 50, 150);

   startdoubleplayer = Creare_Buton(L"Double Player", 75, 130, 50, 150);

   scor = Creare_Buton(L"Scor", 75, 200, 50, 150);

   exitbutton = Creare_Buton(L"Exit", 75, 270, 50, 150);

   ShowWindow(fereastra_meniu, nCmdShow);
   UpdateWindow(fereastra_meniu);
   afisarejoc();
}

HWND Creare_Buton(WCHAR text_buton[], int x, int y, int inaltime, int latime)
{
	HWND button = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		text_buton,      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		x,         // x position 
		y,         // y position 
		latime,        // Button width
		inaltime,        // Button height
		fereastra_meniu,     // Parent window
		(HMENU)BUTTON_IDENTIFIER,
		(HINSTANCE)GetWindowLong(fereastra_meniu, GWL_HINSTANCE),
		NULL);      // Pointer not needed.

	return button;
}

LRESULT CALLBACK Procesare_Comenzi_Fereastra(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			WCHAR text[] =L"Snake!";
			int iY = 20;
				TextOut(hdc, 125, iY, text, 6);
		
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case BUTTON_IDENTIFIER:
		{
			//Step 5: User click on the button
			if (HIWORD(wParam) == BN_CLICKED)
			{
				afisarejoc();
			}
		}
		break;
		}
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

void afisarejoc()
{
	RECT desktop;

	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);

	fereastra_joc = CreateWindow(nume_clasa_fereastra, titlu_fereastra, WS_SYSMENU,
		desktop.right / 2 - 150, desktop.bottom / 2 - 200, 300, 400, nullptr, nullptr, instanta_curenta, nullptr);

	ShowWindow(fereastra_joc, nCmdShowG);
	UpdateWindow(fereastra_joc);
}
  