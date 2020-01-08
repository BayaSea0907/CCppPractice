/*
課題番号　：L26-8
内容　　　：アイテム構造体変数のアドレスを受取ってメンバに入力するinpItem関数を作成して、アイテム
　　　　　　構造体のメンバを表示する。
　　　　　　表示はmain関数で行う。
ファイル名：L26-08.cpp
作成日　　：2016/1/14
作成者　　：BayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//アイテム構造体定義
struct Item {
	string name;	//アイテム名
	int power;		//能力
};

void inpItem(Item* p);		//関数のプロトタイプ宣言

/////////////////////////////////////////////////////////////
int main()
{
	Item item;

	inpItem(&item);		//関数呼び出し

	cout << "アイテム名= " << item.name << endl;
	cout << "能力= " <<	item.power << endl;

	_getch();
	return 0;
}
/*
関数名：inpItem
内容　：アイテム構造体のメンバ入力
引数　：Item* p　アイテム構造体変数のアドレス
戻り値：なし
*/
void inpItem(Item* p)
{
	cout << "アイテム名と能力を入力>> ";
	cin >> p->name >> p->power;
}




