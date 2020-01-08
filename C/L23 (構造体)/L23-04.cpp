/*
課題番号　：L23-4
内容　　　：L23-3を書き換えて、heroオブジェクトに入力したヒーロー名とアイテム構造体配列（要素数
　　　　　　２）を格納して、ヒーロー名とアイテム構造体のメンバを表示する。
　　　　　　アイテム構造体のメンバは、アイテム名と能力。
　　　　　　ヒーロー名とアイテム構造体配列への入力は、異なるメソッドで行う。
　　　　　　アイテム構造体配列への入力には、繰返し制御を使う。
　　　　　　入力と表示はオブジェクトで行う。
ファイル名：L23-04.cpp
作成日　　：2015/11/19
作成者　　：BayaSea
*/

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
	Item item[2];		//アイテム構造体配列
public:
	//ヒーロー名入力
	void inpName(){
		cout << "ヒーロー名を入力>> ";
		cin >> name;
	}
	//アイテム入力
	void inpItem(){
		for (int i = 0; i < 2; i++){
			cout << "アイテム名と能力を入力(例 sword 10) >> ";
			cin >> item[i].name >> item[i].power;
		}
		cout << endl;
	}
	//ヒーロー名、アイテム表示
	void show(){
		cout << name << endl;

		for (int i = 0; i < 2; i++){
			cout << item[i].name << " " <<	item[i].power << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.inpName();	//ヒーロー名入力メソッド呼び出し
	hero.inpItem();	//アイテム入力メソッド呼び出し
	hero.show();	//ヒーロー名、アイテム表示メソッド呼び出し

	_getch();
	return 0;
}
