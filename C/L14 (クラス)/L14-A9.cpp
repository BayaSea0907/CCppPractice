/*
課題番号　：L14-9
内容　　　：L14-7を書き換えて、main関数で行っていた一連の処理をＵＩ（User Interface）用オブジェクトで行う。
　　　　　　uiオブジェクトでは、入力設定メソッドと表示メソッドを用意して、goodsオブジェクトに対す
　　　　　　る定価計算も含めた一連の処理制御をprocessCtrlメソッドで行う。
　　　　　　入力設定メソッドでは、入力した販売価格と値引率を商品goodsオブジェクトに設定する。
　　　　　　表示メソッドでは、goodsオブジェクトから取得した定価を表示する。
ファイル名：L14-A9.cpp
作成日　　：2015/06/10
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//商品クラス定義
class Goods {
	int teika;		//定価（円）
	int price;		//販売価格（円）
	double rate;	//値引き率

public:

//販売価格・値引率設定メソッド
    void setVar(int sprice, double srate){
	    price =sprice;
	    rate = srate;
    }

	//定価計算メソッド
	void calcTeika(){
		teika = (int)((double)price / (1.0 - rate));
	}

	//定価取得メソッド
	int getTeika(){
		return teika;
	}
};

////////////////////////////////////////////////////////////

//ユーザインタフェースクラス定義
class UI {
	Goods goods;				//goodsオブジェクト宣言

public:

    //処理制御メソッド
    void processCtrl(){

		inp();					//入力設
		goods.calcTeika();		//定価計算           
        show();		  	        //表示
    }

    //入力設定メソッド
	void inp(){
		int price;				//販売価格入力用
		double rate;			//値引率入力用

		cout << "販売価格の入力（例　2080）>> ";
		cin >> price;

		cout << "値引率（20％の場合　0.2）>> ";
		cin >> rate;

		//購入価格・値引率設定
		goods.setVar(price, rate);
	}

    //表示メソッド
    void show(){
		cout << "定価=" << goods.getTeika() << endl;
    }
};

////////////////////////////////////////////////////////////

int main()
{
	UI ui;			    //ユーザインタフェースオブジェクト宣言

	ui.processCtrl();	//インタフェース処理制御

	_getch();
	return 0;
}
