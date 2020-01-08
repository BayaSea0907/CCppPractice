/*
課題番号　：L15-Special3
内容　　　：テストtestオブジェクトに得点を設定した後、0～59を”不合格”、60～74を”可”、75～89を”良”、
　　　　　　90以上を“優”と表示する。
　　　　　　論理演算子を使わずに判定して、0未満の場合は"負の値のため評価できません"と表示する。
　　　　　　得点入力はuiオブジェクトで行い、判定表示はtestオブジェクトで行うものとする。
　　　　　　大きい値から判別する
ファイル名：L15-S3.cpp
作成日　　：2015/08/23
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test{
	int ten;					//プロパティ
public:
    //点数設定メソッド
	void setTen(int sten)
	{
		sten = ten;				//プロパティに引数stenを代入
	}

    //得点判定メソッド
	void judgeTen()
	{
		//90点以上なら優
		if (ten >= 90)
		{
			cout << "優" << endl;
		}
		//89~75点の間だったら良
		else if (ten >= 75)
		{
			cout << "良" << endl;
		}
		//74~60点の間だったら可
		else if (ten >= 60)
		{
			cout << "可" << endl;
		}
		//59~0点の間だったら不合格
		else if (ten >= 0)
		{
			cout << "不合格" << endl;
		}
		//0点未満の値は評価しない
		else
		{
			cout << "負の値のため評価できません" << endl;
		}
	}
};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Test test;

public:
	//処理制御メソッド
	void processCtrl()
	{
		inpTest();				//入力設定メソッド呼び出し
		test.judgeTen();		//特典判定メソッド呼び出し
	}

	//test入力設定メソッド
	void inpTest()
	{
		int ten;				//自動変数

		//点数の入力
		cout << "得点を入力(例 75) >> ";
		cin >> ten;

		test.setTen(ten);		//点数設定メソッド呼び出し
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
