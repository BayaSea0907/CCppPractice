/*
課題番号　：L14-ExcellentSpecial1
内容　　　：電車（特急と快速）がお互いに反対方向に走っています。
　　　　　　特急と快速電車の速度（km/時）と車両長さを入力して、出会ってからすれ違うまでにかかる時間（秒）を表示する。
　　　　　　特急と快速をそれぞれオブジェクトにして、速度と車両長さを設定します。
　　　　　　そして、すれ違いcrossオブジェクトに、特急と快速のオブジェクトを設定して、出会ってから
　　　　　　すれ違うまでにかかる時間を表示する。
　　　　　　ただし、１秒未満は（1/10）秒までを切り上げる。
　　　　　　特急と快速電車の速度と車両長さの入力、すれ違うまでの時間表示はuiオブジェクトで行う。
　　　　　　ただし、すれ違い時間計算はcrossオブジェクトのメソッドで行い、いちどオブジェクトに格納するものする。
ファイル名：L14-XC1.cpp
作成日　　：2015/07/22
作成者　　：BayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//電車クラス定義
class Train {
	int speed;					//速度(km/時)
	int len;					//長さ(m)
public:
	//速度設定メソッド
	void setSpeed(int sspeed)
	{
		speed = sspeed;
	}

	//速度取得メソッド
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
////////////////////////////////////////////////////
//すれ違いクラス定義
class Cross {
	Train exp;					//特急オブジェクト
	Train rap;					//快速オブジェクト
	int second;					//すれ違う時間(秒)
public:
	//特急と快速オブジェクト設定メソッド
	void setVar(Train sexp, Train srap)
	{
		//UIクラスで使ったTrainオブジェクトを代入
		exp = sexp;
		rap = srap;
	}
    
    //すれ違う時間計算メソッド
	void calcTime()
	{
		//km/時を、m/秒に直す計算
		double ESpeed = (double)exp.getSpeed() / 3600.0 * 1000.0;
		double RSpeed = (double)rap.getSpeed() / 3600.0 * 1000.0;
		
		//すれ違う時間を計算
		second = (int)((double)(exp.getLen() + rap.getLen()) / (ESpeed + RSpeed) + 0.9);
	}
    
    //すれ違い時間取得メソッド
	int getSecond()
	{
		return second;
	}

};
//////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Train exp, rap;				//特急、快速オブジェクト
	Cross cross;				//すれ違いオブジェクト
public:
	//処理制御メソッド
	void processCtrl()
	{
		inputTrain();				//入力メソッド
		cross.setVar(exp, rap);		//オブジェクト設定メソッド
		cross.calcTime();			//時間計算メソッド
		show();						//表示メソッド
	}

	//train入力設定メソッド
	void inputTrain()
	{
		//自動変数
		int speedExp, speedRap;					//速度
		int lenExp, lenRap;						//車両の長さ

		cout << "特急の速度と長さの入力(速度90km/時、長さ250mの場合 90 250) >> ";
		cin >> speedExp >> lenExp;
		cout << "快速の速度と長さの入力(速度72km/時、長さ200mの場合 72 200) >> ";
		cin >> speedRap >> lenRap;

		//Trainオブジェクトの速度設定メソッド呼び出し
		exp.setSpeed(speedExp);
		rap.setSpeed(speedRap);

		//Trainオブジェクトの長さ設定メソッド呼び出し
		exp.setLen(lenExp);
		rap.setLen(lenRap);

	}

	//表示メソッド
	void show()
	{
		cout << cross.getSecond() << "秒" << endl;
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
