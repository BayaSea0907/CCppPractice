/*
課題番号　：L13-7
内容　　　：string型の文字列を受け取って文字列"CU"を付け加えた文字列を戻す関数を、main関数から呼び出す。
　　　　　　関数が受け取る文字列はmain関数で入力して、関数から戻る文字列をmain関数で表示する。
ファイル名：L13-07.cpp
作成日　　：2015/05/27
作成者　　：BayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

string addStr(string str); 	//関数のプロトタイプ宣言

int main()
{
	string str;		//string型文字列
	string ret;		//関数から戻ってきたstring型文字列

	cout << "文字列を入力（例　game）>> ";
	cin >> str;

	ret = addStr(str);		//関数の呼び出し（文字列を渡して戻った文字列を格納する）


	cout << "文字列=" << ret << endl;

	_getch();
	return 0;
}

/*
関数名：addStr
内容　：引数で受け取った文字列に文字列を付け加える
引数　：string str　文字列
戻り値：string　文字列
*/
string addStr(string str)
{
	string strWa; 		//addStr関数で宣言した変数（自動変数）

	strWa = "CU" + str;


	return strWa;

	//次の１文だけでもよい（文字列を付け加えた文字列を戻す）
    //return str + "CU";
}
