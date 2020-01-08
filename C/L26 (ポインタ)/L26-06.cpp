/*
課題番号　：L26-6
内容　　　：L26-5を書き換えて、show関数にint型配列のみを渡して全要素を表示する。
　　　　　　main関数で配列は宣言と同時に初期化しておき、表示もmain関数で行う。
ファイル名：L26-06.cpp
作成日　　：2016/1/14
作成者　　：BayaSea
*/

//プログラムを書き換えて確認すること：
//□#define　MAX　5　をconst指定子を使った書き方に書き換えて、同じ結果を表示できることを確認し
//　ましょう。
//　　　const　int MAX = 5;
//A.確認しました。

#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 5;		//配列要素数の定義

//#define MAX 5			//配列要素数の定義

void show(int ary[]);		//関数のプロトタイプ宣言

//////////////////////////////////////////////////////////////////
int main()
{
	int ary[MAX] = { 30, 20, 50, 10, 40 };

	show(ary);		//関数呼び出し

	_getch();
	return 0;
}

/*
関数名：show
内容　：受取った整数値配列（要素数５）の全要素を表示する
引数　：int ary[]　int型配列の先頭アドレス
戻り値：なし
*/
void show(int ary[])
{
	for (int i = 0;	i < MAX; i++){
		cout << " [" << i << "]=" << ary[i];
	}
	cout << endl;
}

