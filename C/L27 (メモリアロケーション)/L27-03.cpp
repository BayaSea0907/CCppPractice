/*
課題番号　：L27-3
内容　　　：アロケーションしたint型の領域に整数を入力して、アロケーション領域に格納されている値
　　　　　　を表示する。
　　　　　　main関数のみで行う。
ファイル名：L27-03.cpp
作成日　　：2016/1/20
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int* p;		//アロケーション領域へのポインタ宣言

	//メモリのアロケーション
	p = new int;

	//アロケーションできなかった場合
	if (*p == NULL)
	{
		cout << "アロケーション失敗" << endl;
	}
	//アロケーションできた場合
	else
	{
		//アロケーション領域に入力
		cout << "整数を入力>> ";
		cin >> *p;

		//アロケーション領域の値を表示
		cout << "アロケーション領域の値=" << *p << endl;

		//アロケーション領域の解放（必ず行うこと）
		delete p;

	}

	_getch();
	return 0;
}


