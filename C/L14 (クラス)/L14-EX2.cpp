/*
課題番号　：L14-ExtraSpecial2
内容　　　：Ａ管、Ｂ管それぞれのみを使ってタンクを満杯にできる時間を入力して、両管を同時に使って満
　　　　　　杯にできる時間を表示する。
　　　　　　Ａ管とＢ管をそれぞれオブジェクトにして、その管のみで満杯にできる時間を設定する。
　　　　　　そして、tankオブジェクトに、Ａ管とＢ管のオブジェクトを設定して、両管を同時に使って満杯
　　　　　　にできる時間を表示する。
　　　　　　Ａ管とＢ管それぞれで満杯にできる時間の入力、両管を同時に使って満杯にできる時間（時間と
　　　　　　分）表示はuiオブジェクトで行う。
　　　　　　ただし、両管を同時に使って満杯にできる時間計算はtankオブジェクトのメソッドで行い、いち
　　　　　　どオブジェクトに格納するものとする。
ファイル名：L14-EX2.cpp
作成日　　：2015/07/21
作成者　　：BayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

//管クラス定義
class Tube {
	int Hour;
public:
	//満杯にできる時間設定メソッド
	void setHour(int shour)
	{
		Hour = shour;
	}

	//満杯時間取得メソッド
	int getHour()
	{
		return Hour;
	}

};
////////////////////////////////////////////////
//タンククラス定義
class Tank {
	Tube tubeA, tubeB;			//A管、B管オブジェクト
	int hour;					//時間
	int minute;					//分
public:
	//Ａ管、Ｂ管オブジェクト設定メソッド
	void setTube(Tube stubeA, Tube stubeB)
	{
		//UIクラスで使ったtubeオブジェクトを代入。
		tubeA = stubeA;
		tubeB = stubeB;
	}
    
    //Ａ管とＢ管両方使って満杯にできる時間計算メソッド
	void calcTime()
	{
		//自動変数。Aのみ、Bのみで満杯にできる時間を代入。
		int A = tubeA.getHour();
		int B = tubeB.getHour();

		//A管B管両方使って満杯になる時間を計算。
		hour = (int)(1.0 / ((1.0 / (double)A) + (1.0 / (double)B)));
		//A管B管両方を使って満杯になる分を計算。四捨五入してます。
		minute = (int)((((1.0 / ((1.0 / (double)A) + (1.0 / (double)B))) - (double)hour) * 60.0) + 0.5);
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
	Tube tubeA, tubeB;				//Tubeクラスのオブジェクト宣言
	Tank tank;						//Tankクラスノオブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl()
	{
		inputTube();						//入力メソッド
		tank.setTube(tubeA, tubeB);			//tankオブジェクトのA管B管のオブジェクト設定メソッドを呼び出す。
		tank.calcTime();					//tankオブジェクトの時間計算メソッドを呼び出す。
		show();								//表示メソッド
	}

	//tube入力設定メソッド
	void inputTube()
	{
		//自動変数
		int A, B;

		cout << "A管のみで満杯にできる時間の入力(6時間の場合 6) >> ";
		cin >> A;
		cout << "B管のみで満杯にできる時間の入力(9時間の場合 9) >> ";
		cin >> B;

		//Tubeオブジェクトの時間設定メソッドを呼び出す。
		tubeA.setHour(A);
		tubeB.setHour(B);
	}

	//表示メソッド
	void show()
	{
		cout << "A、B管を使うと" << tank.getHour() << "時間 " << tank.getMinute() << "分" << endl;
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	UI ui;			//ユーザインタフェースオブジェクト宣言

	ui. processCtrl();	//インタフェース処理制御

	_getch();
	return 0;
}
