/*
課題番号　：L26-SuperDeluxe1
内容　　　：valoprオブジェクトにint型領域を参照するポインタのアドレスを渡して、int型領域に値を
　　　　　　入力して表示する。
　　　　　　入力はオブジェクトで行い、表示はmain関数で行う。
ファイル名：L26-SD1.cpp
作成日　　：2016/1/28
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//値操作クラス定義
class ValOpr {
public:
	//入力　**p：int型領域を参照するポインタのアドレス
	void input(int** p){
		cout << "整数を入力>> " ;
		cin >> **p;
	}
};
//////////////////////////////////////////////////////
int main()
{
	ValOpr valopr;
	int num;			//入力値格納用
	int* p;

	p = &num;			//numのアドレスをポインタpに代入

	valopr.input(&p);		//ポインタpのアドレスを渡す

	cout << "num=" << *p << endl;

	_getch();
	return 0;
}


