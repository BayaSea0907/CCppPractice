/*---------------------------------------------------------------------------
|課題4 division
|   加算、減算だけを用いて、整数の除算を行うアルゴリズムを考えよ。ただし、
|	商と余りを求める。2整数(被除数、除数)はキー入力する。また、入力は必ず
|	被除数＞除数であるとする。
|
|	2016/5/30	BayaSea
-----------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main ()
{
	unsigned int dividend;				//被除数
	unsigned int divisor;				//除数
	unsigned int quotient = 0;			//商
	unsigned int surplus;				//剰余

	cout << "被除数・除数の入力(例:	20 3) >>";
	cin >> dividend >> divisor;

	surplus = dividend; 
	
	//除算
	while(surplus >= divisor)
	{
		surplus -= divisor;
		quotient++;
	}

	cout << "被除数 : " << dividend << endl;
	cout << "除数 : "	 << divisor	   << endl << endl;
	cout << dividend << " / " << divisor << " = " << quotient << "…" << surplus << endl;

	system ("pause");
	return 0;
}