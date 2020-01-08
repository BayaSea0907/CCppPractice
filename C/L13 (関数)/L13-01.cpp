/*
課題番号　：L13-1
内容　　　：入力した整数値を１０倍して表示する関数を、main関数から呼び出す。
ファイル名：L13-01.cpp
作成日　　：2015/05/20
作成者　　：BayaSea
*/

//確認すること：
//□()内の引数並びを書いていません。このことは何を表していますか？
//A.引数なし

//□戻り値の型のvoidは何を表していますか？
//戻り値なし

//□関数の呼び出しは、どのように書いてありますか？
//引数はないのでそのまま関数を呼び出している。

#include <conio.h>
#include <iostream>
using namespace std;

void inputHyouzi();		//関数のプロトタイプ宣言

int main()
{
	//関数の呼び出し
	inputHyouzi();

	_getch();
	return 0;
}

/*
関数名：inputHyouzi
内容　：入力した整数値を１０倍して表示する
引数　：なし
戻り値：なし
*/
void inputHyouzi()
{
	int num; 		//入力用

	printf("整数値を入力>> ");
	cin >> num;

	num *= 10; 		//num = num * 10　と同じ

	cout << "１０倍した値=" << num << endl;
}
