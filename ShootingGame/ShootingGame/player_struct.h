#pragma once
#include "location_struct.h"

typedef struct Player_st {
	location player_pos;
	int player_hp; //체력
	int player_damage; //공격력
	int player_critical; //치명타
	double player_damage_percent; //damage확률 8: 10%, 9: 25%, 10: 50%, 11: 25%, 12: 10%
	double player_critical_percent;	//critical확률 18: 6%, 19: 5%, 20: 4%
	int player_ammu_movement_tickrate; //발사 속도
	bool player_attack;//발사
} player_st;