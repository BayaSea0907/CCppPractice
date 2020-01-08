/*
課題番号　：L15-12
内容　　　：ランプlampオブジェクトに色１文字を渡した後、その色１文字に対応する色を判定した結果を
　　　　　　switch文を使って表示する。
　　　　　　判定は、文字が‘R’なら“Red”、‘G’なら“Green”、‘B’なら“Blue”、‘$’や‘#’なら“補正色”、
　　　　　　それら以外の文字の場合には“その他の色”と表示する。
　　　　　　switch文で１文字を格納した変数を多分岐するには、１文字を格納する変数の型はchar型にする。
　　　　　　色１文字入力はuiオブジェクトで行い、判定表示はlampオブジェクトで行う。
ファイル名：L15-A12.cpp
作成日　　：2015/07/08
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ランプクラス定義
class Lamp {
public:
    //温度判定メソッド
	void Judg(char scoller)
	{
		//自動変数
		char coller = scoller;

		//色の判別
		switch (coller)
		{
		case 'R':	cout << "Red";
			break;
		case 'G': cout << "Green";
			break;
		case 'B': cout << "Blue";
			break;
		case '$':
		case '#': cout << "補正色";
			break;
		default: cout << "その他の色";
			break;
		}
	}


};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Lamp lamp;	//ランプオブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl(){
		inpLampJudg();		//lamp入力・判定
	}
	//lamp入力設定メソッド
	void inpLampJudg()
	{
		char coller;

		cout << "色を入力(例: R) >> ";
		cin >> coller;
		//lampオブジェクトのJudgメソッド呼び出し
		lamp.Judg(coller);
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
