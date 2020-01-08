/*
課題番号　：L12-9
内容　　　：文字列を２つ入力して、その文字列どうしを加算（＋）した文字列を表示する。
ファイル名：L12-09.cpp
作成日　　：2015/05/13
作成者　　：BayaSea
*/

//実行時に確認すること：
//□文字列どうしを加算するとどうなるでしょうか？
//str1に代入した文字列とstr2に代入した文字列がつながって、一つの文字列として表示されました。

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	string str1;		//string型文字列
	string str2;		//string型文字列
	string str3;		//string型文字列

	cout << "文字列を２つ入力（例　game CU）>> ";
	cin >> str1 >> str2;

	//文字列の計算
	str3 =   str1 + str2           ;

	cout << "加算した文字列=" << str3 << endl;

	_getch();
	return 0;
}
