#pragma once

/*
	Global.h �ڷ��� �����ϰ� �����ϴ� ���
*/

// Operation �����ϴ� ����
enum Operation {
	PLUS,
	MINUS,
	MULT,
	DIVI,
	MOD,
	POW,
	SQRT,
	LAST_LIST
};

// �Լ� �����Ͷ�� �θ��ϴ�.
// �Լ� ������ = �Լ��� �ּҸ� ����Ű�� ������ ����
typedef double (*FunctionPointer)(int, int);

// Keyword = Ű����, �ٽ� �ܾ�
struct KeyWordTable {
	// �������� �̸�
	const char* Name; // �迭��� �ǹ��ε� �츮�� �������� 2�� �̻� ���ڸ� ������ ��ɾ �����Ұ̴ϴ�.
	// �� �ش� �����ڰ� ȣ���ϴ� �Լ�.
	FunctionPointer CallbackMethod;
};