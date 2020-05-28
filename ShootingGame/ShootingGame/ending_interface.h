#pragma once

#include "interface_design_tool.h"
#include "player_struct.h"
#include <random>
#include <math.h>

void win_image(int stage);
void lose_image(int stage);
void random_box(player_st* player);

void win_image(int stage) {
	color_change(14);
	gotoxy(19, 18);
	printf("이겼다!!\n ");
	gotoxy(10, 20); 
	printf("선물 3개 중 1개를 택하시오.\n");
	gotoxy(4, 8);
	printf("1 ■             2 ■             3 ■\n");
	color_change(7);
}

void lose_image(int stage) {
	gotoxy(18, 14);
	color_change(14);
	printf("이걸 지누!!");
	color_change(11);
	gotoxy(10, 22);
	printf("Press any key to continue.");
	color_change(7);
}

void random_box(player_st* player) {
	int temp = 0;
	do {
		temp = _getch();
	} while ((temp != 49) && (temp != 50) && (temp != 51));
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uni_int(1, 44);
	color_change(11);
	int box[3][2];
	int i;
	for (i = 0; i < 3; i++) {
		box[i][0] = uni_int(gen);
		if (box[i][0] <= 5) {
			uni_int = std::uniform_int_distribution<int>(10, 30);
			box[i][1] = uni_int(gen);
			//내용 출력
			gotoxy(13, 11 + i);
			printf("%d. 최대 체력 +%d", i + 1, box[i][1]);
			if ((i + 49) == temp) {
				player->player_max_hp += box[i][1];
				player->player_hp += box[i][1];
				if (player->player_max_hp > 9999) {
					player->player_max_hp = 9999;
					if (player->player_hp > player->player_max_hp) {
						player->player_hp = player->player_max_hp;
					}
				}
			}
		}
		else if (box[i][0] <= 20) {
			uni_int = std::uniform_int_distribution<int>(30, 60);
			box[i][1] = uni_int(gen);
			//내용 출력
			gotoxy(13, 11 + i);
			printf("%d. 체력 회복 +%d", i + 1, box[i][1]);
			if ((i + 49) == temp) {
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
			gotoxy(13, 11 + i);
			printf("%d. 공격력 증가 +%d", i + 1, box[i][1]);
			if ((i + 49) == temp) {
				player->player_damage += box[i][1];
				if (player->player_damage > 999) {
					player->player_damage = 999;
				}
			}
		}
		else if (box[i][0] <= 35) {
			std::uniform_real_distribution<double> uni_real(0.02, 0.05);
			box[i][1] = (int)round(1000 * uni_real(gen));
			//내용 출력
			gotoxy(13, 11 + i);
			printf("%d. 치명타율 증가 +%.1f%%", i + 1, (double)box[i][1] / 10.0);
			if ((i + 49) == temp) {
				player->player_critical_percent += (double)(box[i][1] / 1000.0);
				if (player->player_critical_percent > 0.999) {
					player->player_critical_percent = 0.999;
				}
			}
		}
		else if (box[i][0] <= 39) {
			std::uniform_real_distribution<double> uni_real(0.2, 0.4);
			box[i][1] = (int)round(1000 * uni_real(gen));
			//내용 출력
			gotoxy(13, 11 + i);
			printf("%d. 치명피해 증가 +%.1f%%", i + 1, (double)box[i][1] / 10.0);
			if ((i + 49) == temp) {
				player->player_critical += (double)(box[i][1] / 1000.0);
			}
		}
		else {
			uni_int = std::uniform_int_distribution<int>(1, 3);
			box[i][1] = uni_int(gen);
			//내용 출력
			gotoxy(13, 11 + i);
			printf("%d. 탄속 증가 +%d", i + 1, box[i][1]);
			if ((i + 49) == temp) {
				player->player_ammu_movement_tickrate -= box[i][1];
				if (player->player_ammu_movement_tickrate < 1) {
					player->player_ammu_movement_tickrate = 1;
				}
			}
		}
	}
	gotoxy(15, 15);
	printf("%d번 선택", temp - 48);
	gotoxy(10, 22);
	printf("Press any key to continue.");
	color_change(7);
}