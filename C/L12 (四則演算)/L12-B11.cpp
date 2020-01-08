/*
課題番号　：L12-11
内容　　　：入力した実数値を、小数点以下第１位の値を四捨五入した整数値で表示する。
ファイル名：L12-B11.cpp
作成日　　：2015/05/13
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	double zisu; 		//入力用
	int num; 		    //四捨五入した結果格納用

	cout << "実数値の入力>> ";
	cin >> zisu;


	num = (int)(zisu + 0.5); 	//四捨五入

	cout << "四捨五入した整数値=" << num << endl;

	_getch();
	return 0;
}
