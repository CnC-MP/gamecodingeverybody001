#pragma once
#include "interface_design_tool.h"
#include "monster_struct.h"

void monster_write(monster_st* monster);
void monster_feature_determine(monster_st* monster, int stage);

void monster_write(monster_st* monster) {
	color_change(0);
	horizontal(0, 1, 23, 1, "■");
	fill2(monster->ex_monster_pos.xPos, monster->ex_monster_pos.yPos, monster->ex_monster_pos.xPos + 2 * monster->monster_width - 2, monster->ex_monster_pos.yPos + monster->monster_height - 1, "■");
	color_change(7);
	fill2(monster->monster_pos.xPos, monster->monster_pos.yPos, monster->monster_pos.xPos + 2 * monster->monster_width - 2, monster->monster_pos.yPos + monster->monster_height - 1, "■"); //몬스터 아이콘 그리기
	//체력바
	gotoxy(0, 0); printf("%d %d %d %d", monster->monster_pos.xPos, monster->monster_pos.yPos, monster->ex_monster_pos.xPos, monster->ex_monster_pos.yPos);
}

void monster_feature_determine(monster_st* monster, int stage) {
	monster->monster_width = 3;
	monster->monster_height = 3;
	monster->monster_tickrate = 5;
}