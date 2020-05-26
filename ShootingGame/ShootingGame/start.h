#pragma once

void battle();

void battle() {
	int temp;
	while (true) {
		//플레이어 표시 관련 함수
		//몬스터 표시 관련 함수
		//플레이어 총알 발사 관련 함수
		//몬스터 총알 발사 관련 함수
		//플레이어 총알 표시 관련 함수
		//몬스터 총알 표시 관련 함수
		//피격 판단 및 추후 계산
		if (_kbhit() != 0) {
			temp = _getch();
			if (temp == 'a' || temp == 'A') {
				//내용
			}
			else if (temp == 's' || temp == 'S') {
				//내용
			}
			else if (temp == 'd' || temp == 'D') {
				//내용
			}
			else if (temp == 'w' || temp == 'W') {
				//내용
			}
		}
		Sleep(100);
	}
}