#include "stdafx.h"
#include "Snake.h"

int nCmdShowG;
HINSTANCE Instanta_Curenta;                                
WCHAR titlu_fereastra[] = L"                          Main Menu";                  
WCHAR Clasa_Meniu[] = L"Fereastra_Principala"; 

//Ferestre
HWND Fereastra_Meniu, Fereastra_Joc;

//Butoane
HWND Singleplayer_Button, Doubleplayer_Button, Scor_Button, Exit_Button;

//Functii
ATOM                Creare_Clasa_Fereastra(HINSTANCE hInstance);
void                Initializare(HINSTANCE, int);
LRESULT CALLBACK    Procesare_Comenzi_Fereastra(HWND, UINT, WPARAM, LPARAM);
HWND				Creare_Buton(WCHAR text_buton[], int x, int y, int inaltime, int latime, int cod_buton);
HWND				Creare_Fereastra(WCHAR nume_clasa[], WCHAR titlu_fereastra[], int latime, int inaltime);

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Instanta_Curenta = hInstance;
	nCmdShowG = nCmdShow; // pastrez mCmdShow pentru a putea afisa si alte ferestre (vezi Creare_Fereastra)

    Creare_Clasa_Fereastra(hInstance); // creaza clasa ferestrei, cu proprietatile ei
	Initializare(hInstance, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SNAKE)), &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

ATOM Creare_Clasa_Fereastra(HINSTANCE hInstance) // adauga proprietati la fereastra de meniu
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
    wcex.hbrBackground  = CreateSolidBrush(RGB(200, 200, 200)); // coloreaza fereastra gri
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SNAKE);
    wcex.lpszClassName  = Clasa_Meniu; // numele clasei
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); //iconita ferestrei

    return RegisterClassExW(&wcex);
}

void Initializare(HINSTANCE hInstance, int nCmdShow)
{
   
	Fereastra_Meniu = Creare_Fereastra(Clasa_Meniu, L"                          Main Menu",300,425);
	SetMenu(Fereastra_Meniu, NULL); // elimina meniul de sus

   Singleplayer_Button = Creare_Buton(L"Single Player", 75, 90, 50, 150,1);
   Doubleplayer_Button = Creare_Buton(L"Double Player", 75, 160, 50, 150,2);
   Scor_Button = Creare_Buton(L"Scor", 75, 230, 50, 150,3);
   Exit_Button = Creare_Buton(L"Exit", 75, 300, 50, 150,4);

}

LRESULT CALLBACK Procesare_Comenzi_Fereastra(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT://coloreaza fereastra si scrie text in ea
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			WCHAR text[] =L"Snake!";
			SetBkColor(hdc, COLORREF RGB(200, 200, 200));//face fundalul textului gri
			SetTextColor(hdc, RGB(51, 153, 255));// seteaza culoarea textului
			SelectObject(hdc, (HFONT)CreateFont(40, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 100, 0, L"SYSTEM_FIXED_FONT"));

			TextOut(hdc, 98, 20, text, 6); //98 pixeli la stanga, 20 sus, dimensiune de 6
		
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_COMMAND: // comanda de la butoane
	{
		switch (LOWORD(wParam))
		{
			case 1: // cod_buton, vezi functia Creare_Buton
			{
				Fereastra_Joc = Creare_Fereastra(Clasa_Meniu,L"Single Player",500,500); // cand fereastra primeste o comanda de la butonul cu codul 1, creaza alta fereastra
				break;
			}
			case 2: // apasare buton 2
			{
				break;
			}
			case 3: // apasare buton 3
			{
				break;
			}
			case 4: // apasare buton 4
			{
				break;
			}
		}
	}
	break;
    case WM_DESTROY:
        PostQuitMessage(0); // cand apesi pe butonul de x se inchide totul
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

HWND Creare_Buton(WCHAR text_buton[], int x, int y, int inaltime, int latime, int cod_buton)
{
	HWND button = CreateWindow(
		L"BUTTON",  // Clasa predefinita (nu trebuie sa creem noi una)
		text_buton,      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		x,         // x position 
		y,         // y position 
		latime,        // Button width
		inaltime,        // Button height
		Fereastra_Meniu,     // Parent window
		(HMENU)cod_buton, // codul de la Procesare_Comenzi_Fereastra
		(HINSTANCE)GetWindowLong(Fereastra_Meniu, GWL_HINSTANCE),
		NULL);      // Pointer not needed.

	return button;
}

HWND Creare_Fereastra(WCHAR nume_clasa[], WCHAR titlu_fereastra[], int latime, int inaltime)
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop); //ia dimensiunile desktopului

	HWND fereastra = CreateWindow(nume_clasa, titlu_fereastra, WS_SYSMENU,
		(desktop.right-latime) / 2, (desktop.bottom- inaltime) / 2, latime, inaltime, nullptr, nullptr, Instanta_Curenta, nullptr); 
	// inaltime si latime fereastra si centrarea ferestrei - (desktop.right-latime)/2 si (desktop.bottom-inaltime)/2

	ShowWindow(fereastra, nCmdShowG);
	UpdateWindow(fereastra);

	return fereastra;
}
  