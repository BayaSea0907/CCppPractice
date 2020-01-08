/*
課題番号　：L11-5
内容　　　：実数値を入力して、その値を表示する。
ファイル名：L11-05.cpp
作成日　　：2015/04/30
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	double zisu; 		//実数値を格納する変数の宣言

	cout << "実数値を入力>> ";	//入力メッセージの表示
	cin >> zisu;	 	    	//実数値の入力

	//変数に格納されている値の表示
	cout << "変数zisuの値=" << zisu << endl;

	_getch();
	return 0;
}
