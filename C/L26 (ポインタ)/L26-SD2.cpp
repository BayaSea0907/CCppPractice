/*
課題番号　：L26-SuperDeluxe2
内容　　　：自然数を１つ入力して、その自然数までの階乗計算数値（例えば、5!=120(1*2*3*4*5)）を
　　　　　　表示する。
　　　　　　階乗計算は再帰関数メソッドとする。
　　　　　　自然数の型は、unsigned int。
　　　　　　表示はmain関数で行う。
ファイル名：L26-SD2.cpp
作成日　　：2016/2/3
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//値操作クラス定義
class ValOpr {
public:
	//階乗計算取得（再帰）　n：値
	int factorial(unsigned int n){

		if (n <= 1){		//(n == 0)
			return 1;
		}
		else{
			return n * factorial(n - 1);
		}
	}
};
//////////////////////////////////////////////////////
int main()
{
	ValOpr valopr;
	unsigned int num;			//入力値格納用

	cout << "自然数を入力>> ";
	cin >> num;

	//階乗計算取得メソッドを呼び出して表示
	cout << num << "!=" << valopr.factorial(num) << endl;

	_getch();
	return 0;
}

