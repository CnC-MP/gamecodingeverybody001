#pragma once

#include <stdio.h>
#include "location_struct.h"
#include "monster_image.h"
#include "monster_struct.h"
#include <time.h>
#include "cursor_status.h"
#include "player_struct.h"
#include <deque>
#include <math.h>
#include <random>
#include "monster_feature.h"
#include "ending_interface.h"

void battle(int stage, monster_st* monster, player_st* player);
void monster_movement(monster_st* monster, int* monster_movement_tick, bool check);
void monster_fire(monster_st* monster, player_st* player, std::deque<monster_ammu>& deque_monster_ammu, int* monster_fire_tick, bool check);
void monster_ammu_movement(monster_st* monster, std::deque<monster_ammu>& deque_monster_ammu, int* monster_ammu_movement_tick);
void monster_ammu_delete(std::deque<monster_ammu>& deque_monster_ammu);
void monster_ammu_write(std::deque<monster_ammu>& deque_monster_ammu);
void player_ammu_movement(player_st* player, std::deque<location>& deque_player_ammu, int* player_fire_tick, bool check);
int monster_be_shot(player_st* player, monster_st* monster, std::deque<location>& deque_player_ammu); //0: 게임 진행, 1: 게임 승리, 2: 게임 패배
int player_be_shot(player_st* player, monster_st* monster, std::deque<monster_ammu>& deque_monster_ammu);
int monster_take_damage(player_st* player, monster_st* monster);
int player_take_damage(player_st* player, monster_st* monster);
void monster_health_bar_write(monster_st* monster);
void player_health_bar_write(player_st* player);

void battle(int stage, monster_st* monster, player_st* player) {
	int temp_getch;
	int stage_finish = 0;
	int temp_stage_finish;
	int lower_limit = 26;
	int temp;
	int monster_movement_tick;
	int monster_fire_tick;
	int monster_ammu_movement_tick = 1;
	int player_fire_tick = 1;

	monster_feature_determine(monster, stage);

	gotoxy(player->player_pos.xPos, player->player_pos.yPos);
	printf("♠");

	
	std::deque<location> deque_player_ammu;
	std::deque<monster_ammu> deque_monster_ammu;

	int upper_limit = monster->monster_pos.yPos + monster->monster_height + 9;
	
	monster_movement(monster, &monster_movement_tick, true);
	monster_fire(monster, player, deque_monster_ammu, &monster_fire_tick, true);
	player_ammu_movement(player, deque_player_ammu, &player_fire_tick, true);

	

	while (stage_finish == 0) {
		monster_write(monster);
		monster_health_bar_write(monster);
		monster_movement(monster, &monster_movement_tick, false);
		player_ammu_movement(player, deque_player_ammu, &player_fire_tick, false);
		player_be_shot(player, monster, deque_monster_ammu);
		player_health_bar_write(player);

		//플레이어 총알 발사 관련 함수 //직선  //Queue로 만듦
		//몬스터 총알 발사 관련 함수  //대각선 //Queue로 만듦
		monster_fire(monster, player, deque_monster_ammu, &monster_fire_tick, false);
		monster_ammu_delete(deque_monster_ammu);
		monster_ammu_movement(monster, deque_monster_ammu, &monster_ammu_movement_tick);
		monster_ammu_write(deque_monster_ammu);
		//_getch();

		//플레이어 총알 표시 관련 함수
		//몬스터 총알 표시 관련 함수
		//피격 판단 및 추후 계산 

		//monster_take_damage(player, monster);
		//player_take_damage(player, monster);

		stage_finish = monster_be_shot(player, monster, deque_player_ammu);
		temp_stage_finish = player_be_shot(player, monster, deque_monster_ammu);
		if (temp_stage_finish == 2) {
			stage_finish = 2;
		}

		if (_kbhit() != 0) {
			temp = _getch();
			if (temp == 32) {
				location temp_player_ammu_pos;
				temp_player_ammu_pos.xPos = player->player_pos.xPos;
				temp_player_ammu_pos.yPos = player->player_pos.yPos - 1;
				deque_player_ammu.push_back(temp_player_ammu_pos);
			}
			else if (temp == 'a' || temp == 'A') {// 0
				if (player->player_pos.xPos > 0)
				{
					player->player_pos.xPos -= 2;
					player->player_pos.yPos;
				}
			}
			else if (temp == 's' || temp == 'S') { //밑에서 3번째까지
				if (player->player_pos.yPos < lower_limit) {
					player->player_pos.xPos;
					++player->player_pos.yPos;
				}
			}
			else if (temp == 'd' || temp == 'D') {
				if (player->player_pos.xPos < 44) {
					player->player_pos.xPos += 2; //44
					player->player_pos.yPos;
				}
			}
			else if (temp == 'w' || temp == 'W') {
				if (player->player_pos.yPos > upper_limit) {
					player->player_pos.xPos;					//
					--player->player_pos.yPos;
				}
			}

			gotoxy(player->player_pos.xPos, player->player_pos.yPos);
			printf("♠");
			if (temp == 'a' || temp == 'A') {
				gotoxy(player->player_pos.xPos + 2, player->player_pos.yPos);
				printf("  ");
			}
			else if (temp == 's' || temp == 'S') {
				gotoxy(player->player_pos.xPos, player->player_pos.yPos - 1);
				printf("  ");
			}
			else if (temp == 'd' || temp == 'D') {
				gotoxy(player->player_pos.xPos - 2, player->player_pos.yPos);
				printf("  ");
			}
			else if (temp == 'w' || temp == 'W') {
				gotoxy(player->player_pos.xPos, player->player_pos.yPos + 1);
				printf("  ");
			}
		}
		Sleep(10);
	}
	//while 바깥
	if (stage_finish == 1) {
		//승리
		system("cls");
		win_image(stage);
		temp_getch = _getch();
	}
	else {
		//패배
		system("cls");
		lose_image(stage);
		temp_getch = _getch();
	}


}

