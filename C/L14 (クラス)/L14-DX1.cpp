/*
課題番号　：L14-DeluxeSpecial1
内容　　　：ある作業をA君とB君の２人で作業することになり、最初A君のみで作業し、その後B君ひとりで作業する。
　　　　　　A君、B君それぞれ１人で完了できる日数と最初Ａ君ひとりで作業する日数を入力して、２人で作
　　　　　　業を完了できる総日数を表示する。
　　　　　　A君とB君をそれぞれオブジェクトにして、１人で完了できる日数を設定する。
　　　　　　そして、作業workオブジェクトに、A君とB君のオブジェクトと最初Ａ君ひとりで作業する日数を
　　　　　　設定して、２人で作業を完了できる総日数を表示する。
　　　　　　A君とB君それぞれ１人で完了できる日数と最初A君ひとりで作業する日数の入力、２人で作業を完
　　　　　　了できる総日数表示はuiオブジェクトで行う。
　　　　　　ただし、２人で作業した時、B君がひとりで作業する日数計算はworkオブジェクトのメソッドで
　　　　　　行い、いちどオブジェクトに格納するものとする。
ファイル名：L14-DX1.cpp
作成日　　：2015/07/21
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//人クラス定義
class Man {
	int day;					//ひとりで完了できる日数（日）
	int onlyDay;				//ひとりで作業する日数
public:
	//ひとりで完了できる日数設定メソッド
	void setDay(int sday)
	{
		day = sday;
	}

	//ひとりで完了できる日数取得メソッド
	int getDay()
	{
		return day;
	}

	//ひとりで作業する日数メソッド
	void setOnlyDay(int sonlyDay)
	{
		onlyDay = sonlyDay;
	}

	//ひとりで作業する日数取得メソッド
	int getOnlyDay()
	{
		return onlyDay;
	}

};
//////////////////////////////////////////////////
//作業クラス定義
class Work {
	//オブジェクト宣言
	Man manA, manB;
	//プロパティ。
	int ABDay;
public:
	//A君、B君オブジェクト設定メソッド
	void setVar(Man smanA, Man smanB)
	{
		//UIクラスで使ったmanオブジェクトを代入
		manA = smanA;
		manB = smanB;
	}
    
    //Ａ君とＢ君二人でできる時間計算メソッド
	void calcTime()
	{
		//時間計算。
		ABDay = manA.getOnlyDay() + (int)(((1.0 - ((1.0 / (double)manA.getDay()) * (double)manA.getOnlyDay())) / (1.0 / (double)manB.getDay())) + 0.99999f);
		//ABDay = manA.getOnlyDay() + (int)((1.0 - ((double)manA.getOnlyDay() / (double)manA.getDay())) * (double)manB.getDay() + 0.99999f);
	}
    
    //ＡＢ共同作業日数取得メソッド
	int getABDay()
	{
		return ABDay;
	}
};
//////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	//オブジェクト宣言
	Man manA, manB;
	Work work;
public:
	//処理制御メソッド
	void processCtrl()
	{
		inputMan();						//入力メソッド呼び出し
		work.setVar(manA, manB);		//A君、B君オブジェクト設定メソッド呼び出し
		work.calcTime();				//A君とB君ふたりで作業する時間計算
		show();							//表示メソッド呼び出し
	}

	//man入力設定メソッド
	void inputMan()
	{
		//自動変数
		int A, B;					//一人で完了できる日数
		int onlyDay;				//A君が最初一人で作業する日数

		cout << "A君ひとりで完了できる日数の入力(30日の場合 30) >> ";
		cin >> A;
		cout << "B君ひとりで完了できる日数の入力(20日の場合 20) >> ";
		cin >> B;
		cout << "最初のA君ひとりで作業する日数の入力(6日の場合 6) >> ";
		cin >> onlyDay;

		//manオブジェクトの一人で作業できる日数設定メソッドを呼び出す。
		manA.setDay(A);
		manB.setDay(B);
		//manオブジェクトのA君が最初ひとりで作業する日数設定メソッドを呼び出す。
		manA.setOnlyDay(onlyDay);
	}

	//表示メソッド
	void show()
	{
		cout << "仕事が始まってから終わるまでの日数=" << work.getABDay() << "日" << endl;
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	UI ui;			    //ユーザインタフェースオブジェクト宣言

	ui.processCtrl();	//インタフェース処理制御

	_getch();
	return 0;
}
