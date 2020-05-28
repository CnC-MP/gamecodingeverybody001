#pragma once
#include "monster_struct.h"
#include <random>
#include <math.h>

#define MAX_MONSTER_IMAGE_NUM 4


void monster_feature_determine(monster_st* monster, int stage);

void monster_feature_determine(monster_st* monster, int stage) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uni_int1(1, MAX_MONSTER_IMAGE_NUM);
	std::uniform_int_distribution<int> uni_int2(1, 14);
	int temp1;
	int temp2;
	int temp3;
	do {
		temp1 = uni_int1(gen);
		temp2 = uni_int2(gen);
		temp3 = uni_int2(gen);
	} while ((temp1 == monster->monster_templete_num) && (temp2 == monster->monster_color1) && (temp3 == monster->monster_color2));
	monster->monster_templete_num = temp1;
	monster->monster_color1 = temp2;
	monster->monster_color2 = temp3;

	if (monster->monster_templete_num == 1) {
		monster->monster_height = 5;
		monster->monster_width = 6;
	}
	else if (monster->monster_templete_num == 2) {
		monster->monster_height = 5;
		monster->monster_width = 5;
	}
	else if (monster->monster_templete_num == 3) {
		monster->monster_height = 5;
		monster->monster_width = 5;
	}
	else if (monster->monster_templete_num == 4) {
		monster->monster_height = 3;
		monster->monster_width = 3;
	}

	int potential = stage * 100;
	int arr[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = 0;
	}
	uni_int1 = std::uniform_int_distribution<int>(0, 4);
	for (int i = 0; i < potential; i++) {
		arr[uni_int1(gen)]++;
	}
	for (int i = 2; i < 5; i++) {
		if (arr[i] == 0) {
			arr[i] = 1;
		}
	}
	monster->monster_max_hp = 4 * arr[0];
	monster->monster_damage = (int)round(0.5 * arr[1]);
	monster->monster_ammu_movement_tickrate = (int)round(1 / (0.0025 * arr[2]));
	monster->monster_fire_tickrate = (int)round(1 / (0.00025 * arr[3]));
	monster->monster_tickrate = (int)round(1 / (0.001 * arr[4]));


	monster->monster_pos.xPos = 23 - monster->monster_width;
	monster->monster_pos.yPos = 3;
	monster->monster_hp = monster->monster_max_hp;
	monster->ex_monster_pos.xPos = monster->monster_pos.xPos;
	monster->ex_monster_pos.yPos = monster->monster_pos.yPos;
	monster->monster_preset = 0;
	monster->monster_hp_bar_pos.xPos = 13;
	monster->monster_hp_bar_pos.yPos = 1;
}