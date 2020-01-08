/*
課題番号　：L13-4
内容　　　：受け取った整数値を１０倍して戻す関数を、main関数から呼び出す。
　　　　　　関数が受け取る整数値はmain関数で入力して、関数から戻った値もmain関数で表示する。
ファイル名：L13-04.cpp
作成日　　：2015/05/27
作成者　　：BayaSea
*/

//確認すること：
//□関数が受け取る値の個数と型はなんですか？
//A.1個、int型

//□関数が戻す値の型と戻り値の型はなんですか？
//A.int型

//□関数を呼び出している１文は、どのように書いてありますか？
//A.ret = calcRet(num);

#include <conio.h>
#include <iostream>
using namespace std;

int calcRet(int knum);	//関数のプロトタイプ宣言

int main()
{
	int num; 	//入力用
	int ret; 	//関数から戻ってきた値格納用

	cout << "整数値を入力>> ";
	cin >> num;

	//関数の呼び出し（値を渡して、戻った値を格納する）
	ret = calcRet(num);

	cout << "戻った値=" << ret << endl;

	_getch();
	return 0;
}

/*
関数名：calcRet
内容　：受け取った整数値を１０倍して戻す
引数　：int knum　整数値
戻り値：int knum　１０倍した整数値
*/
int calcRet(int knum)
{
	knum *= 10; 		//knum = knum * 10　と同じ

	return knum;	//numの値を戻す
}
