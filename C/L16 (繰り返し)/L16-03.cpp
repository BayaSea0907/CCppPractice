/*
課題番号　：L16-3
内容　　　：ヒーローheroオブジェクトのメソッドで、while文を使ってヒーロー名”X-men”を７行表示する。
ファイル名：L16-03.cpp
作成日　　：2015/10/01
作成者　　：BayaSea
*/

//プログラムを書き換えて何行表示されたかを確認すること：
//□ループカウンタが7になるまでの条件を、7と等しい（　ループカウンタ　==　7　）としたらどうなるで
//　しょうか？
//A.何も表示されない。cntが7の間繰り返すとなっているから


#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	string name = "Xmen";		//ヒーロー名("X-men")
public:
	//名前表示メソッド
	void showName(){
		int cnt;        //cnt：ループカウンタ

		cnt = 0;        //事前処理（ループの開始値設定）

		//名前の表示を７回繰返す
		while(cnt < 7){
			cout << name << endl;
			
			cnt++;		//後処理（ループカウントアップ）
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;		//ヒーローオブジェクト宣言

	hero.showName();	//名前表示メソッド呼び出し

	_getch();
	return 0;
}


