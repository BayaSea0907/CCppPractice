/*
課題番号　：L14-2
内容　　　：L14-1を書き換えて、ヒーローheroオブジェクトのhpに入力した後、HPを表示する。
　　　　　　HeroクラスのHP入力用メソッドでhpに100を入力する。
　　　　　　ただし、入力したHPは、いちどインスタンス変数に格納（オブジェクトに格納）するものとする。
ファイル名：L14-02.cpp
作成日　　：2015/06/10
作成者　　：BayaSea
*/

//実行時に確認すること：
//□heroオブジェクトのメソッドでHPを入力していることを確認しなさい。
//A.確認しました。入力メソッドの中のcin >> hpを消したら入力できなくなる。

#include <conio.h>
#include <iostream>
using namespace std;

//HEROクラス定義
class Hero {

	int hp;		//HP

public:

	//HP入力メソッド
	void inputHp(){
		cout << "HPを整数値で入力（例　100）>> ";
		cin >> hp;									//インスタンス変数hpに入力
	}
	//HP表示メソッド
	void showHp(){
		cout << "HP=" << hp << endl; 				//インスタンス変数hpを表示
	}
};

////////////////////////////////////////////////////////////

int main()
{
	Hero hero;										//オブジェクト宣言
	
	hero.inputHp();									//HP入力メソッドの呼び出し
	hero.showHp();									//HP表示メソッドの呼び出し

	_getch();
	return 0;
}
