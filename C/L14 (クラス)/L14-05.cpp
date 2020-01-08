/*
課題番号　：L14-5
内容　　　：台形daikeiオブジェクトに上辺、底辺、高さ（double型）を設定した後、面積を計算する。
　　　　　　ただし、上辺、底辺、高さの入力、面積表示はmain関数で行う。
　　　　　　また、面積計算はdaikeiオブジェクトのメソッドで行い、いちどオブジェクトに格納するものとする。
ファイル名：L14-05.cpp
作成日　　：2015/06/10
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//台形クラス定義
class Daikei {

	double jouhen;		//上辺
	double teihen;		//底辺
	double takasa;		//高さ
	double area;		//面積

public:

	//上辺・底辺・高さ設定用メソッド
	void setVar(double sjouhen, double steihen, double stakasa)
	{
		jouhen = sjouhen;
		teihen = steihen;
		takasa = stakasa;
	}

	//面積計算メソッド
	void calcArea()
	{
		area = (jouhen + teihen) * takasa / 2;
    }

	//面積取得メソッド
	double getArea()
	{ 
		return area;
	}
};


////////////////////////////////////////////////////////////////


int main()
{

	Daikei daikei;		//台形オブジェクト宣言
	double jouhen;		//上辺入力用
	double teihen;		//底辺入力用
	double takasa;		//高さ入力用

	cout << "上辺　底辺　高さを入力（例　3.5 11.5 10.0）>> ";
	cin >> jouhen >> teihen >> takasa;

	//上辺・底辺・高さ設定
	daikei.setVar(jouhen, teihen, takasa);

	daikei.calcArea();	//面積計算

	//面積表示
	cout << "面積=" << daikei.getArea() << endl;

	_getch();
	return 0;
}
