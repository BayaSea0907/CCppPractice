/*
課題番号　：L14-Special5
内容　　　：ボートboatオブジェクトに静水上の船の速度（km/時）、川の流速（km/時）、川上Ａ点と
　　　　　　川下Ｂ点間の距離（km）を設定して、船がＡ点Ｂ点を往復する時間を表示する。
　　　　　　ただし、１分未満は、1/100分までを切り上げる。
　　　　　　静水上の船の速度、川の流速、川上Ａ点と川下Ｂ点間の距離入力、往復時間表示はuiオブジェクトで行う。
　　　　　　また、往路時間、復路時間、往復時間（時間と分）計算はboatオブジェクトのそれぞれのメソッ
　　　　　　ドで行い、いちどオブジェクトに格納するものとする。
ファイル名：L14-S5.cpp
作成日　　：2015/07/21
作成者　　：BayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//ボートクラス定義
class Boat {
	//プロパティ宣言
	int ship;				//船の速度
	int river;				//川の速度
	int distance;			//A点からB店までの距離
	int downHour;			//往路の時間
	int downMinute;			//往路の分
	int upHour;				//復路の時間
	int upMinute;			//復路の分
	int hour;				//往復の時間
	int minute;				//往復の分

public:
    //速度、流速、距離設定メソッド
	void setVar(int sship, int sriver, int sdistance)
	{
		//プロパティを初期化
		ship = sship;
		river = sriver;
		distance = sdistance;
	}
    
    //川上Ａ点から川下Ｂ点までの往路時間計算メソッド
	void calcOuroTime()
	{
		//時間と分を別々に計算。1/100分まで切り上げ
		downHour = distance / (ship + river);
		downMinute = (int)(((double)(distance % (ship + river)) / ( (double)(ship + river) / 60.0)) + 0.99);
	}
    
    //川下Ｂ点から川上Ａ点までの復路時間計算メソッド
	void calcFukuroTime()
	{
		//時間と分を別々計算。1/100まで切り上げ
		upHour = distance / (ship - river);
		upMinute = (int)(((double)(distance % (ship - river)) / ((double)(ship - river) / 60.0)) + 0.99);
	}
    
    //往復時間計算メソッド
	void calcRoundTrip()
	{
		//往路と復路の時間の合計。分が60を超えていたら時間を増やす。
		hour = (downHour + upHour) + ((downMinute + upMinute) / 60);

		//往路と復路の分の合計。60分を超えていたら、60引いた余りを分とする。
		minute = (downMinute + upMinute) % 60;
	}
    
    //時間取得メソッド
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
	Boat boat;			//ボートオブジェクト宣言
public:
    //処理制御メソッド
	void processCtrl()
	{
		inp();						//入力設定メソッド
		boat.calcOuroTime();		//往路の時間を計算
		boat.calcFukuroTime();		//復路の時間を計算
		boat.calcRoundTrip();		//往復の時間を計算
		show();						//表示メソッド
	}
	//入力設定メソッド
	void inp()
	{
		//自動変数
		int ship;			//船の速度
		int river;			//川の速度
		int distance;		//A点からB点までの距離

		cout << "静水上の船の速度の入力(14km/時の場合  14) >> " ;
		cin >> ship;
		cout << "川の流速の入力(2km/時の場合  2) >> " ;
		cin >> river;
		cout << "川上A点と川下B点間の距離の入力(36kmの場合  36) >> ";
		cin >> distance;
		//船の速度、川の流速、距離を設定
		boat.setVar(ship, river, distance);
	}
	
	//表示メソッド
	void show()
	{
		//boatオブジェクトに記憶されている時間と分を別々に表示。
		cout << " "<< boat.getHour() << "時間 " << boat.getMinute() << "分" << endl;
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
