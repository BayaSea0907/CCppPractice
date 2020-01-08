/*
課題番号　：L23-Special2
内 容　　　：ｈeroオブジェクトにヒーロー名を格納して、ヒーロー名と外部変数で宣言したアイテム構造
　　　　　　　体のメンバを表示する。
　　　　　　　ヒーロー名（自分の名前）は、クラス定義で初期化する。
　　　　　　　アイテム構造体は、外部変数として宣言して、宣言と同時に初期化する。
　　　　　　　表示は、オブジェクトで行う。
ファイル名：L23-S2.cpp
作成日　　：2015/11/21
作成者　　：BayaSea
*/

#include <string>		//文字列操作用
#include <conio.h>
#include <iostream>
using namespace std;

//アイテム構造体定義・宣言と同時の初期化
struct Item {
	string name;	//アイテム名
	int power;		//能力
} ITM = {			//グローバル構造体変数の宣言と初期化
	"mant",
	50
};
////////////////////////////////////////////////////////////////
//ヒーロークラス定義
class Hero {
	string name = "BERG";	//ヒーロー名
public:
	//表示
	void show(){
		cout << name << endl << ITM.name << " " << ITM.power << endl;
	}
};
////////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.show();	//表示メソッド呼び出し

	_getch();
	return 0;
}



