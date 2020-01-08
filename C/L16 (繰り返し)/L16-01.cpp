/*
課題番号　：L16-1
内容　　　：ヒーローheroオブジェクトのメソッドで、ヒーロー自身にエールを送る（表示する）。
　　　　　　ヒーローの名前は自分の名前とし、エールは、while文を使ってヒーローのHPが0以下になるまで表示する。
　　　　　　1回エールするごとにHPは10減るものとする。
ファイル名：L16-01.cpp
作成日　　：2015/10/01
作成者　　：BayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	string name = "小林";     //ヒーロー名("自分の名前")
	int hp = 100;                  //HP(100)
public:
	//エールメソッド
	void yell(){
		//エール繰返し
		while(hp > 0){
			cout << name << "ファイト！！" << endl;

			hp -= 10;//HPを減らす

		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;		//ヒーローオブジェクト宣言

	hero.yell();	//エールメソッド呼び出し

	_getch();
	return 0;
}