void monster_movement(monster_st* monster, int* monster_movement_tick, bool check) {
	if ((*monster_movement_tick % monster->monster_tickrate) == 0 || check) {
		*monster_movement_tick = 1;
		if (monster->monster_preset == 0) {
			srand((unsigned int)time(NULL));
			if (monster->monster_pos.xPos == 0) {
				monster->monster_toward_right = true;
			}
			else if (monster->monster_pos.xPos == (46 - 2 * monster->monster_width)) {
				monster->monster_toward_right = false;
			}
			else if ((rand() % 2) == 0) {
				monster->monster_toward_right = false;
			}
			else {
				monster->monster_toward_right = true;
			}
			if (monster->monster_toward_right) {
				monster->monster_preset = rand() % (23 - monster->monster_width - monster->monster_pos.xPos / 2) + 1;
			}
			else {
				monster->monster_preset = rand() % (monster->monster_pos.xPos / 2) + 1;
			}
		}
		monster->ex_monster_pos.xPos = monster->monster_pos.xPos;
		if (monster->monster_toward_right) {
			monster->monster_pos.xPos += 2;
			monster->monster_preset--;
		}
		else {
			monster->monster_pos.xPos -= 2;
			monster->monster_preset--;
		}
	}
	else {
		*monster_movement_tick = *monster_movement_tick + 1;
	}
}

void monster_fire(monster_st* monster, player_st* player, std::deque<monster_ammu>& deque_monster_ammu, int* monster_fire_tick, bool check) {
	if ((*monster_fire_tick % monster->monster_fire_tickrate) == 0 || check) {
		*monster_fire_tick = 1;
		monster_ammu temp_monster_ammu;
		temp_monster_ammu.begin.xPos = monster->monster_pos.xPos + monster->monster_width - 1;
		temp_monster_ammu.begin.yPos = monster->monster_pos.yPos + monster->monster_height;
		temp_monster_ammu.curr.xPos = temp_monster_ammu.begin.xPos;
		temp_monster_ammu.curr.yPos = temp_monster_ammu.begin.yPos;
		temp_monster_ammu.end.xPos = player->player_pos.xPos;
		temp_monster_ammu.end.yPos = player->player_pos.yPos;
		deque_monster_ammu.push_back(temp_monster_ammu);
	}
	else {
		*monster_fire_tick = *monster_fire_tick + 1;
	}
}

void monster_ammu_movement(monster_st* monster, std::deque<monster_ammu>& deque_monster_ammu, int* monster_ammu_movement_tick) {
	if ((*monster_ammu_movement_tick % monster->monster_ammu_movement_tickrate) == 0) {
		*monster_ammu_movement_tick = 1;
		int temp = 0;
		for (auto& element : deque_monster_ammu) {
			element.curr.yPos++;
			if (element.curr.yPos > 26) {
				deque_monster_ammu.erase(deque_monster_ammu.begin() + temp);
				continue;
			}
			element.curr.xPos = (int)round(element.begin.xPos + ((double)element.curr.yPos - element.begin.yPos) * ((double)element.end.xPos - element.begin.xPos) / ((double)element.end.yPos - element.begin.yPos));
			if (element.curr.xPos < 0 || element.curr.xPos > 44) {
				deque_monster_ammu.erase(deque_monster_ammu.begin() + temp);
			}
			temp++;
		}
	}
	else {
		*monster_ammu_movement_tick = *monster_ammu_movement_tick + 1;
	}
}

