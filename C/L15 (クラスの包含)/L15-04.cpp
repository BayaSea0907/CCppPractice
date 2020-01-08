/*
課題番号　：L15-4
内容　　　：テストの得点を判定する。
　　　　　　テストtestオブジェクトに得点を設定した後、得点が70点以上かどうかの判定結果を表示する。
　　　　　　判定は、70以上の値を入力すると”合格”、それ以外の値ならば“不合格”と表示する。
　　　　　　ただし、得点入力はuiオブジェクトで行い、判定表示はtestオブジェクトで行う。
ファイル名：L15-04.cpp
作成日　　：2015/07/01
作成者　　：BayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;
//テストクラス定義
class Test {
	int ten;	//得点
public:
    //得点設定メソッド
	void setTen(int sten){
	    ten = sten;
    }
    //得点判定メソッド
	void judgeTen(){

		//点数が70以上かどうかを判別
		if (ten >= 70){ cout << "合格" << endl; }

		//それ以外の数値の場合不合格を表示
		else{ cout << "不合格" << endl; }

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

		cout << "得点を入力（例　100）>> ";
		cin >> ten;
		test.setTen(ten);	//設定メソッド呼び出し
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
