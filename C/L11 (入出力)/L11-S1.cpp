/*
課題番号　：L11-special1
内容　　　：変数（num1とnum2）に整数値を入力した値を、入れ替える（交換する）
ファイル名：L11-S1.cpp
作成日　　：2015/04/30
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int num1; 		//入力用
	int num2; 		//入力用
	int taihi;		//退避用

	cout << "変数num1に整数値を入力>> ";
	cin >> num1;

	cout << "変数num2に整数値を入力>> ";
	cin >> num2;

	taihi = num1;
	num1  = num2;
	num2  = taihi;


		cout << "入れ替え後のnum1の値=" << num1 << " num2の値=" << num2 << endl;

	_getch();
	return 0;
}
