#pragma once
#include "monster_struct.h"


void monster_feature_determine(monster_st* monster, int stage);

void monster_feature_determine(monster_st* monster, int stage) {
	if (stage == 1) {
		monster->monster_ammu_movement_tickrate = 20;
		monster->monster_damage = 10;
		monster->monster_fire_tickrate = 150; //발사 속도
		monster->monster_height = 3;
		monster->monster_hp = 100;
		monster->monster_max_hp = 100;
		monster->monster_tickrate = 50; //움직이는 속도
		monster->monster_width = 3;
	}
	monster->monster_pos.xPos = 23 - monster->monster_width;
	monster->monster_pos.yPos = 3;
	monster->ex_monster_pos.xPos = monster->monster_pos.xPos;
	monster->ex_monster_pos.yPos = monster->monster_pos.yPos;
	monster->monster_preset = 0;
	monster->monster_hp_bar_pos.xPos = 13;
	monster->monster_hp_bar_pos.yPos = 1;
}