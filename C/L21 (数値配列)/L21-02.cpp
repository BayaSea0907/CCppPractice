/*
課題番号　：L21-2
内容　　　：L21-1を書き換えて、テストtestオブジェクトの配列に格納した５件分の得点を、
　　　　　　ループを使って同じ結果を表示する。
　　　　　　得点の格納と表示は、testオブジェクトで行う。
ファイル名：L21-02.cpp
作成日　　：2015/10/21
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test {
	int ten[5];		//得点配列
public:
	//得点設定メソッド
	void setTen()
	{
		//配列要素に得点を格納
		ten[0] = 8;
		ten[1] = 33;
		ten[2] = 96;
		ten[3] = 2;
		ten[4] = 48;
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

	test.setTen();		//得点設定メソッドの呼び出し
	test.showTen();		//得点表示メソッドの呼び出し

	_getch();
	return 0;
}



