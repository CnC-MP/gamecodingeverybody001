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

void battle(int stage);
void monster_movement(monster_st* monster, int* monster_movement_tick, bool check);
void monster_fire(monster_st* monster, player_st* player, std::deque<monster_ammu>& deque_monster_ammu, int* monster_fire_tick, bool check);
void monster_ammu_movement(monster_st* monster, std::deque<monster_ammu>& deque_monster_ammu, int* monster_ammu_movement_tick);
void monster_ammu_delete(std::deque<monster_ammu>& deque_monster_ammu);
void monster_ammu_write(std::deque<monster_ammu>& deque_monster_ammu);


void battle(int stage) {
	int lower_limit = 26;
	int temp;
	int monster_movement_tick;
	int monster_fire_tick;
	int monster_ammu_movement_tick = 1;
	player_st player;
	player.player_pos.xPos = 22;
	player.player_pos.yPos = 26;	
	gotoxy(player.player_pos.xPos, player.player_pos.yPos);
	printf("♠");
	player.player_hp = 100;
	
	monster_st monster;
	monster_feature_determine(&monster, stage);
	monster.monster_pos.xPos = 23 - monster.monster_width;
	monster.monster_pos.yPos = 3;
	monster.ex_monster_pos.xPos = monster.monster_pos.xPos;
	monster.ex_monster_pos.yPos = monster.monster_pos.yPos;
	monster.preset = 0;
	
	
	std::deque<location> t;


	std::deque<monster_ammu> deque_monster_ammu;

	int upper_limit = monster.monster_pos.yPos + monster.monster_height + 9;
	monster_movement(&monster, &monster_movement_tick, true);
	monster_fire(&monster, &player, deque_monster_ammu, &monster_fire_tick, true);

	
	while (true) {
		monster_write(&monster);
		monster_movement(&monster, &monster_movement_tick, false);
		//플레이어 총알 발사 관련 함수 //직선  //Queue로 만듦
		//몬스터 총알 발사 관련 함수  //대각선 //Queue로 만듦
		monster_fire(&monster, &player, deque_monster_ammu, &monster_fire_tick, false);
		monster_ammu_delete(deque_monster_ammu);
		monster_ammu_movement(&monster, deque_monster_ammu, &monster_ammu_movement_tick);
		monster_ammu_write(deque_monster_ammu);
		//_getch();

		//플레이어 총알 표시 관련 함수
		//몬스터 총알 표시 관련 함수
		//피격 판단 및 추후 계산 
		if (_kbhit() != 0) {
			temp = _getch();
			if (temp == 32) {
				location temp_player_ammu_pos;
				temp_player_ammu_pos.xPos = player.player_pos.xPos;
				temp_player_ammu_pos.yPos = player.player_pos.yPos - 1;
				t.push_back(temp_player_ammu_pos);
			}
			else if (temp == 'a' || temp == 'A') {// 0
				if (player.player_pos.xPos > 0)
				{
					player.player_pos.xPos -= 2;
					player.player_pos.yPos;
				}
			}
			else if (temp == 's' || temp == 'S') { //밑에서 3번째까지
				if (player.player_pos.yPos < lower_limit) {
					player.player_pos.xPos;
					++player.player_pos.yPos;
				}
			}
			else if (temp == 'd' || temp == 'D') {
				if (player.player_pos.xPos < 44) {
					player.player_pos.xPos += 2; //44
					player.player_pos.yPos;
				}
			}
			else if (temp == 'w' || temp == 'W') {
				if (player.player_pos.yPos > upper_limit) {
					player.player_pos.xPos;					//
					--player.player_pos.yPos;
				}
			}

			gotoxy(player.player_pos.xPos, player.player_pos.yPos);
			printf("♠");
			if (temp == 'a' || temp == 'A') {
				gotoxy(player.player_pos.xPos + 2, player.player_pos.yPos);
				printf("  ");
			}
			else if (temp == 's' || temp == 'S') {
				gotoxy(player.player_pos.xPos, player.player_pos.yPos - 1);
				printf("  ");
			}
			else if (temp == 'd' || temp == 'D') {
				gotoxy(player.player_pos.xPos - 2, player.player_pos.yPos);
				printf("  ");
			}
			else if (temp == 'w' || temp == 'W') {
				gotoxy(player.player_pos.xPos, player.player_pos.yPos + 1);
				printf("  ");
			}
		}


	}
	Sleep(100);
}

void monster_movement(monster_st* monster, int* monster_movement_tick, bool check) {
	if ((*monster_movement_tick % monster->monster_tickrate) == 0 || check) {
		*monster_movement_tick = 1;
		if (monster->preset == 0) {
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
				monster->preset = rand() % (23 - monster->monster_width - monster->monster_pos.xPos / 2) + 1;
			}
			else {
				monster->preset = rand() % (monster->monster_pos.xPos / 2) + 1;
			}
		}
		monster->ex_monster_pos.xPos = monster->monster_pos.xPos;
		if (monster->monster_toward_right) {
			monster->monster_pos.xPos += 2;
			monster->preset--;
		}
		else {
			monster->monster_pos.xPos -= 2;
			monster->preset--;
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