void monster_ammu_delete(std::deque<monster_ammu>& deque_monster_ammu) {
	color_change(0);
	for (auto& element : deque_monster_ammu) {
		gotoxy(element.curr.xPos, element.curr.yPos);
		printf("  ");
	}
	color_change(7);
}

void monster_ammu_write(std::deque<monster_ammu>& deque_monster_ammu) {
	color_change(12);
	for (auto& element : deque_monster_ammu) {
		gotoxy(element.curr.xPos, element.curr.yPos);
		printf("◆");
	}
	color_change(7);
}

void player_ammu_movement(player_st* player, std::deque<location>& deque_player_ammu, int* player_fire_tick, bool check) {
	if ((*player_fire_tick % player->player_ammu_movement_tickrate) == 0 || check) {
		*player_fire_tick = 1;
		int temp = 0;
		for (auto& element : deque_player_ammu) {
			gotoxy(element.xPos, element.yPos);
			printf("  ");
			element.yPos -= 1;
			if (element.yPos < 0) {
				deque_player_ammu.erase(deque_player_ammu.begin() + temp);
				continue;
			}
			gotoxy(element.xPos, element.yPos);
			printf("◆");
			temp++;
		}
	}
	else
		*player_fire_tick = *player_fire_tick + 1;
}

int monster_be_shot(player_st* player, monster_st* monster, std::deque<location>& deque_player_ammu) {
	int temp = 0;
	int check = 0;
	for (auto& element : deque_player_ammu) {
		bool bool_temp = false;
		if ((element.xPos >= (monster->monster_pos.xPos - 1)) && (element.xPos <= (monster->monster_pos.xPos + 2 * monster->monster_width - 1))) {
			if ((element.yPos >= monster->monster_pos.yPos) && (element.yPos <= (monster->monster_pos.yPos + monster->monster_pos.yPos - 1))) {
				bool_temp = true;
			}
		}
		if (bool_temp) {
			deque_player_ammu.erase(deque_player_ammu.begin() + temp);
			//피격 후 계산
			check = monster_take_damage(player, monster);
		}
		temp++;
	}
	return check;
}

int player_be_shot(player_st* player, monster_st* monster, std::deque<monster_ammu>& deque_monster_ammu) {
	int temp = 0;
	int check = 0;
	for (auto& element : deque_monster_ammu) {
		if (element.curr.xPos == player->player_pos.xPos && element.curr.yPos == player->player_pos.yPos) {
				deque_monster_ammu.erase(deque_monster_ammu.begin() + temp);
				//플레이어 피격 후 계산
				check = player_take_damage(player, monster);
				continue;
		}
		temp++;
	}
	return check;
}

void player_health_bar_write(player_st* player) {
	
	gotoxy(player->player_hp_bar_pos.xPos, player->player_hp_bar_pos.yPos);
	printf("                    ");
	player->player_hp_bar_pos.xPos = player->player_pos.xPos - 9;
	player->player_hp_bar_pos.yPos = player->player_pos.yPos + 2;
	if (player->player_hp_bar_pos.xPos < 0) {
		player->player_hp_bar_pos.xPos = 0;
	}
	else if (player->player_hp_bar_pos.xPos > 26) {
		player->player_hp_bar_pos.xPos = 26;
	}


}

int monster_take_damage(player_st* player, monster_st* monster) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<double> dist;
	int damage = (int)round(player->player_damage * (1 + dist(gen) / 3));
	if ((rand() / RAND_MAX) < player->player_critical_percent) {
		damage = (int)round(damage * player->player_critical);
	}
	if (damage < 1) {
		damage = 1;
	}
	monster->monster_hp -= damage;
	if (monster->monster_hp <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int player_take_damage(player_st* player, monster_st* monster) {
	player->player_hp -= monster->monster_damage;
	if (player->player_hp <= 0) {
		return 2;
	}
	else {
		return 0;
	}
}

void monster_health_bar_write(monster_st* monster) {
	int num = (int)round(10 * monster->monster_hp / monster->monster_max_hp);
	gotoxy(monster->monster_hp_bar_pos.xPos, monster->monster_hp_bar_pos.yPos);
	printf("                    ");
	monster->monster_hp_bar_pos.xPos = monster->monster_pos.xPos + monster->monster_width - 10;
	if (monster->monster_hp_bar_pos.xPos < 0) {
		monster->monster_hp_bar_pos.xPos = 0;
	}
	if (monster->monster_hp_bar_pos.xPos > 26) {
		monster->monster_hp_bar_pos.xPos = 26;
	}

	gotoxy(monster->monster_hp_bar_pos.xPos, monster->monster_hp_bar_pos.yPos);
	for (int i = 0; i < num; i++) {
		printf("■");
	}
	for (int i = 10; i > num; i--) {
		printf("□");
	}

	gotoxy(0, 10); printf("%4d", monster->monster_hp);
}