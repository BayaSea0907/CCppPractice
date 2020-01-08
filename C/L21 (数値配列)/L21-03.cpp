/*
課題番号　：L21-3
内容　　　：L21-2を書き換えて、テストtestオブジェクトの配列に５件分の得点を入力して表示する。
　　　　　　得点の入力には、ループを使わない。
　　　　　　得点の入力と表示は、testオブジェクトで行う。
ファイル名：L21-03.cpp
作成日　　：2015/10/21
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test {
	int ten[5];	//得点配列
public:
	//得点入力メソッド
	void inpTen()
	{
		//配列要素に得点を入力
		cout << "得点を入力>> ";
		cin >> ten[0];

		cout << "得点を入力>> ";
		cin >> ten[1];

		cout << "得点を入力>> ";
		cin >> ten[2];

		cout << "得点を入力>> ";
		cin >> ten[3];

		cout << "得点を入力>> ";
		cin >> ten[4];
	}

	//得点表示メソッド
	void showTen()
	{
		//配列要素の表示　cnt：ループカウンタ
		for(int cnt = 0; cnt < 5; cnt++)
		{
			cout << ten[cnt] << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;			//テストオブジェクト宣言

	test.inpTen();		//得点入力メソッドの呼び出し
	test.showTen();		//得点表示メソッドの呼び出し

	_getch();
	return 0;
}


