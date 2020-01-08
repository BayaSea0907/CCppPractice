/*
課題番号　：L11-6
内容　　　：string型領域に文字列（連続した文字の並び）"gameCU"を代入して、その文字列を表示する。
ファイル名：L11-06.cpp
作成日　　：2015/04/30
作成者　　：BayaSea
*/

//プログラムを書き換えて確認すること：
//□文字Gを代入（　str = "G"　）するとどうなるでしょうか？
//A.　Gの一文字だけが表示される

#include <string>		//string型文字列を使う場合必要
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	//文字列を格納するstring型領域の宣言
	string str;

	str = "gameCU";		//文字列を代入

	//文字を代入
	//str = "G";

	//領域に格納されている文字列の表示
	cout << "文字列= " << str << endl;

	_getch();
	return 0;
}
