#pragma once
#include "location_struct.h"

typedef struct Player_st {
	location player_pos;
	int player_hp; //ü��
	int player_damage; //���ݷ�
	int player_critical; //ġ��Ÿ
	double player_percent;
} player_st;