#pragma once
#include "main_interface.h"
#include "cursor_status.h"
#include <conio.h>
#include "start.h"

void gamestart();

void gamestart() {
	int temp;
	system("mode con:cols=45 lines=30");
	while (true) {
		main_interface_write();
		temp = _getch();
		if (temp == 13) {
			battle();
		}
	}
}