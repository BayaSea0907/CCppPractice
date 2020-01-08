/*
課題番号　：L13-2
内容　　　：受け取った整数値を１０倍して表示する関数を、main関数から呼び出す。
　　　　　　ただし、関数が受け取る整数値はmain関数で入力するものとする。
ファイル名：L13-02.cpp
作成日　　：2015/05/27
作成者　　：BayaSea
*/

//確認すること：
//□関数が受け取る値の個数と型はなんですか？
//A.int型を1個

//□関数の呼び出しは、どのように書いてありますか？
//A.関数hyouziを呼び出して、引数にnumを渡している。

//□関数はmain関数に値を戻しますか？
//戻りません。

//プログラムを書き換えて確認すること：
//□関数の呼び出しをhyouzi();　と書き換える（プロトタイプ宣言も書き換える）と、関数を呼び出せるで
//　しょうか？
//A.呼び出せない。戻り値の型がない。戻り値がない場合はvoidを書かないといけない。

#include <conio.h>
#include <iostream>
using namespace std;

void hyouzi(int hnum);	//関数のプロトタイプ宣言

int main()
{
	int num; 		//入力用

	cout << "整数値を入力>> ";
	cin >> num;

	//関数の呼び出し（numの値を渡す）

	hyouzi(num);


	_getch();
	return 0;
}

/*
関数名：hyouzi
内容　：受け取った整数値を１０倍して表示する
引数　：int hnum　受取った整数値を格納する変数
戻り値：なし
*/
void hyouzi(int hnum)
{
	hnum *= 10; 		//hnum = hnum * 10　と同じ

	cout << "１０倍した値=" << hnum << endl;
}
