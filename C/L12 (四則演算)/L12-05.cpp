/*
課題番号　：L12-5
内容　　　：整数値を２つ入力して、割り算した時の余りを表示する。
ファイル名：L12-05.cpp
作成日　　：2015/04/13
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int num1; 		//入力用
	int num2; 		//入力用
	int amari;		//余り用

	cout << "整数を２つ入力（例　100 3）>> ";

	cin >> num1 >> num2;

	amari = num1 % num2;		//余り計算

	//割った余りの表示
	cout << "割り算した余り=" << amari << endl;

	_getch();
	return 0;
}
