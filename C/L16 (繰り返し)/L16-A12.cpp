/*
課題番号　：L16-12
内容　　　：テストtestオブジェクトのメソッドで、0～100の得点を５つ入力しながら、
　　　　　　50以上の値と50未満の得点がそれぞれいくつあったのかを求める。
　　　　　　0～100の得点は個数にカウントしない。
　　　　　　ただし、while文を使うものとする。
　　　　　　個数用プロパティは、クラス定義で0に初期化する。
　　　　　　各個数（50未満と50以上）表示は、main関数で行う。
ファイル名：L16-A12.cpp
作成日　　：2015/10/01
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test{
	int under50 = 0;	//50未満個数用(0)
	int over50 = 0;		//50以上個数用(0)
public:
	//得点入力・個数判定メソッド
	void inpJudgeTen()
	{
		int ten;	//得点入力用

		//入力した値ごとに５０以上の値と５０未満の値の個数を求める処理を５回繰返す
		int cnt = 0;	//ループカウンタ

		while(cnt < 5)
		{
			cout << "得点を入力（得点は0～100）>> ";
			cin >> ten;

			//０以上１００以下の入力値の場合のみ個数を求め、ループカウンタを加算する
			if(0 <= ten && ten <= 100)
			{
				//50未満の値の個数を求める
				if(ten < 50)
				{
					under50 += 1;
				}
				//50以上の値の個数を求める
				else
				{
					over50 += 1;
				}

				cnt++;		//入力した値が、0～100の個数カウント
			}
		}
	}

	//50未満個数取得メソッド
	int getUnder50()
	{
		return under50;
	}

	//50以上個数取得メソッド
	int getOver50()
	{
		return over50;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;				//テストオブジェクト宣言

	test.inpJudgeTen();		//得点入力・個数判定メソッド

	cout << endl << "50以上=" << test.getOver50()
		<< " 50未満=" << test.getUnder50() << endl;

	_getch();
	return 0;
}
