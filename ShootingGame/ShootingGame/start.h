#pragma once

#include <stdio.h>
#include "location_struct.h"
#include "monster_image.h"
#include "monster_struct.h"
#include <time.h>
#include "cursor_status.h"
#include "player_struct.h"
#include <deque>

void battle(int stage);
void monster_movement(monster_st* monster, int* monster_movement_tick, bool check);
void player_ammu_movement(player_st* player, std::deque<location>& t, int* player_fire_tick, bool check);

void battle(int stage) {
	int lower_limit = 26;
	int temp;
	int monster_movement_tick;
	int player_fire_tick = 1;
	player_st player;
	player.player_ammu_movement_tickrate = 20;
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
	monster.monster_preset = 0;
	
	
	std::deque<location> t;

	

	int upper_limit = monster.monster_pos.yPos + monster.monster_height + 9;
	monster_movement(&monster, &monster_movement_tick, true);
	player_ammu_movement(&player, t, &player_fire_tick, true);

	while (true) {
		monster_write(&monster);
		monster_movement(&monster, &monster_movement_tick, false);
		player_ammu_movement(&player, t, &player_fire_tick, false);
		//플레이어 총알 발사 관련 함수 //직선  //Queue로 만듦
		//몬스터 총알 발사 관련 함수  //대각선 //Queue로 만듦
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
		if (monster->monster_preset == 0) {
			srand(time(NULL));
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
		//_getch();
	}
}

void player_ammu_movement(player_st* player, std::deque<location> &t, int* player_fire_tick, bool check) {
	if ((*player_fire_tick % player->player_ammu_movement_tickrate) == 0 || check) {
		*player_fire_tick = 1;
		int temp = 0;
		for (auto& element : t) {
			gotoxy(element.xPos, element.yPos);
			printf("  ");
			element.yPos -= 1;
			if (element.yPos < 0) {
				t.erase(t.begin() + temp);
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

