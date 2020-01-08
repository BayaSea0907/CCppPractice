/*
課題番号　：L15-5
内容　　　：テストtestオブジェクトに得点を設定した後、オブジェクトの得点が基準合格以上かどうがの
　　　　　　判定結果を表示する。
　　　　　　判定は、受取った基準合格点以上ならば”合格”、それ以外の値ならば“不合格”と表示する。
　　　　　　得点と基準合格点入力はuiオブジェクトで行い、判定表示はtestオブジェクトで行う。
ファイル名：L15-05.cpp
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
    //得点判定メソッド  border：基準合格点受取り用
    void judgeTen(int sborder){
		int border = sborder;

		//点数がborder以上かどうかを判別
		if (ten >= border){ cout << "合格" << endl; }
		
		//ボーダー以下の場合不合格
		else{ cout << "不合格" << endl; }
	}
};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Test test;		//テストオブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl(){
		inpScore();		//得点入力設定
		inpBdrJudg();	//基準点入力・判定
	}
	//得点入力設定メソッド
	void inpScore(){
		int score;		//得点入力用

		cout << "得点を入力（例　100）>> ";
		cin >> score;
		test.setTen(score);		//得点設定
	}
	//基準点入力・判定メソッド
	void inpBdrJudg(){
		int border;		//基準合格点入力用

		cout << "基準合格点を入力（例　60）>> ";
		cin >> border;

		//得点判定メソッド呼び出し
		test.judgeTen(border);

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
