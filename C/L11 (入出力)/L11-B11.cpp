/*
課題番号　：L11-11
内容　　　：入力した整数値、実数値、文字列を表示する。
　　　　　　１つのcinですべての値を入力する。文字列はstring型で扱う。
ファイル名：L11-B11.cpp
作成日　　：2015/04/30
作成者　　：BayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	//変数の宣言
	int num;		//整数値格納用
	double zisu;       //実数値格納用
	string str;		//文字列格納用

	cout << "整数値、実数値、文字列を入力（例　10 20.5 game）" << endl << ">> ";

	//整数値、実数値、文字列の入力
	cin >> num >> zisu >> str;


	//格納している整数値、実数値、文字列の表示
	cout << "整数値=" << num << " 実数値=" << zisu << " 文字列=" << str << endl;


	_getch();
	return 0;
}
