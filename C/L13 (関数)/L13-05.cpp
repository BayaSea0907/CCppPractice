/*
課題番号　：L13-5
内容　　　：main関数とhyouzi関数それぞれで宣言した同じ名前（num）の変数に格納した値を表示して、
　　　　　　関数が異なれば、同じ名前の変数であってもまったく別物であることを確認する。
　　　　　　確認するために、hyouzi関数の変数を表示した後、main関数の変数を表示する。
ファイル名：L13-05.cpp
作成日　　：2015/05/27
作成者　　：BayaSea
*/

//実行して確認すること：
//□実行結果から、関数で宣言した変数（自動変数という）は、宣言した関数の中でのみ使える（有効である）
//　ことを確認しなさい。
//A.確認しました。

#include <conio.h>
#include <iostream>
using namespace std;

void hyouzi();			//関数のプロトタイプ宣言

int main()
{
	int num;		//main関数で宣言した変数（自動変数）

	num = 100;
	cout << "main関数のnum=" << num << endl;

	hyouzi();		//関数の呼び出し

	cout << "main関数のnum=" << num << endl;

	_getch();
	return 0;
}

/*
関数名：hyouzi
内容　：関数内で宣言した変数の値を表示する
引数　：なし
戻り値：なし
*/
void hyouzi()
{
	int num; 		//hyouzi関数で宣言した変数（自動変数）

	num = 200;
	cout << "hyouzi関数のnum=" << num << endl;
}
