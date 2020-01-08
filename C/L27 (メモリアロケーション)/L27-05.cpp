/*
課題番号　：L27-5
内容　　　：アロケーションした商品構造体領域のメンバに入力して、商品構造体のメンバを表示する。
　　　　　　main関数のみで行う。
ファイル名：L27-05.cpp
作成日　　：2016/1/20
作成者　　：BayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//商品構造体の定義
struct Goods {
	string name;		//品名
	int cost;		//値段（円）
};

int main()
{
	Goods* p;		//アロケーション構造体領域へのポインタ宣言

	//メモリのアロケーション
	p = new Goods;

	//アロケーションできなかった場合
	if (p == NULL)
	{
		cout << "アロケーション失敗" << endl;
	}
	//アロケーションできた場合
	else
	{
		//アロケーション領域に入力
		cout << "品名を入力（例　melon）>> ";
		cin >> p->name;

		cout << "値段を入力（例　850）>> ";
		cin >> p->cost;

		//アロケーション領域の表示
		cout <<	p->name << " " << p->cost << endl;

		//アロケーション領域の解放（必ず行うこと）
		delete p;

	}

	_getch();
	return 0;
}

