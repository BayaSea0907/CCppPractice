/*
課題番号　：L26-DeluxeSpecial3
内容　　　：char型文字配列に入力した２つの文字列（最大文字数１０）を、辞書書式の順序で比較した大小
　　　　　　関係を表示する。
　　　　　　文字列の大小比較は、最初に入力した単語が　"!"　になるまで繰返す。
　　　　　　文字列の比較には、文字列比較用標準関数strcmp関数を使う。
　　　　　　main関数のみで行う。
ファイル名：L26-DX3.cpp
作成日　　：2016/1/28
作成者　　：BayaSea
*/

//確認すること：
//□文字列を比較する関数は、既に標準関数で用意されていることを確認しなさい。
//A.確認しました。

#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
	char str1[11];		//最大10文字を格納
	char str2[11];		//最大10文字を格納
	int ret;			//戻り値用
	

	while (1){
		cout << "文字列を入力（最大１０文字））：終了は !>> ";
		cin >> str1;
		if (strcmp("!", str1) == 0)break;

		cout << "文字列を入力（最大１０文字）>> ";
		cin >> str2;

		ret = strcmp(str1, str2);

		switch (ret)
		{	
			case -1: cout << str1 << "<" << str2 << endl;
				break;
			case 1: cout << str1 << ">" << str2 << endl;
				break;
			case 0: cout << str1 << "=" << str2 << endl;
				break;
		}
	}
	_getch();
	return 0;
}
