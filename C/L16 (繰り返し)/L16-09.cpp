/*
課題番号　：L16-9
内容　　　：テストtestオブジェクトのメソッドで、得点を３回入力しながら総得点を求める。
　　　　　　ただし、for文を使うものとする。
　　　　　　総得点は、プロパティで用意しておき、クラス定義で0に初期化しておく。
　　　　　　入力する得点は0以上とし、負値かどうかの判別は行わないものとする。
　　　　　　入力と表示はmain関数で行う。
ファイル名：L16-09.cpp
作成日　　：2015/10/01BayaSea15CU0210小林裕樹
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test{
	int total = 0;									//総得点(0)
public:
	//得点入力・総得点設定メソッド
	void inpAddTen()
	{
		int ten;									//得点入力用

		//得点入力と総得点計算を３回繰返す
		for(int cnt = 0; cnt < 3; cnt++)
		{
			cout << "点数を入力（例　100）>> ";
			cin >> ten;

			total += ten;							//総得点計算
		}
	}

	//総得点取得メソッド
	int getTotal()
	{
		return total;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;			//テストオブジェクト宣言

	test.inpAddTen();	//得点入力と総得点設定メソッド呼び出し

	cout << endl << "total=" << test.getTotal() << endl;

	_getch();
	return 0;
}

