#pragma once
#include <stdlib.h>

#include "interface_design_tool.h"

void main_interface_write();
void main_interface_image();

void main_interface_write() {
	system("cls");
	main_interface_image();
	gotoxy(18, 19);
	color_change(14);
	printf("게임  시작\n");
	color_change(7);
	gotoxy(14, 21);
	printf("Enter키를 누르시오\n");
}

void main_interface_image() {

}