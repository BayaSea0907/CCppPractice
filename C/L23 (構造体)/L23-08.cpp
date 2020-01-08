/*
課題番号　：L23-8
内容　　　：heroオブジェクトにヒーロー名とアイテム構造体配列（要素数２）を格納して、ヒーロー名とア
　　　　　　イテム構造体のメンバを表示する。
　　　　　　アイテム構造体のメンバは、アイテム名と能力。
　　　　　　ヒーロー名とアイテム構造体は、main関数で宣言と同時に初期化する。
　　　　　　表示はオブジェクトで行う。
ファイル名：L23-08.cpp
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
	//ヒーロー名設定　str：ヒーロー名
	void setName(string str){
		name = str;
	}
	//アイテム設定　itm[]：アイテム構造体配列
	void setItem(Item itm[]){

		for (int i = 0; i < 2; i++){
			item[i] = itm[i];
		}
	}
	//ヒーロー名、アイテム表示
	void show(){
		cout << name << endl;

		for (int i = 0; i < 2; i++){
			cout << item[i].name << " " << item[i].power << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	string name = "BERG"; 	//ヒーロー名格納用変数の宣言と同時の初期化

	//アイテム構造体配列の宣言と同時の初期化
	Item item[2] = { { "mant", 50 }, { "sword", 200 } };

	hero.setName(name);		//ヒーロー名設定メソッド呼び出し
	hero.setItem(item);		//アイテム設定メソッド呼び出し
	hero.show();			//ヒーロー名、アイテム表示メソッド呼び出し
	_getch();
	return 0;
}
