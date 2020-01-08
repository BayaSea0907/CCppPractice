/*
課題番号　：L15-7
内容　　　：バスケットの中のみかんとりんごの個数を判定する。
　　　　　　バスケットbasketオブジェクトにみかんとりんごの個数を設定した後、個数の多さを判定した結果を表示する。
　　　　　　判定は、個数が多い方の果物名、同じならば“同じ”と表示する。
　　　　　　それぞれの果物の個数入力はuiオブジェクトで行い、判定表示はbasketオブジェクトで行う。
ファイル名：L15-07.cpp
作成日　　：2015/07/01
作成者　　：BayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//バスケットクラス定義
class Basket {
	int orange;	//みかん個数
	int apple;	//りんご個数
public:
    //みかん・りんご個数設定メソッド
	void setVar(int sorange, int sapple){
		orange = sorange;
		apple = sapple;
    }
    //個数大小判定メソッド
    void judgeVar(){

		//大小判定
		if (apple > orange){ cout << "りんごの方が多い" << endl; }
		else if (apple < orange){ cout << "みかんの方が多い" << endl; }
		else{ cout << "同じ" << endl; }
	}
};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Basket basket;		//バスケットオブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl(){
		inpBasket();		//basket入力設定
		basket.judgeVar();	//個数判定
	}
	//basket入力設定メソッド
	void inpBasket(){
		int orange;		//みかん個数入力用
		int apple;		//りんご個数入力用

		cout << "みかんとりんごの個数を入力（例　100 200）>> ";
		cin >> orange >> apple;
		basket.setVar(orange, apple);
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
