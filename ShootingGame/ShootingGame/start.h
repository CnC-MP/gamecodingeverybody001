#pragma once
#include "location_struct.h"
#include "cursor_status.h"
void battle();

void battle() {
	hideCursor();
	int temp;
	int upper_limit = 2;
	int down_limit = 27;
	location player_pos;
	player_pos.xPos = 22;
	player_pos.yPos = 27;
	gotoxy(player_pos.xPos, player_pos.yPos); 
	printf("��");
	while (true) {
		
		//���� ǥ�� ���� �Լ�
		//�÷��̾� �Ѿ� �߻� ���� �Լ�
		//���� �Ѿ� �߻� ���� �Լ�
		//�÷��̾� �Ѿ� ǥ�� ���� �Լ�
		//���� �Ѿ� ǥ�� ���� �Լ�
		//�ǰ� �Ǵ� �� ���� ���
		if (_kbhit() != 0) {
			temp = _getch();
			if (temp == 'a' || temp == 'A') {// 0
				if (player_pos.xPos > 0)
				{
					player_pos.xPos -= 2;
					player_pos.yPos;
				}
			}
			else if (temp == 's' || temp == 'S') { //�ؿ��� 3��������
				if (player_pos.yPos < down_limit) {
					player_pos.xPos;
					++player_pos.yPos;
				}
			}
			else if (temp == 'd' || temp == 'D') {
				if(player_pos.xPos<44){
					player_pos.xPos += 2; //44
				player_pos.yPos;
				}
			}
			else if (temp == 'w' || temp == 'W') {
				if (player_pos.yPos > upper_limit) {
					player_pos.xPos;					//
					--player_pos.yPos;
				}
			}
			
			gotoxy(player_pos.xPos, player_pos.yPos);
			printf("��");
			if (temp == 'a' || temp == 'A') {
				gotoxy(player_pos.xPos + 2, player_pos.yPos);
				printf("  ");
			}
			else if (temp == 's' || temp == 'S') {
				gotoxy(player_pos.xPos, player_pos.yPos - 1);
				printf("  ");
			}
			else if (temp == 'd' || temp == 'D') {
				gotoxy(player_pos.xPos - 2, player_pos.yPos);
				printf("  ");
			}
			else if (temp == 'w' || temp == 'W') {
				gotoxy(player_pos.xPos, player_pos.yPos + 1);
				printf("  ");
			}
			}
			

		}
		Sleep(100);
	}
