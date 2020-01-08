/*
課題番号　：L14-3
内容　　　：main関数で入力したHPをheroオブジェクトに渡した後、heroオブジェクトが教えてくれた
　　　　　　（メソッドから戻された）HPをmain関数で表示する。
　　　　　　HP設定とHP取得は、heroオブジェクトのそれぞれのメソッドで行う。
　　　　　　ただし、heroオブジェクトに渡したHPは、いちどインスタンス変数（オブジェクトに格納）に格納するものとする。
ファイル名：L14-03.cpp
作成日　　：2015/06/10
作成者　　：BayaSea
*/

//実行時に確認すること：
//□heroオブジェクトに、main関数からHPを渡していることを確認しなさい。
//A.確認しました。引数が無いとインスタンス変数のhpには何も格納できない。

//□heroオブジェクトが、受取ったHPをインスタンス変数に格納していることを確認しなさい。
//A.確認しました。setHpメソッドの =shpを消すと入力した数値と違うものが表示される。

//□heroオブジェクトから戻されたHPを、main関数で表示していることを確認しなさい。
//A.確認しました。getHpメソッドのreturn hpを０にすると、インスタンス変数に格納した数値と違うものが表示される。

#include <conio.h>
#include <iostream>
using namespace std;

//HEROクラス定義

class Hero {

	int hp;		//HP

public:

	//HP設定メソッド　shp：HP受取り用
	void setHp(int shp){
		hp = shp ; 							//受取ったHPをインスタンス変数hpに代入
	}

	//HP取得メソッド
	int getHp(){
	return 0;								//インスタンス変数hpの値を戻す
	}
};


////////////////////////////////////////////////////////////


int main()
{
	Hero hero;									//ヒーローオブジェクト宣言
	int hp; 									//HP入力用

	cout << "HPを整数値で入力（例　100）>> ";
	cin >> hp;
	hero.setHp(hp);								//HP設定メソッドの呼び出し

	//HP取得メソッドから戻ってきたHPを表示
	cout << "HP=" << hero.getHp() << endl;

	_getch();
	return 0;
}
