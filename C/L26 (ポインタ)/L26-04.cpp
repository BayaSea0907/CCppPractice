/*
課題番号　：L26-4
内容　　　：int型変数のアドレスを受取って、受取ったアドレスから始まる領域の値を１０倍するmulti10
　　　　　　関数を作成して表示する。
　　　　　　main関数でint型変数は宣言と同時に初期化しておき、表示もmain関数で行う。
　　　　　　swap関数ではreturn文を使わない。
ファイル名：L26-04.cpp
作成日　　：2016/1/13
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

void swap(int* p1, int* p2);	//関数のプロトタイプ宣言

int main()
{
	int num1 = 100;
	int num2 = 200;

	swap(&num1, &num2);			//関数呼び出し

	cout << "num1=" << num1 << " num2=" << num2 << endl;

	_getch();
	return 0;
}

/*
関数名：swap
内容　：受取った２つアドレスから始まる領域に格納されているを入れ替える
引数　：int* p1　int型領域のアドレス
int* p2　int型領域のアドレス
戻り値：なし
*/
void swap(int* p1,	int* p2)
{
	int temp;

	temp = *p1;
	*p1  = *p2;
	*p2  = temp;
}

