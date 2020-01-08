/*
課題番号　：L12-6
内容　　　：整数値２と３をそれぞれ格納した２つの変数を計算して３０を表示する。
ファイル名：L12-06.cpp
作成日　　：2015/04/13
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int num1 = 2;		//整数型変数の宣言と同時の初期化
	int num2 = 3;		//整数型変数の宣言と同時の初期化
	int ans;		    //計算結果用

	ans = (num1 + num2) * num1 *num2;

	cout << "ans=" << ans << endl;

	_getch();
	return 0;
}
