/*
課題番号　：L11-10
内容　　　：２つの文字列（９文字以内）を入力して、それらの文字列を表示する。
　　　　　　１つのcinで両方の文字列を入力する。文字列はstring型で扱う。
ファイル名：L11-A10.cpp
作成日　　：2015/04/30
作成者　　：BayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	//文字列を格納する領域の宣言
	string str1;
	string str2;

	cout << "２つの文字列を入力（例　game jec）" << endl << ">> ";

	//２つの文字列を１度に入力
	cin >> str1 >> str2;

	//格納されている文字列の表示
	cout << "文字列は" << str1 << "と" << str2 << "です";

	_getch();
	return 0;
}
