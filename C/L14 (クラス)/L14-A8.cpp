/*
課題番号　：L14-8
内容　　　：L14-3を書き換えて、main関数で行っていた一連の処理をＵＩ（User Interface）用オブジェクトで行う。
　　　　　　uiオブジェクトでは、入力設定メソッドと表示メソッドを用意して、heroオブジェクトに対する
　　　　　　一連の処理制御をprocessCtrlメソッドで行う。
　　　　　　入力設定メソッドでは、入力したＨＰをheroオブジェクトに設定する。
　　　　　　表示メソッドでは、heroオブジェクトから取得したＨＰを表示する。
ファイル名：L14-A8.cpp
作成日　　：2015/06/10
作成者　　：BayaSea
*/

//メモ：UIで入力した値をHeroに渡して、Heroが教えてくれた値をUIで表示する。

#include <conio.h>
#include <iostream>
using namespace std;

//HEROクラス定義
class Hero {
	int hp;		//HP

public:
	//HP設定メソッド　shp：HP受取り用
	void setHp(int shp){
		hp = shp;			//受取ったHPをインスタンス変数hpに代入
	}

	//HP取得メソッド
	int getHp(){
		return hp;			//インスタンス変数hpの値を戻す
	}
};

////////////////////////////////////////////////////////////

//ユーザインタフェースクラス定義
class UI {
	Hero hero;				//heroオブジェクト

public:

    //処理制御メソッド
    void processCtrl(){
        inp();				//入力設定
        show();				//表示
    }

    //入力設定メソッド
    void inp(){
		int hp; 			//HP入力用

		cout << "HPを整数値で入力（例　100）>> ";
		cin >> hp;

		//HP設定メソッドの呼び出し
		hero.setHp(hp);
    }

    //表示メソッド
    void show(){
        cout << "HP=" << hero.getHp() << endl;
    }
};

////////////////////////////////////////////////////////////

int main()
{
	UI ui;					//ユーザインタフェースオブジェクト宣言

    ui. processCtrl();		//インタフェース処理制御

	_getch();
	return 0;
}
