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
void gotoxy(int x, int y); //Ŀ���� x, y ��ǥ�� �̵�
void horizontal(int a, int b, int c, int d, const char e[3]); //e�� (a,b)���� d��° ���� c�� �������� �Է� 
void vertical(int a, int b, int c, int d, const char e[3]); //e�� (a,b)���� d��° ���� c�� �������� �Է� 
void diagonal_left(int a, int b, int c, int d, const char e[3]); //e�� (a,b)���� d��° ���� c�� ���� �밢���� �Է� 
void diagonal_right(int a, int b, int c, int d, const char e[3]); //e�� (a,b)���� d��° ���� c�� ������ �밢���� �Է� 
void diagonal_left2(int a, int b, int c, int d, const char e[3]); //e�� (a,b)���� d��° ���� c�� ���� �밢���� �Է� 
void diagonal_right2(int a, int b, int c, int d, const char e[3]); //e�� (a,b)���� d��° ���� c�� ������ �밢���� �Է� 
void fill(int x1, int y1, int x2, int y2, char c);
void fill2(int x1, int y1, int x2, int y2, const char c[3]);
void square(int x, int y, int a, int color, const char e[3]);
void rect(int x1, int y1, int x2, int y2, int color, const char e[3]);
void color_change(int a); //���� �� �ٲٱ�
				/*
					   ����ǥ
				 0. ������
				 1. �Ķ���
				 2. �ʷϻ�
				 3. ����
				 4. ������
				 5. ���ֻ�
				 6. �����
				 7. ���(�⺻��)
				 8. ȸ��
				 9. ���� �Ķ���
				10. ���� �ʷϻ�
				11. ���� ����
				12. ���� ������
				13. ���� ���ֻ�
				14. ���� �����
				15. ���� ���   */




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


void color_change(int a) //���� �� �ٲٱ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void gotoxy(int x, int y) //Ŀ���� x, y ��ǥ�� �̵� 
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void horizontal(int a, int b, int c, int d, const char e[3]) //e�� (a,b)���� d��° ���� c�� �������� �Է� 
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < c; temp_interface_design_fuction++)
	{
		gotoxy(a, b); printf("%s", e);
		a += (2 * d);
	}
}

void hori(int x, int y, int num, int color, const char e[3]) //e�� (a,b)���� d��° ���� c�� �������� �Է� 
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

void vertical(int a, int b, int c, int d, const char e[3]) //e�� (a,b)���� d��° ���� c�� �������� �Է� 
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < c; temp_interface_design_fuction++)
	{
		gotoxy(a, b); printf("%s", e);
		b += d;
	}
}

void ver(int x, int y, int num, int color, const char e[3]) //e�� (a,b)���� d��° ���� c�� �������� �Է� 
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

void diagonal_left(int a, int b, int c, int d, const char e[3]) //e�� (a,b)���� d��° ���� c�� ���� �밢���� �Է� 
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < c; temp_interface_design_fuction++)
	{
		gotoxy(a, b); printf("%s", e);
		a -= (2 * d); b += d;
	}
}

void diagonal_left2(int a, int b, int c, int d, const char e[3]) //e�� (a,b)���� d��° ���� c�� ���� �밢���� �Է� 
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < c; temp_interface_design_fuction++)
	{
		gotoxy(a, b); printf("%s", e);
		a -= d; b += d;
	}
}

void diagonal_right(int a, int b, int c, int d, const char e[3]) //e�� (a,b)���� d��° ���� c�� ������ �밢���� �Է� 
{
	for (temp_interface_design_fuction = 0; temp_interface_design_fuction < c; temp_interface_design_fuction++)
	{
		gotoxy(a, b); printf("%s", e);
		a += (2 * d); b += d;
	}
}

void diagonal_right2(int a, int b, int c, int d, const char e[3]) //e�� (a,b)���� d��° ���� c�� ������ �밢���� �Է� 
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

void fill2(int x1, int y1, int x2, int y2, const char c[3]) //Ư����ȣ�� ä���
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