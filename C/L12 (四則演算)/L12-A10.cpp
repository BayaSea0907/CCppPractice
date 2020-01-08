/*
課題番号　：L12-10
内容　　　：L12-8のすべての変数を整数型に変更するとコンパイルエラーがおきる。
　　　　　　コンパイルエラーをおこさずに、直径と面積を整数値で表示できるように型を揃えて修正する。
ファイル名：L12-A10.cpp
作成日　　：2015/05/13
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int radius;		//半径
	int diameter;	//直径
	int area;		//面積

	//半径の入力
	cout << "半径を整数値で入力（例　10）>> ";
	cin >> radius;

	//直径の計算
	diameter = radius + radius;

	//面積の計算
	area = (int)((double)(radius * radius) * 3.1415926);

	//直径と面積の表示
	cout << "直径=" << diameter << endl;
	cout << "面積=" << area << endl;

	_getch();
	return 0;
}
