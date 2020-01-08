/*
課題番号　：L15-Special1
内容　　　：テストtestオブジェクトに得点を設定した後、0～59を”不合格”、60～74を”可”、75～89を”良”、90～100を“優”と表示する。
　　　　　　得点を0～100に範囲限定して判定して、0未満あるいは100超の場合は"0以上100以下の値ではな
　　　　　　いので評価できません"と表示する。
　　　　　　得点入力はuiオブジェクトで行い、判定表示はtestオブジェクトで行う。
ファイル名：L15-S1.cpp
作成日　　：2015/07/22
作成者　　：BayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;
//テストクラス定義
class Test{
	int ten;
public:
    //点数設定メソッド
	void setTen(int sten)
	{
		ten = sten;
	}

    //得点判定メソッド
	void judgeTen()
	{
		if ((ten < 0) || (ten > 100))
		{
			cout << "0以上100点以下の値ではないので評価できません";
		}
		else if (ten < 60)
		{
			cout << "不合格";
		}
		else if (ten < 75)
		{
			cout << "可";
		}
		else if (ten < 90)
		{
			cout << "良";
		}
		else
		{
			cout << "優";
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
		inpTest();
		test.judgeTen();
	}
	//test入力設定メソッド
	void inpTest()
	{
		//自動変数。得点
		int ten;

		cout << "得点を入力(例 75) >> ";
		cin >> ten;

		//テストオブジェクトの点数設定メソッド
		test.setTen(ten);
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
