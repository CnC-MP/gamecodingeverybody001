#pragma once

void battle();

void battle() {
	int temp;
	while (true) {
		//�÷��̾� ǥ�� ���� �Լ�
		//���� ǥ�� ���� �Լ�
		//�÷��̾� �Ѿ� �߻� ���� �Լ�
		//���� �Ѿ� �߻� ���� �Լ�
		//�÷��̾� �Ѿ� ǥ�� ���� �Լ�
		//���� �Ѿ� ǥ�� ���� �Լ�
		//�ǰ� �Ǵ� �� ���� ���
		if (_kbhit() != 0) {
			temp = _getch();
			if (temp == 'a' || temp == 'A') {
				//����
			}
			else if (temp == 's' || temp == 'S') {
				//����
			}
			else if (temp == 'd' || temp == 'D') {
				//����
			}
			else if (temp == 'w' || temp == 'W') {
				//����
			}
		}
		Sleep(100);
	}
}