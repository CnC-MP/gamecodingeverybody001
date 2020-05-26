#pragma once

void battle();

void battle() {
	int temp;
	while (true) {
		//플레이어 표시 함수
		//몬스터 표시 함수
		//플레이어 총알 발사 함수
		//몬스터 총알 발사 함수
		//플레이어 총알 표시 함수
		//몬스터 총알 표시 함수
		if (_kbhit() != 0) {
			temp = _getch();
			if (temp == 'a' || temp == 'A') {

			}
			else if (temp == 's' || temp == 'S') {

			}
			else if (temp == 'd' || temp == 'D') {

			}
			else if (temp == 'w' || temp == 'W') {

			}
		}
	}
}