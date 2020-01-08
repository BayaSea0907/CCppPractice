/*
課題番号　：L24-Special1
内容　　　：入力した半角１文字を１０進整数で表示する。
　　　　　　main関数のみで行う。
ファイル名：L24-S1.cpp
作成日　　：15CU0210小林裕樹
作成者　　：BayaSea
*/

//□英大文字（A～Z）、英小文字（a～z）を入力すると、どのような整数値になるでしょうか？
//A. A～Zは、65～90。　a～ｚは、97～122。

//□そのほかの文字ではどうなるでしょうか？
//A.文字としての1は　2進数では(0011 0001)なので、10進数だと(49)になりました。

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	char c;

	cout << "半角1文字を入力 (例: a ) >> " ;
	cin >> c;

	cout << c << " = " << (int)c << endl;

	_getch();
	return 0;
}


