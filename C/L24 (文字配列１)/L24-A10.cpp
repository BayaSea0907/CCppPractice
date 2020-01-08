/*
課題番号　：L24-10
内容　　　：英大文字'A'～'Z'と英小文字'a'～'z'の各文字の１０進整数を表示する。
　　　　　　main関数のみで行う。
ファイル名：L24-B10.cpp
作成日　　：2015/12/10
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	char c;

	//英大文字数値変換表示
	for (c = 'A'; c <= 'Z'; c++){
		cout << c << "=" << (int)c << endl;
	}

	cout << endl;

	//英小文字数値変換表示
	for (c = 'a'; c <= 'z'; c++){
		cout << c << '=' << (int)c << endl;
	}

	_getch();
	return 0;
}




