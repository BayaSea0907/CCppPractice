/*
課題番号　：L14-ExcellentSpecial2
内容　　　：トンネルと鉄橋を通過するときは速度（16m/秒）、それ以外のところでは速度（18m/秒）で走る
　　　　　　規則になっている列車が、トンネルを抜けてしばらく走り、次に鉄橋を渡ります。
　　　　　　列車の長さ（m）とトンネルにかかってから鉄橋を通過し終えるまでの時間（分）を入力して、ト
　　　　　　ンネルの出口から鉄橋の入口までの距離（トンネル鉄橋間の距離）を表示する。
　　　　　　列車をオブジェクトにして、車両長さとトンネルと鉄橋を通過するときは速度、それ以外のとこ
　　　　　　ろでの速度を設定する。
　　　　　　トンネルと鉄橋を通過するときの速度とそれ以外のところでの速度は、クラス定義で初期化しておく。
　　　　　　そして、通過計測passTimeオブジェクトに、列車オブジェクトを設定して、トンネル鉄橋間の距離を表示する。
　　　　　　トンネルと鉄橋の長さはそれぞれ1000ｍとして、クラス定義で初期化しておく。
　　　　　　トンネル鉄橋間の距離は（1/10）ｍを四捨五入する。
　　　　　　列車の長さ、トンネルにかかってから鉄橋を通過し終えるまでの時間入力、トンネル鉄橋間の距
　　　　　　離表示はuiオブジェクトで行う。
　　　　　　ただし、トンネル鉄橋間の距離計算はpassTimeオブジェクトメソッドで行い、トンネル鉄橋間
　　　　　　の距離はオブジェクトに格納しないでuiオブジェクトに戻すものとする。
ファイル名：L14-XC2.cpp
作成日　　：2015/07/22
作成者　　：BayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//列車クラス定義
class Train {
	int tbSpeed;				//トンネル鉄橋速度(16m/秒)
	int speed;					//通常速度(18m/秒)
	int len;					//長さ(m)
public:
	//コンストラクタ　tbSpeedを16、speedを18で初期化
	Train():tbSpeed(16), speed(18){}

	//トンネル鉄橋速度取得メソッド
	int getTbSpeed()
	{
		return tbSpeed;
	}

	//通常速度取得メソッド
	int getSpeed()
	{
		return speed;
	}

	//長さ設定メソッド
	void setLen(int slen)
	{
		len = slen;
	}

	//長さ取得メソッド
	int getLen()
	{
		return len;
	}

};
//////////////////////////////////////////////////////
//通過計測クラス定義
class PassTime {
	Train train;				//列車オブジェクト
	int len;					//列車の長さ(m)
	int time;					//トンネル渡り始めから鉄橋渡り終えまでの時間(分)
	int distance;				//トンネル鉄橋間の、長さ(m)
	int tunnel;					//トンネル長さ(1000m)
	int bridge;					//鉄橋長さ(1000m)
public:
	//コンストラクタ tunnelを1000、bridgeを1000で初期化
	PassTime() :tunnel(1000), bridge(1000)
	{

	}
	//列車長さ・時間設定メソッド
	void setVar(int strain, int stime)
	{
		len = strain;
		time = stime;
	}
    
    //トンネル鉄橋間長さ取得メソッド
	int getDistance()
	{
		return distance;
	}

};
//////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Train train;
	PassTime pTime;
public:
	//処理制御メソッド
	void processCtrl()
	{
		inputTrain();				//列車の長さ設定メソッド
		inputPassTime();			//トンネル鉄橋間渡り終えるまでの時間メソッド
		pTime.PassTime();			//トンネル鉄橋間の距離計算メソッド
		show();						//表示メソッド
	}

	//train入力設定メソッド
	void inputTrain()
	{
		//自動変数。列車の長さ
		int len;

		cout << "列車の長さの入力(長さ200mの場合 200) >> ";
		cin >> len;

		//trainオブジェクトの長さ設定メソッド
		train.setLen(len);
	}

	//passTime入力設定メソッド
	void inputPassTime()
	{
		//自動変数。渡り終えるまでの時間
		int time;

		cout << "トンネル渡り初めから鉄橋渡り終えるまでの時間の入力(6分の場合 6) >> ";
		cin >> time;

		//pTimeオブジェクトの列車の長さ、時間設定メソッド呼び出し
		pTime.setVar(train.getLen(), time);
	}
		
	//表示メソッド
	void show()
	{
		cout << pTime.getDistance() << "m" << endl;
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
