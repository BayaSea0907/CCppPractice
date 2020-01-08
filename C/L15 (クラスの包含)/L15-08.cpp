/*
課題番号　：L15-8
内容　　　：テストの結果を判定する。
　　　　　　テストtestオブジェクトに得点を設定した後、論理演算子を使って0～59を”不合格”、60～74
　　　　　　を”可”、75～89を”良”、90以上を“優”と表示する。
　　　　　　得点入力はuiオブジェクトで行い、判定表示はtestオブジェクトで行う。
ファイル名：L15-08.cpp
作成日　　：2015/07/08
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test{
	int ten;	//得点
public:
//点数設定メソッド
	void setTen(int sten){
		ten = sten;
    }
    //得点判定メソッド
	void judgeTen(){

		//点数の判別
		if (0 <= ten && ten < 60)
		{
			cout << "不合格" << endl;
		}
		else if (60 <= ten && ten < 75)
		{
			cout << "可" << endl;
		}
		else if (75 <= ten && ten < 90)
		{
			cout << "良" << endl;
		}
		else if (90 <= ten)
		{
			cout << "優" << endl;
		}
		else
		{
			cout << "負の値のため評価できません" << endl;
		}

	}
};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Test test;	//テストオブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl(){
		inpTest();		//test入力設定
		test.judgeTen();	//得点判定
	}
	//test入力設定メソッド
	void inpTest(){
		int ten;	//得点入力用

		cout << "得点を入力（例　75）>> ";
		cin >> ten;
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
