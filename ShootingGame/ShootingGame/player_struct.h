#pragma once
#include "location_struct.h"

typedef struct Player_st {
	location player_pos;
	int player_hp; //ü��
	int player_damage; //���ݷ�
	int player_critical; //ġ��Ÿ
	double player_damage_percent; //damageȮ�� 8: 10%, 9: 25%, 10: 50%, 11: 25%, 12: 10%
	double player_critical_percent;	//criticalȮ�� 18: 6%, 19: 5%, 20: 4%
	int player_ammu_movement_tickrate; //�߻� �ӵ�
	bool player_attack;//�߻�
} player_st;