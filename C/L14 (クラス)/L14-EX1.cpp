/*
課題番号　：L14-ExtraSpecial1
内容　　　：池の１周距離（ｍ）、A君B君の歩く速度（ｍ／分）を入力して、池を反対方向に歩くA君とB君が
　　　　　　再び出会うのは何分後かを表示する。
　　　　　　A君とB君をそれぞれのオブジェクトにして、歩く速度を設定する。
　　　　　　そして、再び出会う時間を計測するランデブーrendezvousオブジェクトに、A君とB君のオブジ
　　　　　　ェクトと池の周距離を設定して出会う時間（分）を表示する。
　　　　　　A君とB君の速度と池の周距離入力、再び出会う時間表示はuiオブジェクトで行う。
　　　　　　ただし、rendezvousオブジェクトで計算した出会う時間は、rendezvousオブジェクトに格納
　　　　　　しないものとし、再び出会う時間（分）の１分未満は切り捨てる。
ファイル名：L14-EX1.cpp
作成日　　：2015/07/21
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//人クラス定義
class Man {
	int speed;			//プロパティ宣言
public:
	//速度設定メソッド　sspeed：速度
	void setSpeed(int sspeed)
	{
		speed = sspeed;
	}

	//速度取得メソッド
	int getSpeed()
	{
		return speed;
	}

};
////////////////////////////////////////////
//ランデブークラス定義
class Rendezvous {
	//オブジェクト宣言
	Man manA, manB;				//オブジェクト宣言
	int distance;				//プロパティ宣言
public:
	//池１周距離・A君とB君オブジェクト設定メソッド
	void setVar(int sdistance, Man smanA, Man smanB)
	{
		//A君B君オブジェクトに、UIクラスで使ったA君B君オブジェクトを代入。
		manA = smanA;
		manB = smanB;

		//池の１週の距離
		distance = sdistance;
	}
    
    //再び出会う時間取得メソッド
	int getTime()
	{
		//自動変数
		int Time;

		//A君とB君が出会う時間を計算。doubleで計算して、最後にint型に直して1分未満を切り捨てる。
		Time = (int)((double)distance / (double)(manA.getSpeed() + manB.getSpeed()));

		return Time;
	}

};
//////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Rendezvous rende;			//ランデブークラスをオブジェクト宣言
	Man manA, manB;				//ManクラスをAとBに分けてオブジェクト宣言
public:
    //処理制御メソッド
	void processCtrl()
	{
		inputMan();				//man入力メソッド
		input();				//入力メソッド
		show();					//表示メソッド
	}
public:
	//man入力設定メソッド
	void inputMan()
	{
		//自動変数
		int A, B;

		//A君とB君の歩く速度を入力
		cout << "AくんとB君の速度を入力(36m/分 40m/分の場合  36 40) >> ";
		cin >> A >> B;

		//Manクラスの速度設定メソッドを呼び出す。
		manA.setSpeed(A);
		manB.setSpeed(B);
	}

	//入力設定メソッド
	void input()
	{
		//自動変数
		int distance;

		//池の１週の距離を入力
		cout << "池の１週の距離を入力(1368mの場合 1368) >> ";
		cin >> distance;

		//ﾗﾝﾃﾞﾌﾞｰｸﾗｽの池の距離、A君B君の速度設定メソッドを呼び出す。
		rende.setVar(distance, manA, manB);
	}
	//表示メソッド
	void show()
	{
		cout << "出会うのは" << rende.getTime() << "分後" << endl;
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
