/*
課題番号　：L23-9
内容　　　：heroオブジェクトのヒーロー名とアイテム構造体（アイテム名と能力）を初期化して、ヒーロー
　　　　　　名とアイテム構造体のメンバを表示する。
　　　　　　ヒーロー名はクラス定義で、アイテム構造体は構造体定義で初期化する。
　　　　　　表示はオブジェクトで行う。
ファイル名：L23-09.cpp
作成日　　：2015/11/19
作成者　　：BayaSea
*/

//プログラムを書換えて確認すること：
//□アイテム構造体の初期化を、構造体定義で行わず、クラス定義のアイテム構造体宣言時で行うとどうなる
//　でしょうか？
//A.実行できない。プロパティの構造体変数は、宣言と同時に初期化が出来ない

#include <string>		//文字列操作用
#include <conio.h>
#include <iostream>
using namespace std;

//アイテム構造体の定義
struct Item {
	string name = "mant";	//アイテム名
	int power = 50;			//能力
};

//ヒーロークラス定義
class Hero {
	string name = "BERG";	//ヒーロー名
	Item item;				//アイテム構造体
public:
	//ヒーロー名、アイテム表示
	void show(){
		cout << name << endl << item.name << " " << item.power << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.show();		//ヒーロー名、アイテム表示メソッド呼び出し

	_getch();
	return 0;
}

