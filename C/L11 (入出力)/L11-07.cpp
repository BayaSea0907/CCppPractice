/*
課題番号　：L11-7
内容　　　：string型領域に文字列"gameCU"を入力して、その文字列を表示する。
ファイル名：L11-07.cpp
作成日　　：2015/04/30
作成者　　：BayaSea
*/

//プログラムを書き換えて確認すること：
//□文字Gを入力するとどうなるでしょうか？
//A. Gの一文字だけが表示される。

#include <string>		//string型文字列を使う場合必要
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	//文字列を格納するstring型領域の宣言
	string str;

	cout << "文字列を入力>> ";	//入力メッセージ
	
	cin >> str ;//文字列の入力



	//領域に格納されている文字列の表示
	cout << "文字列=" << str << endl;

	_getch();
	return 0;
}
