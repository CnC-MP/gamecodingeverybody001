#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

int temp_interface_design_fuction = 0;
int temp2_interface_design_fuction = 0;


int wsleep(int* milliseconds, int* result);
void gotoxy(int x, int y); //커서를 x, y 좌표로 이동
void horizontal(int a, int b, int c, int d, const char e[3]); //e를 (a,b)에서 d번째 마다 c번 가로줄을 입력 
void vertical(int a, int b, int c, int d, const char e[3]); //e를 (a,b)에서 d번째 마다 c번 세로줄을 입력 
void diagonal_left(int a, int b, int c, int d, const char e[3]); //e를 (a,b)에서 d번째 마다 c번 왼쪽 대각선을 입력 
void diagonal_right(int a, int b, int c, int d, const char e[3]); //e를 (a,b)에서 d번째 마다 c번 오른쪽 대각선을 입력 
void diagonal_left2(int a, int b, int c, int d, const char e[3]); //e를 (a,b)에서 d번째 마다 c번 왼쪽 대각선을 입력 
void diagonal_right2(int a, int b, int c, int d, const char e[3]); //e를 (a,b)에서 d번째 마다 c번 오른쪽 대각선을 입력 
void fill(int x1, int y1, int x2, int y2, char c);
void fill2(int x1, int y1, int x2, int y2, const char c[3]);
void square(int x, int y, int a, int color, const char e[3]);
void rect(int x1, int y1, int x2, int y2, int color, const char e[3]);
void color_change(int a); //글자 색 바꾸기
				/*
					   색상표
				 0. 검정색
				 1. 파란색
				 2. 초록색
				 3. 옥색
				 4. 빨간색
				 5. 자주색
				 6. 노란색
				 7. 흰색(기본형)
				 8. 회색
				 9. 연한 파란색
				10. 연한 초록색
				11. 연한 옥색
				12. 연한 빨간색
				13. 연한 자주색
				14. 연한 노란색
				15. 진한 흰색   */




				//*************************************************************************



int wsleep(int* milliseconds, int* result)
{
	while (_kbhit() == 0)
	{
		if (*milliseconds <= 0)
			return -1;
		Sleep(10);
		*milliseconds -= 10;
	}
	*result = _getch();
	return *result;
}


void color_change(int a) //글자 색 바꾸기
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void gotoxy(int x, int y) //커서를 x, y 좌표로 이동 
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void horizontal(int a, int b, int c, int d, const char e[3]) //e를 (a,b)에서 d번째 마다 c번 가로줄을 입력 
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < c; temp_interface_design_fuction++)
	{
		gotoxy(a, b); printf("%s", e);
		a += (2 * d);
	}
}

void hori(int x, int y, int num, int color, const char e[3]) //e를 (a,b)에서 d번째 마다 c번 가로줄을 입력 
{
	color_change(color);
	x = 2 * x;
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < num; temp_interface_design_fuction++)
	{
		gotoxy(x, y); printf("%s", e);
		x += 2;
	}
	color_change(7);
}

void vertical(int a, int b, int c, int d, const char e[3]) //e를 (a,b)에서 d번째 마다 c번 세로줄을 입력 
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < c; temp_interface_design_fuction++)
	{
		gotoxy(a, b); printf("%s", e);
		b += d;
	}
}

void ver(int x, int y, int num, int color, const char e[3]) //e를 (a,b)에서 d번째 마다 c번 세로줄을 입력 
{
	color_change(color);
	x = 2 * x;
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < num; temp_interface_design_fuction++)
	{
		gotoxy(x, y); printf("%s", e);
		y += 1;
	}
	color_change(7);
}

void diagonal_left(int a, int b, int c, int d, const char e[3]) //e를 (a,b)에서 d번째 마다 c번 왼쪽 대각선을 입력 
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < c; temp_interface_design_fuction++)
	{
		gotoxy(a, b); printf("%s", e);
		a -= (2 * d); b += d;
	}
}

void diagonal_left2(int a, int b, int c, int d, const char e[3]) //e를 (a,b)에서 d번째 마다 c번 왼쪽 대각선을 입력 
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < c; temp_interface_design_fuction++)
	{
		gotoxy(a, b); printf("%s", e);
		a -= d; b += d;
	}
}

void diagonal_right(int a, int b, int c, int d, const char e[3]) //e를 (a,b)에서 d번째 마다 c번 오른쪽 대각선을 입력 
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < c; temp_interface_design_fuction++)
	{
		gotoxy(a, b); printf("%s", e);
		a += (2 * d); b += d;
	}
}

void diagonal_right2(int a, int b, int c, int d, const char e[3]) //e를 (a,b)에서 d번째 마다 c번 오른쪽 대각선을 입력 
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < c; temp_interface_design_fuction++)
	{
		gotoxy(a, b); printf("%s", e);
		a += d; b += d;
	}
}

void fill(int x1, int y1, int x2, int y2, char c)
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction <= (y2 - y1); temp_interface_design_fuction++)
	{
		gotoxy(x1, y1 + temp_interface_design_fuction);
		for (temp2_interface_design_fuction = 0; temp2_interface_design_fuction <= (x2 - x1); temp2_interface_design_fuction++)
		{
			printf("%c", c);
		}
	}
}

void fill2(int x1, int y1, int x2, int y2, const char c[3]) //특수기호로 채우기
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction <= (y2 - y1); temp_interface_design_fuction++)
	{
		gotoxy(x1, y1 + temp_interface_design_fuction);
		for (temp2_interface_design_fuction = 0; temp2_interface_design_fuction <= (x2 - x1); temp2_interface_design_fuction += 2)
		{
			printf("%s", c);
		}
	}
}

void square(int x, int y, int a, int color, const char e[3])
{
	color_change(color);
	horizontal(x, y, a, 1, e);
	horizontal(x, y + a - 1, a, 1, e);
	vertical(x, y + 1, a - 2, 1, e);
	vertical(x + 2 * a - 2, y + 1, a - 2, 1, e);
	color_change(7);
}

void rect(int x1, int y1, int x2, int y2, int color, const char e[3])
{
	color_change(color);
	horizontal(x1, y1, (x2 - x1 + 2) / 2, 1, e);
	horizontal(x1, y2, (x2 - x1 + 2) / 2, 1, e);
	vertical(x1, y1 + 1, y2 - y1 - 1, 1, e);
	vertical(x2, y1 + 1, y2 - y1 - 1, 1, e);
	color_change(7);
}