/*
課題番号　：L12-8
内容　　　：実数値を入力して、その値を半径とする円の直径と面積を実数値で表示する。
　　　　　　円周率は3.1415926
　　　　　　計算で求めた直径と面積は、それぞれの変数に格納する。
ファイル名：L12-08.cpp
作成日　　：2015/05/13
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	double radius;		//半径
	double diameter;	//直径
	double area;		//面積

	cout << "半径を実数値で入力（例　10.5）>> ";
	cin >> radius;

	//直径の計算
	diameter = radius + radius;

	//面積の計算
	area = radius * radius * 3.1415926 ;

	printf(% 10d, area);

	cout << "直径=" << diameter << endl;
	cout << "面積=" << area << endl;

	_getch();
	return 0;
}
