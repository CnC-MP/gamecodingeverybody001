#pragma once
#include "location_struct.h"

typedef struct Monster_st {
	location monster_pos;
	location ex_monster_pos;
	int monster_width;
	int monster_height;
	int monster_tickrate;
	bool monster_toward_right;
	int preset;
} monster_st;