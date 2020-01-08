/*
課題番号　：L14-Special4
内容　　　：１辺１０cmの正方形画用紙を張り合わせた面積を求める。
　　　　　　２枚の画用紙を張り合わせたときののり代は１cmとする。
　　　　　　矩形rectオブジェクトに、縦方向と横方向にそれぞれ張り合わせる枚数とのり代を設定した後、
　　　　　　張り合わせたときにできる画用紙の面積を表示する。
　　　　　　縦・横にそれぞれ張り合わせる枚数、のり代入力、面積表示はuiオブジェクトで行う。
　　　　　　rectオブジェクトで計算されて求まる、張り合わせてできる矩形の縦・横長さ、面積は、オブジ
　　　　　　ェクトに格納しないものとする。
ファイル名：L14-S4.cpp
作成日　　：2015/06/24
作成者　　：BayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//矩形クラス定義
class Rectangle {

	//プロパティの宣言
	int tmai;
	int ymai;
	int nori;
public:
    //縦横枚数・のり代設定メソッド
	void setVar(int stmai, int symai, int snori)
	{
		tmai = stmai;
		ymai = symai;
		nori = snori;
	}

    //矩形の縦横長さ計算メソッド
	int getArea()
	{
		return ((tmai * 10) - nori * (tmai - 1)) * ((ymai * 10) - nori * (ymai - 1));

	}
};
//////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Rectangle rect;          	//矩形オブジェクト宣言
public:
    //処理制御メソッド
	void processCtrl()
	{
		inp();
		show();
	}
	
	
	//入力設定メソッド
	void inp()
	{
		//自動変数：縦枚数、横枚数、のりしろ
		int tmai, ymai, nori;

		cout << "縦と横枚数の入力1（縦5枚、横8枚の場合 例： 5  8) >>" ;
		cin >> tmai >> ymai;

		cout << "のり代(縦横共通)の入力(1cmの場合  例： 1) >>";
		cin >> nori;

		rect.setVar(tmai, ymai, nori);

	}
	//表示メソッド
	void show()
	{
		cout << "のり代を除いた面積 = " << rect.getArea() << "cm2" << endl;
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
