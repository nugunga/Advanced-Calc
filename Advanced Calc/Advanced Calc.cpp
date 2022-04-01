#include <iostream>
#include <string>
#include "Global.h"
#include "Command.h"
#include "Utility.h"

using namespace std;

struct KeyWordTable OpertorTable[LAST_LIST] = {
	{ "+", Plus },
	{ "-", Minus },
	{ "*", Mult },
	{ "/", Divi },
	{ "%", Mod },
	{ "^", Pow },
	{ "&", Sqrt },
};

int main()
{
	string op;
	getline(cin, op);
	// word = 한 단어
	auto word = Scanner(op.c_str());
	double sum = -1;
	for (auto var : OpertorTable) {
		// string compare => compare는 비교하다, 여기서는 문자열을 비교하다라는 의미에요
		if (word[1] == var.Name) {
			sum = var.CallbackMethod(stoi(word[0]), stoi(word[2]));
			break; // < 반복문 멈춰!
		}
	}
	cout << sum << endl;

	return 0;
}
