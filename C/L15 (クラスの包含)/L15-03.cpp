/*
課題番号　：L15-3
内容　　　：年齢を判定する。
　　　　　　人manオブジェクトに年齢を設定した後、年齢が20歳以上かどうかを判定した結果を表示する。
　　　　　　判定は、年齢が20歳以上ならば”成人”と表示し、20歳未満ならば何も表示しない。
　　　　　　年齢入力はuiオブジェクトで行い、判定結果表示はmanオブジェクトで行う。
ファイル名：L15-03.cpp
作成日　　：2015/07/01
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//人クラス定義
class Man {
	int age;	//年齢
public:
    //年齢設定メソッド  sage：年齢受取り用
	void setAge(int sage){
		age = sage;
    }
    //年齢判定メソッド
	void judgeAge(){

		//20歳以上かどうかを判別
		if (age >= 20)
		{
			cout << "成人" << endl;
		}

	}
};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Man man;		//人オブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl(){
		inpMan();		//man入力設定
		man.judgeAge();	//年齢判定
	}
	//man入力設定メソッド
	void inpMan(){
		int old;		//年齢入力用

		cout << "年齢を入力>> ";
		cin >> old;
		man.setAge(old);	//年齢設定メソッド呼び出し
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
