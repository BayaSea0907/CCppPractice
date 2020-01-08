/*
課題番号　：L14-special1
内容　　　：ビーカーbekerオブジェクトに水（g）と塩の量（ｇ）（重さ）を設定して、食塩水の濃度を表示する。
　　　　　　ただし、水と塩の量入力、濃度表示はuiオブジェクトで行う。
　　　　　　また、濃度計算はbekerオブジェクトで行い、いちどオブジェクトに格納するものとする。
ファイル名：L14-S1.cpp
作成日　　：2015/06/17
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ビーカークラス定義
class Beker {

	int water;
	int salt;
	double density;

public:
	//水・塩の量設定メソッド
	void setVar(int swater, int ssalt)
	{
		water = swater;
		salt = ssalt;
	}

    //濃度計算メソッド
	void calcDensity()
	{
		//濃度 = 塩 / 食塩水
		density = (double)(salt / (double)(water + salt)) * 100.0 ;
	}

    //濃度取得メソッド
	double getDensity()
	{
		return density;
	}

};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Beker beker;		//bekerオブジェクト

public:
    //処理制御メソッド
	void processCtrl()
	{
		inp();
		beker.calcDensity();
		show();
	}	

	//入力設定メソッド
	void inp()
	{
		int water, salt;
		cout << "水の量（ｇ）と塩の量（ｇ）を入力（例  100 20） >> " ;
		cin >> water >> salt;
		beker.setVar(water, salt);
	}
	
	//表示メソッド
	void show()
	{
		cout << "食塩水の濃度（％）　= " << beker.getDensity() << endl;
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
