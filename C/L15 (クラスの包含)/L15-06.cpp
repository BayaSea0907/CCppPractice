/*
課題番号　：L15-6
内容　　　：箱boxオブジェクトに渡した整数値の偶奇数の判定結果を表示する。
　　　　　　判定は、偶数ならば”偶数”、それ以外の値ならば“奇数”と表示する。
　　　　　　整数値入力はuiオブジェクトで行い、表示はboxオブジェクトで行う。
ファイル名：L15-06.cpp
作成日　　：2015/07/01
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//箱クラス定義
class Box {
public:
    //判定メソッド
    void judge(int num){

		//偶数、奇数の判別
		if (num % 2){ cout << "奇数" << endl; }

		else{ cout << "偶数" << endl; }
	}
};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Box box;		//箱オブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl(){
		inpBoxJudg();		//数値入力・判定
	}
	//数値入力・判定メソッド
	void inpBoxJudg(){
		int num;		//入力用

		cout << "整数値を入力（例　15）>> ";
		cin >> num;
		box.judge(num);	//判定
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
