/*
課題番号　：L16-2
内容　　　：計算calcオブジェクトのメソッドで、入力値をすべて掛け算した後、その値を表示する。
　　　　　　ただし、繰返しはwhile文を使って0が入力されるまで行う。
ファイル名：L16-02.cpp
作成日　　：2015/10/01
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//計算クラス定義
class Calc {
	int mul = 1;			//乗算結果用(1)

public:
	//乗算メソッド
	void multiply(){
		int num;           //入力用
		int sw = 1;        //繰返制御用（１：繰返す）

		//入力値を加算する
		while(sw != 0){
			cout << "整数値を入力>> ";
			cin >> num;

			//入力値判別
			if(num == 0){
				sw = 0;			//繰返しをやめる
			}
			else{
				mul *= num;		//掛け算
			}
		}
	}

	//乗算結果取得メソッド
	int getMul()
	{ 
		return mul;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Calc calc;		//計算オブジェクト宣言

	calc.multiply();      //乗算メソッド呼び出し
	cout << "乗算結果=" << calc.getMul() << endl;

	_getch();
	return 0;
}

