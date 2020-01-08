/*
課題番号　：L16-7
内容　　　：ヒーローheroオブジェクトのメソッドで、5回HPに100加算する際に、加算の回数を表示する。
　　　　　　加算の繰返しには、while文を使うものとする。
　　　　　　ただし、ループカウンタは0から始める。
ファイル名：L16-07.cpp
作成日　　：2010/10/01
作成者　　：BayaSea
*/

//プログラムを書き換えて確認すること：
//□ループカウンタを１増やす計算を書かなければどうなるでしょうか？
//A.永遠と繰り返し

//□繰り返し条件を、while(ループカウンタ < 0)　と書き換えたらどうなるでしょうか？
//A. hp=0と表示される。繰り返し処理が行われないから

#include <conio.h>
#include <iostream>
using namespace std;
//ヒーロークラス定義
class Hero {
	int hp = 0;			//HP（0）
public:
	//HP加算メソッド
	void addHp(){
		int cnt;		//ループカウンタ

		//ループカウンタとHPの加算を５回繰返す
		cnt = 0;

		while(cnt < 5){
			cout << "HPを加算　" << cnt+1 << "回目" << endl;
			hp += 100;

			cnt++;		 //ループカウンタを１増やす

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

	cout << "HP=" << hero.getHp() << endl;

	_getch();
	return 0;
}


