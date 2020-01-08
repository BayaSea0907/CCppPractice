/*
課題番号　：L13-6
内容　　　：半径（実数値）を受け取って円の面積（実数値）を戻すcalcArea関数を、main関数から呼び出す。
　　　　　　関数が受け取る半径はmain関数で入力して、関数から戻る面積をmain関数で表示するものとする。
　　　　　　円周率は3.1415926
ファイル名：L13-06.cpp
作成日　　：2015/05/27
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

double calcArea(double radius); 	//関数のプロトタイプ宣言

int main()
{
	double radius;		//半径入力用
	double area;		//関数から戻ってきた面積格納用

	cout << "半径を実数値で入力（例　10.5）>> ";
	cin >> radius;

	//関数の呼び出し（半径を渡して戻った面積を格納する）

	area = calcArea(radius);

	cout << "面積=" << area << endl;

	_getch();
	return 0;
}

/*
関数名：calcArea
内容　：引数で受け取った半径の円の面積を計算する
引数　：double radius　半径
戻り値：double area　面積
*/
double calcArea(double radius)
{
	double area; 		//hyouzi関数で宣言した変数（自動変数）

	area = radius * radius * 3.1415926 ;
    
	return area;

	//次の１文だけでもよい（面積計算した値を戻す）
    //return radius * radius * 3.1415926;
}
