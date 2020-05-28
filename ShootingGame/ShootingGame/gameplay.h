#pragma once
#include "main_interface.h"
#include "cursor_status.h"
#include <conio.h>
#include "start.h"
#include "player_struct.h"
#include "monster_struct.h"
#include "interface_design_tool.h"

void gamestart();

void gamestart() {
	int temp;
	hideCursor();
	system("mode con:cols=46 lines=30");
	while (true) {
		main_interface_write();
		temp = _getch();
		if (temp == 13) {
			player_st player;
			monster_st monster;
			monster.monster_templete_num = MAX_MONSTER_IMAGE_NUM + 1;
			monster.monster_color1 = 0;
			monster.monster_color2 = 0;

			player.player_ammu_movement_tickrate = 20;
			player.player_critical = 2.0;
			player.player_critical_percent = 0.15;
			player.player_damage = 10;
			player.player_hp = 100;
			player.player_max_hp = 100;
			player.player_pos.xPos = 22;
			player.player_pos.yPos = 26;
			system("cls");
			battle(1, &monster, &player);
		}
	}
}