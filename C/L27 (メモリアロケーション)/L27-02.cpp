/*
課題番号　：L27-2
内容　　　：double型の領域をアロケーションして304.25を代入して、アロケーション領域に格納され
　　　　　　ている値を表示する。
　　　　　　main関数のみで行う。
ファイル名：L27-02.cpp
作成日　　：2016/1/20
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	double* p;		//アロケーション領域へのポインタ宣言

	//メモリのアロケーションと同時に初期化
	p = new double(304.25);

	//アロケーションできなかった場合
	if (*p == NULL)
	{
		cout << "アロケーション失敗" << endl;
	}
	//アロケーションできた場合
	else
	{
		//アロケーション領域の値を表示
		cout << "アロケーション領域の値=" << *p << endl;

		//アロケーション領域の解放（必ず行うこと）
		delete p;
	}

	_getch();
	return 0;
}


