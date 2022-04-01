
#include <iostream>

#include "Utility.h"

// ���� �Լ�
// ���� �Լ� = �� ���ϳ������� ȣ���� �� �ִ� �Լ�.
static bool _isDigit(int pCh) {
	return pCh >= '0' && pCh <= '9';
}
static bool _isAlpha(int pCh) {
	return islower(pCh) || isupper(pCh);
}
static bool _isSpace(int pCh) {
	return (pCh >= 9 && pCh <= 13) || pCh == 32;
}
static bool _isOperation(int pCh) {
	return (pCh >= 33  && pCh <= 47) ||
		   (pCh >= 58  && pCh <= 64) ||
		   (pCh >= 91  && pCh <= 96) ||
		   (pCh >= 123 && pCh <= 126);
}

std::vector<std::string> Scanner(const char* Input) {
	std::vector<std::string> Ret;

	// strlen = ���ڿ��� ���̸� �˷��ݴϴ�.
	for (size_t i = 0; i < strlen(Input); i++)
	{
		if (_isSpace(Input[i])) continue;
		if (_isOperation(Input[i])) {
			char _temp_ary[2];
			_temp_ary[0] = Input[i];
			_temp_ary[1] = '\0';
			Ret.push_back(std::string(_temp_ary));
			continue;
		}
		// TODO: ���߿� ��� ������Ʈ
		if (_isAlpha(Input[i])) continue;
		
		if (_isDigit(Input[i])) {
			long total = Input[i] - '0';
			i += 1;
			if (i <= strlen(Input)) {
				while (_isDigit(Input[i])) {
					total *= 10;
					total += Input[i] - '0';
					i++;
				}
			}
			i -= 1; // �ݺ����� ������ 1�� �߰�����?
					// �׷��� ���� �� ���ڸ� �ѹ� �� �˻��ϰ� �����ž�.

			Ret.push_back(std::string(std::to_string(total)));
			continue;
		}

		// �������� �ʴ� ���ڿ��Դϴ�.
		std::cout << "�������� �ʴ� ���ڿ��Դϴ�." << std::endl;
	}

	return Ret; // Ret => Return, ��ȯ�ϴ� ��.
}