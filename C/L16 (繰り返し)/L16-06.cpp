/*
課題番号　：L16-6
内容　　　：ヒーローheroオブジェクトのメソッドで、5回HPに100加算する際に、加算の回数を表示する。
　　　　　　加算の繰返しには、for文を使うものとする。
　　　　　　ただし、ループカウンタは0から始める。
ファイル名：L16-06.cpp
作成日　　：2015/10/01
作成者　　：BayaSea
*/

//プログラムを書き換えて確認すること：
//□ループカウンタが4になるまで（4未満）、繰り返すとどうなるでしょうか？
//A.４回分処理される

//□ループカウンタが4になったときも（4以下）、繰り返すとどうなるでしょうか？
//A.５回分処理される

#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	int hp = 0;    		//HP（0）
public:
	//HP加算メソッド
	void addHp(){
		//ループカウンタとHPの加算を５回繰返す
		//cnt：ループカウンタ
		for(int cnt = 0; cnt < 5; cnt++){
			cout << "HPを加算　" << cnt+1 << "回目" << endl;
			hp += 100;
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



