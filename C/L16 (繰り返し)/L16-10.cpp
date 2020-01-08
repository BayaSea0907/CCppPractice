/*
課題番号　：L16-10
内容　　　：L16-9を書き換えて、while文を使って総得点を求める。
ファイル名：L16-10.cpp
作成日　　：2015/10/01BayaSea15CU0210小林裕樹
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test{
	int total = 0;//総得点(0)
public:
	//得点入力・総得点設定メソッド
	void inpAddTen()
	{
		int ten;		//得点入力用

		//得点入力と総得点計算を３回繰返す
		int cnt = 0; 	//ループカウンタ

		while(cnt < 3)
		{
			cout << "点数を入力（例　100）>> ";
			cin >> ten;

			total += ten;	//総得点計算
			
			cnt++;			//ループカウンタに加算
		}
	}

	//総得点取得メソッド
	int getTotal()
	{
		return total;		//総得点を返す
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;		//テストオブジェクト宣言

	test.inpAddTen();	//得点入力と総得点設定メソッド呼び出し

	cout << "total=" << test.getTotal() << endl;

	_getch();
	return 0;
}

