/*
課題番号　：L14-special2
内容　　　：飛行機planeオブジェクトに目的地までの距離（km）と平均時速（km/h）を設定して、所要時間（時分）を表示する。
　　　　　　ただし、距離と時速入力、所要時間表示はuiオブジェクトで行う。
　　　　　　所要時間はplaneオブジェクトで計算し、所要時間（時と分）は、いちどオブジェクトに格納するものとする。
　　　　　　所要時間の分未満は切り捨てる。
ファイル名：L14-S2.cpp
作成日　　：2015/06/17
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//飛行機クラス定義
class Plane {

	//プロパティの宣言
	int speed;
	int distance;
	int hour;
	int minute;

public:
    //時速・距離設定メソッド　sspeed：時速　 sdistance：距離
	void setVar(int sspeed, int sdistancde)
	{
		speed = sspeed;
		distance = sdistancde;
	}

    //所要時間計算メソッド
	void calcTime()
	{
		//時間計算
		hour = distance / speed;

		//分計算
		minute = (int)((double)(distance % speed) / ((double)speed / 60.0));
	}

	//時取得メソッド
	int getHour()
	{
		return hour;
	}

	//分取得メソッド
	int getMinute()
	{
		return minute;
	}

};
//////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {

	//飛行機オブジェクト宣言
	Plane plane;

public:
    //処理制御メソッド
	void processCtrl()
	{
		inp();
		plane.calcTime();
		show();
	}
	
	//入力設定メソッド
	void inp()
	{
		int speed;
		int distance;

		cout << "平均時速（ｋｍ/ｈ）と距離（ｋｍ）を入力（例　740 10850) >> ";
		cin >> speed >> distance;
		plane.setVar(speed, distance);
	}
	
	//表示メソッド
	void show()
	{
		cout << "推定所要時間=" << plane.getHour() << "時間" << plane.getMinute() << "分";
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
