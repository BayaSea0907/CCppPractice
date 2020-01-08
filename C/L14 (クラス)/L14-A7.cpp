/*
課題番号　：L14-7
内容　　　：商品goodsオブジェクトに販売価格と値引き率を設定した後、定価を計算する。
　　　　　　ただし、販売価格と値引き率の入力、定価の表示はmain関数で行う。
　　　　　　また、定価計算はgoodsオブジェクトのメソッドで行い、いちどオブジェクトに格納するものとする。
　　　　　　また、1円未満は切り捨てる。
ファイル名：L14-A7.cpp
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
	double rate;		//値引き率

public:

    //販売価格・値引率設定メソッド
    void setVar(int sprice, double srate){

	    price = sprice;
	    rate = srate;
    }

	//定価計算メソッド
	void calcTeika(){
		
		teika = (int)((double)price * (1.0 - rate));
	}

	//定価取得メソッド
    int getTeika(){

		return teika;
		
	}
};


////////////////////////////////////////////////////////////


int main()
{

	Goods goods;						//オブジェクト宣言
	int price;					        //販売価格（円）
	double rate;						//値引き率

	cout << "販売価格の入力（例　2080）>> ";
	cin >> price;
	cout << "値引率（20％の場合　0.2）>> ";
	cin >> rate;

	goods.setVar(price, rate);			//購入価格・値引率設定
    goods.calcTeika();				    //定価計算

	cout << "定価=" << goods.getTeika() << endl;

	_getch();
	return 0;
}
