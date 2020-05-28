#pragma once
#include "monster_struct.h"
#include <random>

#define MAX_MONSTER_IMAGE_NUM 5


void monster_feature_determine(monster_st* monster, int stage);

void monster_feature_determine(monster_st* monster, int stage) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uni_int(1, MAX_MONSTER_IMAGE_NUM);
	int temp;
	do {
		temp = uni_int(gen);
	} while (temp == monster->monster_image_num);
	monster->monster_image_num = temp;
	switch (temp) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}

	if (stage == 1) {
		monster->monster_ammu_movement_tickrate = 20;
		monster->monster_damage = 10;
		monster->monster_fire_tickrate = 150; //발사 속도
		monster->monster_height = 3;
		monster->monster_hp = 1000;
		monster->monster_max_hp = 1000;
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