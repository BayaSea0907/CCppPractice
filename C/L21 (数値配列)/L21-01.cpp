/*
課題番号　：L21-1
内容　　　：テストtestオブジェクトの配列に格納した５件分の得点を表示する。
　　　　　　配列に格納する得点は、8, 33, 96, 2, 48
　　　　　　ループは使用しない。
　　　　　　得点の格納と表示は、testオブジェクトで行う。
ファイル名：L21-01.cpp
作成日　　：2015/10/21
作成者　　：BayaSea
*/

//プログラムを書き換えて確認すること：
//□配列の要素数を4にして宣言するとどうなるでしょうか？
//A.エラーが起こった

//□配列の要素数を6にして宣言するとどうなるでしょうか？
//A.すべて表示される

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test {
	int ten[5];		//得点配列宣言
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
		//配列要素の表示
		cout << ten[0] << endl;
		cout << ten[1] << endl;
		cout << ten[2] << endl;
		cout << ten[3] << endl;
		cout << ten[4] << endl;
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

