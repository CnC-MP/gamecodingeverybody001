#pragma once
#include "location_struct.h"

typedef struct Player_st {
	location player_pos;
	location player_hp_bar_pos;
	int player_max_hp; //ü��
	int player_hp; //ü��
	int player_damage; //���ݷ�
	double player_critical; //ġ��Ÿ ���
	double player_critical_percent;	//criticalȮ��
	int player_ammu_movement_tickrate; //�߻� �ӵ�
} player_st;