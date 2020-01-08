/*
課題番号　：L21-6
内容　　　：L21-5を書き換えて、テストtestオブジェクトの配列に５件分の得点を入力した後、
　　　　　　平均点と平均点以上の個数を表示する。
　　　　　　平均点（実数値）と平均点以上の個数計算はtestオブジェクトのcalcAveKosuメソッドで行い、
　　　　　　いちどオブジェクトに格納する。
　　　　　　得点入力と表示はmain関数で行う。
ファイル名：L21-06.cpp
作成日　　：2015/10/21
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test {
	int ten[5];			//得点配列の宣言
	int total = 0;		//合計用（0）
	double ave;			//平均用
	int kosu = 0;		//平均以上の個数用（0）
public:
	//得点設定メソッド　n[]：得点配列
	void setTen(int n[])
	{
		//配列要素に得点を設定　cnt：ループカウンタ
		for(int cnt = 0; cnt < 5; cnt++)
		{
			ten[cnt] = n[cnt];
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

	//平均点・平均以上の個数計算メソッド
	void calcAveKosu()
	{
		//平均値の計算
		ave = (double)total / 5.0f;

		//平均値以上の個数の計算
		for(int cnt = 0; cnt < 5; cnt++)
		{
			//平均値以上
			if(ten[cnt] >= ave)
			{
				kosu++;
			}
		}
	}

	//平均点取得メソッド
	double getAve()
	{
		return ave;
	}

	//平均以上の個数取得メソッド
	int getKosu()
	{
		return kosu;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;		//テストオブジェクト宣言
	int ten[5];		//得点配列入力用

	//配列要素に得点を入力　cnt：ループカウンタ
	for (int cnt = 0; cnt < 5; cnt++){
		cout << "得点を入力>> ";
		cin >> ten[cnt];
	}

	test.setTen(ten);		//得点設定メソッドの呼び出し
	test.calcTotal();			//得点合計計算メソッドの呼び出し
	test.calcAveKosu();			//平均点・平均以上の個数計算メソッドの呼び出し

	cout << "平均点=" << test.getAve() << endl;
	cout << "平均点以上の個数=" << test.getKosu() << endl;

	_getch();
	return 0;
}



