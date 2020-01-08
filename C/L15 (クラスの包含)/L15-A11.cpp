/*
課題番号　：L15-11
内容　　　：箱boxオブジェクトに整数値を渡すと偶奇数の判定結果を表示する。
　　　　　　判定は、switch文を使って偶奇数を判定して、0と偶数ならば”偶数”、それ以外の値ならば“奇数”と表示する。
　　　　　　整数値入力はuiオブジェクトで行い、判定表示はboxオブジェクトで行う。
ファイル名：L15-A11.cpp
作成日　　：2015/07/08
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//箱クラス定義
class Box {
public:
    //偶奇数判定メソッド
	void Judg(int shantei)
	{
		int hantei = shantei % 2;
		switch (hantei)
		{
			case 0:	cout << "偶数" << endl;
				break;
			case 1: cout << "奇数" << endl;
				break;
			default: break;
		}
	}

};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Box box;		//箱オブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl(){
		inpManJudg();		//man入力・判定
	}
	//man入力設定メソッド
	void inpManJudg()
	{
		int hantei;
		cout << "偶数か奇数か判定します。数値を入力 >> " ;
		cin >> hantei;
		box.Judg(hantei);
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
