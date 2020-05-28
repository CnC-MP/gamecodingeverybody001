#pragma once
#include "location_struct.h"

typedef struct Player_st {
	location player_pos;
	location player_hp_bar_pos;
	int player_max_hp; //체력
	int player_hp; //체력
	int player_damage; //공격력
	double player_critical; //치명타 계수
	double player_critical_percent;	//critical확률
	int player_ammu_movement_tickrate; //발사 속도
} player_st;