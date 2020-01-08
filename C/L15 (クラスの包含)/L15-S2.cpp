/*
課題番号　：L15-Special2
内容　　　：整数値の割り算結果を判定する。
　　　　　　割り算Divisionオブジェクトに整数値を２つ設定して、大きい方の数を小さい方の数で割った結果を実数値で表示する。
　　　　　　ただし、同じ数の場合でも、割った結果を実数値で表示するものとする。
　　　　　　また、除数（割る数）、つまり小さい数が０の場合には、"０で割れません"と表示する。
　　　　　　整数値入力はuiオブジェクトで行い、判定表示はDivisionオブジェクトで行う。
ファイル名：L15-S2.cpp
作成日　　：2015/08/23
作成者　　：BayaSea
*/
//□実行時に入力する値について、次の５パターンを必ずチェックすること。
//>> 100 200
//>> 200 100
//>> 100 100
//>> 100 0
//>> 0 100

#include <conio.h>
#include <iostream>
using namespace std;

//割り算クラス定義
class Division {
	int dividend;
	int divisor;
public:
    //被除数・除数設定メソッド
	void setVar(int sdividend, int sdivisor)
	{
		//どちらの数値が大きいか比較し、大きい方をdividendに入れて、小さい方をdivisorに入れる
		if (sdividend > sdivisor)
		{
			dividend = sdividend;		//割られる数
			divisor = sdivisor;			//割る数
		}
		else
		{
			dividend = sdivisor;		//割る数
			divisor = sdividend;		//割られる数
		}
	}

    //割り算判定メソッド
	void judge()
	{
			//除数が0だったら計算しない。
			if (dividend != 0 || divisor != 0)
			{
				cout << "0で割れません" << endl;
			}
			//大きい数(dividend)を、小さい数(divisor)で割る。
			else
			{
				cout << dividend << "÷" << divisor << "=" << (double)dividend / (double)divisor << endl;
			}
	}
};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Division division;
public:
	//処理制御メソッド
	void processCtrl()
	{
		inpDiv();				//入力メソッド
		division.judge();		//割り算判定メソッド
	}

	//division入力設定メソッド
	void inpDiv()
	{
		//自動変数
		int divident;			//被除数(割られる数)
		int divisior;			//除数(割る数)

		cout << "整数値を２つ入力(例 100 200) >> ";
		cin >> divident >> divisior;

		//divisionオブジェクトの被除数、除数設定メソッド
		division.setVar(divident, divisior);
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	UI ui;			//ユーザインタフェースオブジェクト宣言

	ui.processCtrl();	//インタフェース処理制御

	_getch();
	return 0;
}
