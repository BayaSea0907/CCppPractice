/*
課題番号　：L16-Special4
内容　　　：範囲regionオブジェクトに入力した整数値を２つ設定して、小さい値から大きい値までの総合計
　　　　　　を表示する。
　　　　　　合計はいちどオブジェクトに格納しておく。
　　　　　　整数値入力と総合計表示はmain関数で行う。
ファイル名：L16-S4.cpp
作成日　　：2015/10/15
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//範囲クラス定義
class Region {
	int start;				//下限数値
	int end; 				//上限数値
	int sum = 0;			//合計用（0）
public:
	//範囲数値設定メソッド
	void setVar(int sstart, int send)
	{
		start = sstart;		//下限
		end = send;			//上限
	}

	//合計計算メソッド
	void calcSum()
	{
		int taihi;			//退避用

		//小さい値を変数startに設定する
		if(start > end)
		{
			//endと対比を入れ替え
			taihi = end;
			end = start;
			start = taihi;
		}

		//合計を求める
		for(int i = start; i <= end; i++)
		{
			sum += i;
		}
	}

	//合計取得メソッド
	int getSum()
	{
		return sum;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Region  region;			//範囲オブジェクト宣言
	int start;				//下限数値入力用
	int end; 				//上限数値入力用

	cout << "整数値を２つ入力(例 1 5) >> ";
	cin >> start >> end;
	region.setVar(start, end);		//範囲数値設定メソッドの呼び出し

	region.calcSum();			//合計計算メソッドの呼び出し

	cout << "合計=" << region.getSum() << endl;

	_getch();
	return 0;
}
