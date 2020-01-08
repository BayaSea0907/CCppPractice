/*
課題番号　：L16-14
内容　　　：入力した整数値をすべて掛け合わせた値を表示する。
　　　　　　入力はuiオブジェクトで行い、計算calcオブジェクトに入力値を渡して掛け合わせる。
　　　　　　ただし、入力はwhile文を使って0が入力されるまで行い、0でない場合のみuiオブジェクトから
　　　　　　calcオブジェクトへ入力値を渡すものとする。
　　　　　　そして、0が入力されたとき、それまでに掛け合わせた値を表示する。
ファイル名：L16-A14.cpp
作成日　　：2015/10/01
作成者　　：BayaSea
*/

//確認すること：
//□L16-2と異なり、入力をuiオブジェクト、掛け算をcalcオブジェクトで行っているので、calcオブジェ
//　クトが、計算機能だけに特化していることを確認しなさい。

#include <conio.h>
#include <iostream>
using namespace std;

//計算クラス定義
class Calc {
	int mul = 1;        //乗算結果用(1)
public:
	//乗算メソッド（int num：入力値）
	void multiply(int num)
	{
		mul *= num; //掛け算
	}

	//乗算結果取得メソッド
	int getMul()
	{
		return mul;
	}
};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Calc calc;		//計算オブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl()
	{
		inpNum();      //入力
		show();		//表示
	}

	//入力メソッド
	void inpNum()
	{
		int num;            //入力用
		int sw = 1;        //繰返制御用（１：繰返す）

		//入力値を加算する
		while(sw != 0)
		{
			cout << "整数値を入力（終了：0）>> ";
			cin >> num;

			//入力値判別
			if(num == 0)
			{
				sw = 0; 		//繰返しをやめる
			}
			else
			{
				calc.multiply(num);	//乗算メソッド呼び出し
			}
		}
	}

	//表示メソッド
	void show()
	{
		cout << "乗算結果=" << calc.getMul() << endl;
	}
};
////////////////////////////////////////////////////////////////
int main()
{
	UI ui;				//ユーザインタフェースオブジェクト宣言

	ui.processCtrl();	//インタフェース処理制御

	_getch();
	return 0;
}

