#include <stdio.h>
#include <stdlib.h>
#include "interface_design_tool.h"
#include <conio.h>

int main() {
	system("mode con:cols=45 lines=30");
	
	gotoxy(18, 19);
	color_change(14);
	printf("게임 시작");
	_getch();
}