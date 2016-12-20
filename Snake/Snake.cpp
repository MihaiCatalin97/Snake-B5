#include "stdafx.h"
#include "Snake.h"
#include "Meniu.h"

using namespace Snake;

HINSTANCE Instanta_Curenta;

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Instanta_Curenta = hInstance;

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Meniu form;
	Application::Run(%form);

	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SNAKE)), &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}
