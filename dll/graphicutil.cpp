// graphicutil.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include<windows.h>
#include<iostream>
#include<conio.h>

#include "graphicutil_GraphicUtil.h"

int clrscr()
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hndl, &csbi);
	DWORD written;
	DWORD N = csbi.dwSize.X * csbi.dwSize.Y;
	// csbi.dwCursorPosition.Y +
	// csbi.dwCursorPosition.X + 1;
	COORD curhome = { 0, 0 };

	// SetConsoleTextAttribute(hndl, 0xEC);
	FillConsoleOutputAttribute(hndl, 0x00, N, curhome, &written);
	FillConsoleOutputCharacter(hndl, ' ', N, curhome, &written);
	csbi.srWindow.Bottom -= csbi.srWindow.Top;
	csbi.srWindow.Top = 0;
	SetConsoleWindowInfo(hndl, TRUE, &csbi.srWindow);
	SetConsoleCursorPosition(hndl, curhome);

	return 0;
}

JNIEXPORT void JNICALL Java_graphicutil_GraphicUtil_clearScreen(JNIEnv *, jclass)
{
	clrscr();
}


void SetColor(const int Color)
{
	//    Colors are bit-encoded thus:

	//    bit 0 - foreground blue
	//    bit 1 - foreground green
	//    bit 2 - foreground red
	//    bit 3 - foreground intensity
	//
	//    bit 4 - background blue
	//    bit 5 - background green
	//    bit 6 - background red
	//    bit 7 - background intensity
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

JNIEXPORT void JNICALL Java_graphicutil_GraphicUtil_setTextColor(JNIEnv *env, jclass clazz, jint color) 
{
	SetColor(color);
}

int captureKeyboardArrows() 
{
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD   index = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	DWORD NumInputs = 0;
	DWORD InputsRead = 0;
	bool running = true;

	INPUT_RECORD irInput;

	GetNumberOfConsoleInputEvents(hstdin, &NumInputs);

	//while (running) {
		ReadConsoleInput(hstdin, &irInput, 1, &InputsRead);

		if (irInput.Event.KeyEvent.bKeyDown) {
			switch (irInput.Event.KeyEvent.wVirtualKeyCode) {
				case VK_ESCAPE:
					running = false;
					return VK_ESCAPE;
				case VK_LEFT:
				case VK_NUMPAD4:
					return VK_LEFT;
				case VK_UP:
				case VK_NUMPAD8:
					return VK_UP;
				case VK_RIGHT:
				case VK_NUMPAD6:
					return VK_RIGHT;
				case VK_DOWN:
				case VK_NUMPAD2:
					return VK_DOWN;
				default:
					return -1;
			}
		}
		return -1;
	//}
}

JNIEXPORT jint JNICALL Java_graphicutil_GraphicUtil_captureKeyboardArrows(JNIEnv *, jclass)
{
	return captureKeyboardArrows();
}

JNIEXPORT void JNICALL Java_graphicutil_GraphicUtil_setCursorPosition(JNIEnv *env, jclass clazz, jint x, jint y)
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD curXY = { x, y };
	SetConsoleCursorPosition(hndl, curXY);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

JNIEXPORT void JNICALL Java_graphicutil_GraphicUtil_hideCursor(JNIEnv *env, jclass clazz, jboolean hide)
{
	ShowConsoleCursor((bool)hide);
}


