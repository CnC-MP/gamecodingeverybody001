#pragma once
#include "location_struct.h"

typedef struct Player_st {
	location player_pos;
	int player_hp; //체력
	int player_damage; //공격력
	int player_critical; //치명타
	double player_percent;
} player_st;