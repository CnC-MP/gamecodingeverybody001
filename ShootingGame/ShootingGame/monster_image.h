#pragma once
#include "interface_design_tool.h"
#include "monster_struct.h"

void monster_write(monster_st* monster, int stage);
void monster_templete01(int xpos, int ypos, int color1, int color2);
void monster_templete02(int xpos, int ypos, int color1, int color2);
void monster_templete03(int xpos, int ypos, int color1, int color2);
void monster_templete04(int xpos, int ypos, int color1, int color2);

void monster_write(monster_st* monster, int stage) {
	gotoxy(0, 0);
	printf("스테이지: %d", stage);
	color_change(0);
	fill2(monster->ex_monster_pos.xPos, monster->ex_monster_pos.yPos, monster->ex_monster_pos.xPos + 2 * monster->monster_width - 2, monster->ex_monster_pos.yPos + monster->monster_height - 1, "■");
	if (monster->monster_templete_num == 1) {
		monster_templete01(monster->monster_pos.xPos, monster->monster_pos.yPos, monster->monster_color1, monster->monster_color2);
	} else if (monster->monster_templete_num == 2) {
		monster_templete02(monster->monster_pos.xPos, monster->monster_pos.yPos, monster->monster_color1, monster->monster_color2);
	}
	else if (monster->monster_templete_num == 3) {
		monster_templete03(monster->monster_pos.xPos, monster->monster_pos.yPos, monster->monster_color1, monster->monster_color2);
	}
	else {
		monster_templete04(monster->monster_pos.xPos, monster->monster_pos.yPos, monster->monster_color1, monster->monster_color2);
	}
}

void monster_templete01(int xpos, int ypos, int color1, int color2) {
	color_change(color1);
	gotoxy(xpos + 2, ypos + 1);
	printf("▣");
	gotoxy(xpos + 2, ypos + 2);
	printf("▣");
	gotoxy(xpos + 2, ypos + 3);
	printf("▣");
	gotoxy(xpos + 4, ypos + 1);
	printf("▣");
	gotoxy(xpos + 4, ypos + 2);
	printf("▣");
	gotoxy(xpos + 4, ypos + 3);
	printf("▣");
	gotoxy(xpos + 6, ypos + 1);
	printf("▣");
	gotoxy(xpos + 6, ypos + 2);
	printf("▣");
	gotoxy(xpos + 6, ypos + 3);
	printf("▣");
	gotoxy(xpos + 8, ypos + 1);
	printf("▣");
	gotoxy(xpos + 8, ypos + 2);
	printf("▣");
	gotoxy(xpos + 8, ypos + 3);
	printf("▣");
	color_change(color2);
	gotoxy(xpos, ypos);
	printf("◈");
	gotoxy(xpos + 2, ypos);
	printf("◈");
	gotoxy(xpos + 8, ypos);
	printf("◈");
	gotoxy(xpos + 10, ypos);
	printf("◈");
	gotoxy(xpos, ypos + 4);
	printf("◈");
	gotoxy(xpos + 2, ypos + 4);
	printf("◈");
	gotoxy(xpos + 8, ypos + 4);
	printf("◈");
	gotoxy(xpos + 10, ypos + 4);
	printf("◈");
	color_change(7);
}

void monster_templete02(int xpos, int ypos, int color1, int color2) {
	color_change(color1);
	ypos += 2;
	gotoxy(xpos, ypos);
	printf("◈");
	gotoxy(xpos + 4, ypos - 2);
	printf("◈");
	gotoxy(xpos + 8, ypos);
	printf("◈");
	gotoxy(xpos + 4, ypos + 2);
	printf("◈");
	gotoxy(xpos + 4, ypos);
	printf("◈");
	color_change(color2);
	gotoxy(xpos + 2, ypos - 1);
	printf("▣");
	gotoxy(xpos + 2, ypos + 1);
	printf("▣");
	gotoxy(xpos + 6, ypos - 1);
	printf("▣");
	gotoxy(xpos + 6, ypos + 1);
	printf("▣");
	color_change(7);
}

void monster_templete03(int xpos, int ypos, int color1, int color2) {
	color_change(color1);
	ypos += 2;
	gotoxy(xpos, ypos);
	printf("◈");
	gotoxy(xpos + 2, ypos - 1);
	printf("◈");
	gotoxy(xpos + 4, ypos - 2);
	printf("◈");
	gotoxy(xpos + 2, ypos + 1);
	printf("◈");
	gotoxy(xpos + 8, ypos);
	printf("◈");
	gotoxy(xpos + 4, ypos + 2);
	printf("◈");
	gotoxy(xpos + 6, ypos - 1);
	printf("◈");
	gotoxy(xpos + 6, ypos + 1);
	printf("◈");
	color_change(color2);
	gotoxy(xpos + 2, ypos);
	printf("◈");
	gotoxy(xpos + 4, ypos);
	printf("◈");
	gotoxy(xpos + 6, ypos);
	printf("◈");
	color_change(7);
}

void monster_templete04(int xpos, int ypos, int color1, int color2) {
	color_change(color1);
	ypos += 1;
	gotoxy(xpos, ypos);
	printf("◈");
	gotoxy(xpos + 2, ypos - 1);
	printf("◈");
	gotoxy(xpos + 4, ypos);
	printf("◈");
	gotoxy(xpos + 2, ypos + 1);
	printf("◈");
	color_change(color2);
	gotoxy(xpos + 2, ypos);
	printf("◈");
	color_change(7);
}