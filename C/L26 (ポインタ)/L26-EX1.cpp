/*
課題番号　：L26-ExtraSpecial1
内容　　　：calcarrayオブジェクトにint型配列（要素数５）を渡して、最大値が格納されている添字を
　　　　　　使って最大値を表示する。
　　　　　　main関数で、配列は宣言と同時に初期化する。　{30, 20, 50, 10, 40}
　　　　　　要素数は、const指定子を使って宣言する。
　　　　　　オブジェクトは、最大値が格納されている添字を戻す。
　　　　　　表示はmain関数で行う。
　　　　　　L26-12とは戻り値が異なるので気をつけましょう。
ファイル名：L26-EX1.cpp
作成日　　：2016/1/18
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 5;		//配列要素数の定義

//配列計算クラス定義
class CalcArray {
public:
	//最大値をもつ添字取得　ary[]：整数値配列の先頭アドレス
	int getMaxId(int ary[]){
		int max = 0;		//最大値の添字格納用

		//最大値検索
		for (int i = 1; i < MAX; i++){
			if (ary[i] > ary[max]){
				max = i;
			}
		}
		return max;
	}
};
/////////////////////////////////////////////////////////////
int main()
{
	CalcArray calcarray;
	int ten[MAX] = { 30, 20, 50, 10, 40 };
	int id;						//最大値をもつ添字取得用

	id = calcarray.getMaxId(ten);		//最大値をもつ添字取得メソッド呼び出し

	cout << "最大値=" << ten[id] << endl;

	_getch();
	return 0;
}

