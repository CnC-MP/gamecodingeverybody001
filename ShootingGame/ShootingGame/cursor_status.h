#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

typedef struct Cursor_location {
	int xPos;
	int yPos;
} cursor_location;

int enter_key = 0;
int close_key = 0;

void hideCursor();
void showCursor();
void vertical_cursor(cursor_location* loc, int y_min, int y_max, int y_diff, int enter, int close);
void horizontal_cursor(cursor_location* loc, int x_min, int x_max, int x_diff, int enter, int close);
void ver_hori_cursor(cursor_location* loc, int x_min, int x_max, int x_diff, int y_min, int y_max, int y_diff, int enter, int close);

void hideCursor() //커서 숨기기 
{
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.bVisible = FALSE;
	CurInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void showCursor() //커서 보이기 
{
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.bVisible = TRUE;
	CurInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void vertical_cursor(cursor_location* loc, int y_min, int y_max, int y_diff, int enter, int close)
{
	int menumove = _getch();
	switch (menumove)
	{
	case 's':
	case 'S':
		loc->yPos -= y_diff;
		if (loc->yPos < y_min)
			loc->yPos = y_max;
		break;

	case 'w':
	case 'W':
		loc->yPos += y_diff;
		if (loc->yPos > y_max)
			loc->yPos = y_min;
		break;

	case 13:
		enter_key = 13;
		if (enter == 0)
			enter_key = 0;
		break;

	case 8:
		close_key = 8;
		if (close == 0)
			close_key = 0;
		break;
	}
}

void horizontal_cursor(cursor_location* loc, int x_min, int x_max, int x_diff, int enter, int close)
{
	int menumove = _getch();
	switch (menumove)
	{
	case 'a':
	case 'A':
		loc->xPos -= x_diff;
		if (loc->xPos < x_min)
			loc->xPos = x_max;
		break;

	case 'd':
	case 'D':
		loc->xPos += x_diff;
		if (loc->xPos > x_max)
			loc->xPos = x_min;
		break;

	case 13:
		enter_key = 13;
		if (enter == 0)
			enter_key = 0;
		break;

	case 8:
		close_key = 8;
		if (close == 0)
			close_key = 0;
		break;
	}
}

void ver_hori_cursor(cursor_location* loc, int x_min, int x_max, int x_diff, int y_min, int y_max, int y_diff, int enter, int close)
{
	int menumove = _getch();
	switch (menumove)
	{
	case 'a':
	case 'A':
		loc->xPos -= x_diff;
		if (loc->xPos < x_min)
			loc->xPos = x_max;
		break;

	case 'd':
	case 'D':
		loc->xPos += x_diff;
		if (loc->xPos > x_max)
			loc->xPos = x_min;
		break;

	case 's':
	case 'S':
		loc->yPos -= y_diff;
		if (loc->yPos < y_min)
			loc->yPos = y_max;
		break;

	case 'w':
	case 'W':
		loc->yPos += y_diff;
		if (loc->yPos > y_max)
			loc->yPos = y_min;
		break;

	case 13:
		enter_key = 13;
		if (enter == 0)
			enter_key = 0;
		break;

	case 8:
		close_key = 8;
		if (close == 0)
			close_key = 0;
		break;
	}
}