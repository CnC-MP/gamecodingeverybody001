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
	printf("����  ����\n");
	color_change(7); 
	gotoxy(14, 21);
	printf("EnterŰ�� �����ÿ�");
}

void main_interface_image() {

}