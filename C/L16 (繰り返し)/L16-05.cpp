/*
課題番号　：L16-5
内容　　　：ヒーローheroオブジェクトのメソッドで、5回HPに100加算した後、HPを表示する。
　　　　　　ただし、for文を使うものとする。
　　　　　　ただし、heroオブジェクトのhpは、クラス定義で0で初期化しておくものとする。
ファイル名：L16-05.cpp
作成日　　：2015/10/01
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	int hp = 0;			//HP（0）
public:
	//HP加算メソッド
	void addHp(){
		//hpの加算を５回繰返す
		//cnt：ループカウンタ
		for(int cnt = 0; cnt < 5; cnt++){
			cout << "HPを加算" << endl;

			hp += 100;		//100加算
		}
	}

	//HP取得メソッド
	int getHp(){ return hp; }
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;		//ヒーローオブジェクト宣言

	hero.addHp();		//HP加算メソッドの呼び出し

	cout << endl << "HP=" << hero.getHp() << endl;

	_getch();
	return 0;
}


