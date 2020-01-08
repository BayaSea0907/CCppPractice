/*------------------------------------------------------------------------
|課題2 bitmask
| unsigned int型の32bit変数の内容を2進数で表示するプログラムを作る。
| ただし、条件として、マスクデータを使いビット演算で2進数を表示する。
|
|	2016/5/16	BayaSea
--------------------------------------------------------------------------*/
#include <iostream>

#define DATELENGTH 32

using namespace std;

int main()
{
	unsigned int maskDate;
	unsigned int souceDate = 1;
	unsigned int variable;

	cout << "0～4, 294, 967, 295までの値を入力してください >> ";
	cin >> variable;

	//2進数表示
	for (int i = 0; i < DATELENGTH; i++) {
		maskDate = souceDate << (DATELENGTH - (i + 1));

		(variable & maskDate) ? cout << 1 : cout << 0;

		if ((i + 1) % 4 == 0)	cout << " ";
	}

	system("pause");
	return 0;
}