#pragma once

#include "interface_design_tool.h"

void win_image(int stage);
void lose_image(int stage);

void win_image(int stage) {
	if (0 < stage || stage < 11){
		color_change(14);
		gotoxy(18, 14);
		printf("�̰��!!\n ");
		gotoxy(9, 15); 
		printf("���� 3�� �� 1���� ���Ͻÿ�.\n");
		gotoxy(2, 16);
		printf("���� ���������� ������ enterŰ�� �����ÿ�.");
		gotoxy(12, 4);
		printf("1 ��    2 ��    3 ��\n");
	}
}

void lose_image(int stage) {
	if (0 < stage || stage < 11) {
	gotoxy(18, 14);
	color_change(14);
	printf("�̰� ����!!");
	color_change(7);
	}
}