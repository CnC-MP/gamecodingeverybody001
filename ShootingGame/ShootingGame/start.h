#pragma once
#include <stdio.h>
#include "location_struct.h"
#include "monster_image.h"
#include "monster_struct.h"
#include <time.h>

void battle(int stage);
void monster_movement(monster_st* monster, int* tick, bool check);

void battle(int stage) {
	int temp;
	int tick;
	location player_pos;
	player_pos.xPos = 22;
	player_pos.yPos = 26;

	monster_st monster;
	monster_feature_determine(&monster, stage);
	monster.monster_pos.xPos = 23 - monster.monster_width;
	monster.monster_pos.yPos = 3;
	monster.ex_monster_pos.xPos = monster.monster_pos.xPos;
	monster.ex_monster_pos.yPos = monster.monster_pos.yPos;
	monster.preset = 0;
	monster_movement(&monster, &tick, true);


	while (true) {
		//�÷��̾� ǥ�� ���� �Լ�
		monster_write(&monster);
		monster_movement(&monster, &tick, false);
		//�÷��̾� �Ѿ� �߻� ���� �Լ�
		//���� �Ѿ� �߻� ���� �Լ�
		//�÷��̾� �Ѿ� ǥ�� ���� �Լ�
		//���� �Ѿ� ǥ�� ���� �Լ�
		//�ǰ� �Ǵ� �� ���� ���
		if (_kbhit() != 0) {
			temp = _getch();
			if (temp == 'a' || temp == 'A') {
				//����
			}
			else if (temp == 's' || temp == 'S') {
				//����
			}
			else if (temp == 'd' || temp == 'D') {
				//����
			}
			else if (temp == 'w' || temp == 'W') {
				//����
			}
		}
		Sleep(100);
	}
}

void monster_movement(monster_st* monster, int* tick, bool check) {
	if ((*tick % monster->monster_tickrate) == 0 || check) {
		*tick = 1;
		if (monster->preset == 0) {
			srand(time(NULL));
			if ((rand() % 2) == 0) {
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
		printf("in: %d", *tick);
		*tick = *tick + 1;
		printf("in: %d", *tick);
		_getch();
	}
}