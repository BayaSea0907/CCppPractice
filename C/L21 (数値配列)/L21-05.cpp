/*
課題番号　：L21-5
内容　　　：L21-4を書き換えて、テストtestオブジェクトの配列に５件分の得点を入力した後、合計を表示する。
　　　　　　合計計算はtestオブジェクトのメソッドで行い、いちどオブジェクトに格納する。
　　　　　　得点入力と表示はmain関数で行う。
ファイル名：L21-05.cpp
作成日　　：2015/10/21
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test {
	int ten[5];			//得点配列
	int total = 0;		//合計用（0）
public:
	//得点設定メソッド　n[]：得点配列
	void setTen(int n[])
	{
		//配列要素に得点を設定　cnt：ループカウンタ
		for(int cnt = 0; cnt < 5; cnt++)
		{
			ten[cnt] = n[cnt] ;
		}
	}

	//得点合計計算メソッド
	void calcTotal()
	{
		//合計の計算　cnt：ループカウンタ
		for(int cnt = 0; cnt < 5; cnt++)
		{
			total += ten[cnt];
		}
	}

	//合計取得メソッド
	int getTotal()
	{
		return total;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;		//テストオブジェクト宣言
	int ten[5];		//得点配列入力用

	//配列要素に得点を入力　cnt：ループカウンタ
	for (int cnt = 0; cnt < 5; cnt++)
	{
		cout << "得点を入力>> ";
		cin >> ten[cnt];
	}

	test.setTen(ten);		//得点設定メソッドの呼び出し
	test.calcTotal();			//得点合計計算メソッドの呼び出し

	cout << "合計点=" << test.getTotal() << endl;

	_getch();
	return 0;
}


