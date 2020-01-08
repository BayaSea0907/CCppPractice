/*
課題番号　：L23-2
内容　　　：L23-1を書き換えて、heroオブジェクトに入力したヒーロー名とアイテム構造体（アイテム名
　　　　　　と能力）を格納して、ヒーロー名とアイテム構造体のメンバを表示する。
　　　　　　入力はオブジェクトで行い、表示はmain関数で行う。
ファイル名：L23-02.cpp
作成日　　：2015/11/19
作成者　　：BayaSea
*/

#include <string>		//文字列操作用
#include <conio.h>
#include <iostream>
using namespace std;

//アイテム構造体の定義
struct Item {
	string name;	//アイテム名
	int power;		//能力
};

//ヒーロークラス定義
class Hero {
	string name;	//ヒーロー名
	Item item;		//アイテム構造体変数
public:
	//ヒーロー名、アイテム入力
	void inpProperty(){
		cout << "ヒーロー名を入力>> ";
		cin >> name;

		cout << "アイテム名と能力を入力(例 sword 10) >> ";
		cin >> item.name >> item.power;
	}

	//ヒーロー名取得
	string getName(){
		return name;
	}

	//アイテム取得
	Item getItem(){
		return item;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	string name;		//ヒーロー名取得用
	Item item;			//アイテム構造体取得用

	hero.inpProperty();			//ヒーロー名、アイテム入力メソッド呼び出し
	name = hero.getName();		//ヒーロー名取得メソッド呼び出し
	item = hero.getItem();		//アイテム取得メソッド呼び出し

	cout <<	name << " " <<	item.name << " " <<	item.power << endl;

	_getch();
	return 0;
}


