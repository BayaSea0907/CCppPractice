/*
課題番号　：L23-1
内容　　　：heroオブジェクトにヒーロー名とアイテム構造体（アイテム名と能力）を格納して、ヒーロー名
　　　　　　とアイテム構造体のメンバを表示する。
　　　　　　格納と表示はオブジェクトで行う。
　　　　　　L23-1からL23-6までは、このアイテム構造体を使う。
ファイル名：L23-01.cpp
作成日　　：2015/11/19
作成者　　：BayaSea
*/

//プログラムを書き換えて確認すること：
//□構造体変数の定義　Item item;　を、struct Item item;　のように書き換えても、宣言できること
//　を確認しましょう。
//A. しました。

#include <string>		//文字列操作用
#include <conio.h>
#include <iostream>
using namespace std;

//アイテム構造体の定義
struct Item {
	string name;		//アイテム名
	int power;			//能力
};

//ヒーロークラス定義
class Hero {
	string name;		//ヒーロー名
	Item item;			//アイテム構造体変数
//	struct Item item;	//アイテム構造体変数
public:
	//ヒーロー名、アイテム設定
	void setProperty(){
		name = "BERG";			//ヒーロー名
		item.name = "mant";		//アイテム名設定
		item.power = 50;		//アイテム能力設定
	}

	//ヒーロー名、アイテム表示
	void show(){
		cout << name << " " << item.name << " " <<	item.power << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.setProperty();	//ヒーロー名、アイテム設定メソッド呼び出し
	hero.show();		//ヒーロー名、アイテム表示メソッド呼び出し

	_getch();
	return 0;
}

