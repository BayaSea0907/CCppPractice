/*
課題番号　：L13-8
内容　　　：受け取った２つの整数値の平均値を戻す関数を、main関数から呼び出す
　　　　　　関数が受け取る２つの整数値はmain関数で入力して、関数から戻る平均値をmain関数で表示する。
ファイル名：L13-A8.cpp
作成日　　：2015/05/27
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

double calcAve(int num1, int num2);	//関数のプロトタイプ宣言

int main()
{
	int num1, num2;					//入力用
	double ave;						//関数から戻った平均格納用

	ave = 0;

	cout << "整数値を２つ入力（例　100 200）>> ";

	cin >> num1 >> num2;

	ave = calcAve(num1, num2);		//関数の呼び出し（２つの整数値を渡して戻った平均を格納）


	cout << "平均値="  << ave << endl;

	_getch();
	return 0;
}

/*
関数名：calcAve
内容　：引数で受け取った２つの整数値の平均を計算する
引数　：int num1　整数値
　　　　int num2　整数値
戻り値：double　平均値
*/
double calcAve(int num1, int num2)
{
	double ave;

	ave = (double)(num1 + num2) / 2.0;

	return ave;

}
