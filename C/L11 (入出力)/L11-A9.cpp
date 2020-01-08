/*
課題番号　：L11-9
内容　　　：整数値と実数値を入力して、それらの値を表示する。
　　　　　　１つのcinで両方の値を入力する。
ファイル名：L11-A9.cpp
作成日　　：2015/04/30
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int num;			    //整数値を格納する変数の宣言
	double zisu; 			//実数値を格納する変数の宣言

	cout << "整数値と実数値を入力（例　10 20.5）"<< endl << ">> " ;

	cin >> num >> zisu;		//整数値と実数値を１度に入力


	//変数に格納されている値の表示
	cout << "変数num=" << num << " 変数zisu=" << zisu ;


	_getch();
	return 0;
}
