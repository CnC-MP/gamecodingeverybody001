#pragma once

#include "interface_design_tool.h"
#include "player_struct.h"
#include <random>
#include <math.h>

void win_image(int stage);
void lose_image(int stage);
void random_box(player_st* player);

void win_image(int stage) {

}

void lose_image(int stage) {

}

void random_box(player_st* player) {
	int temp = 0;
	do {
		temp = _getch();
	} while ((temp != 49) && (temp != 50) && (temp != 51));
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uni_int(1, 44);

	int box[3][2];
	for (int i = 0; i < 3; i++) {
		box[i][0] = uni_int(gen);
		if (box[i][0] <= 5) {
			uni_int = std::uniform_int_distribution<int>(10, 30);
			box[i][1] = uni_int(gen);
			//내용 출력
			if (i == temp) {
				player->player_max_hp += box[i][1];
				player->player_hp += box[i][1];
			}
		}
		else if (box[i][0] <= 20) {
			uni_int = std::uniform_int_distribution<int>(30, 60);
			box[i][1] = uni_int(gen);
			//내용 출력
			if (i == temp) {
				player->player_hp += box[i][1];
				if (player->player_hp > player->player_max_hp) {
					player->player_hp = player->player_max_hp;
				}
			}
		}
		else if (box[i][0] <= 30) {
			uni_int = std::uniform_int_distribution<int>(4, 6);
			box[i][1] = uni_int(gen);
			//내용 출력
			if (i == temp) {
				player->player_damage += box[i][1];
			}
		}
		else if (box[i][0] <= 35) {
			std::uniform_real_distribution<double> uni_real(0.02, 0.05);
			box[i][1] = (int)round(1000 * uni_real(gen));
			//내용 출력
			if (i == temp) {
				player->player_critical_percent += (double)(box[i][1] / 1000.0);
			}
		}
		else if (box[i][0] <= 39) {
			std::uniform_real_distribution<double> uni_real(0.2, 0.4);
			box[i][1] = (int)round(1000 * uni_real(gen));
			//내용 출력
			if (i == temp) {
				player->player_critical += (double)(box[i][1] / 1000.0);
			}
		}
		else {
			uni_int = std::uniform_int_distribution<int>(1, 3);
			box[i][1] = uni_int(gen);
			//내용 출력
			if (i == temp) {
				player->player_ammu_movement_tickrate -= box[i][1];
				if (player->player_ammu_movement_tickrate < 1) {
					player->player_ammu_movement_tickrate = 1;
				}
			}
		}
	}
}