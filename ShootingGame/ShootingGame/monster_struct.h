#pragma once
#include "location_struct.h"

typedef struct Monster_st {
	location monster_pos;
	location ex_monster_pos;
	int monster_width;
	int monster_height;
	int monster_tickrate;
	int monster_fire_tickrate;
	int monster_ammu_movement_tickrate;
	bool monster_toward_right;
	int monster_preset;
	int monster_hp;
	int monster_attack;
} monster_st;

typedef struct Monster_ammu {
	location begin;
	location end;
	location curr;
} monster_ammu;