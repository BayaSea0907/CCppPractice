/*
課題番号　：L12-3
内容　　　：整数値200を入力して、それに100を足した値を表示する。
　　　　　　ただし、値を入力した変数を書き換えないものとする。
ファイル名：L12-03.cpp
作成日　　：2015/04/13
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int num;			//整数値格納用
	int wa;				//合計用

	cout << "整数値を入力（例　200）>> ";

	//整数値の入力
	cin >> num;

	//合計計算（変数numの値と100を足した合計を変数waに代入）
	wa = num + 100;

	//合計値を格納した変数waの値を表示
	cout << "100を足した結果=" << wa << endl;

	//合計計算結果を表示（変数waを使わない）
	cout << "100を足した結果=" << num + 100 << endl;

	_getch();
	return 0;
}
