#pragma once

#include "interface_design_tool.h"

void win_image(int stage);
void lose_image(int stage);

void win_image(int stage) {
	if (0 < stage || stage < 11){
		color_change(14);
		gotoxy(18, 14);
		printf("이겼다!!\n ");
		gotoxy(9, 15); 
		printf("선물 3개 중 1개를 택하시오.\n");
		gotoxy(2, 16);
		printf("다음 스테이지로 가려면 enter키를 누르시오.");
		gotoxy(12, 4);
		printf("1 ■    2 ■    3 ■\n");
	}
}

void lose_image(int stage) {
	if (0 < stage || stage < 11) {
	gotoxy(18, 14);
	color_change(14);
	printf("이걸 지누!!");
	color_change(7);
	}
}