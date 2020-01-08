/*
課題番号　：L14-special3
内容　　　：３階（高さ８m）を駆け上るものとして、自分の馬力を求める。
　　　　　　人manオブジェクトに体重（㎏）と駆け上るのに要した時間（秒）を設定した後、馬力（double型）を表示する。
　　　　　　ただし、体重と時間入力、馬力表示はuiオブジェクトで行う。
　　　　　　また、manオブジェクトで計算した馬力はオブジェクトに格納しないものとする。
ファイル名：L14-S3.cpp
作成日　　： 2015/06/17
作成者　　： BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//人クラス定義
class Man {

	//プロパティの宣言
	//体重、時間
	double wight;
	double time;

public:
    //体重・時間設定メソッド
	void setVar(double sweight, double stime)
	{
		wight = sweight;
		time = stime;
	}
    //馬力取得メソッド
	double getBariki()
	{
		double bariki;

		//馬力計算 (体重 * 重力 * 高さ) / 時間 / 仏馬力
		bariki = (wight * 9.8 * 8.0) / time / 736.0;

		return bariki;
	}

};
//////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Man man;     		//オブジェクト宣言

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
		//体重と時間を入力
		double weight, time;
		cout << "体重（kg）を入力（例　60.0）>>" ;
		cin >> weight;
		cout << "駆け上がるのに要した秒数の入力（例　6.0）>>" ;
		cin >> time;

		// manオブジェクトの馬力取得メソッドを振舞う
		man.setVar(weight, time);
	}
	//表示メソッド
	void show()
	{
		cout << "馬力(PS) = " << man.getBariki() << endl;
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
