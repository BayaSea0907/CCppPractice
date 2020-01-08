/*
課題番号　：L24-Special2
内容　　　：入力した英大文字を英小文字に変換して英小文字を表示し、英大文字でない場合は"英大文字では
　　　　　　ない"と表示する。
　　　　　　半角１文字を格納する変数の型は、char型にする。
　　　　　　英大文字を英小文字に変換するには、計算式を使う。
　　　　　　main関数のみで行う。
ファイル名：L24-S2.cpp
作成日　　：15CU0210小林裕樹
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	char c;

	cout << "大文字にし変換したい小文字を入力(例: A ) >> ";
	cin >> c;


	//大文字だったら小文字に変換する
	if ('A' <= c && c <= 'Z') {
		cout << c << '=' << (char)(c + ' ') << endl;
	}
	else {
		cout << "英大文字ではない" << endl;
	}

	_getch();
	return 0;
}



