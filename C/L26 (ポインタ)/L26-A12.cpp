/*
課題番号　：L26-12
内容　　　：calcarrayオブジェクトにint型配列（要素数５）を渡して、最大値を表示する。
　　　　　　main関数で配列は宣言と同時に初期化する。
　　　　　　配列要素数はconst指定子を使って宣言する。
　　　　　　表示はmain関数で行う。
ファイル名：L26-A12.cpp
作成日　　：2016/1/21
作成者　　：BayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 5;					//要素数の定義

//配列計算クラス定義
class CalArray {
public:
	//最大値探索　n[]：配列の先頭アドレス
	//　　　　　　戻り値：最大値
	int findMax(int n[])
	{
		
		int max = 0;	//最大値の添字を格納

		for (int i = 1; i < MAX; i++){
			if (n[i] > n[max]){
				max = i;
			}
		}
		return n[max];
	}
};
/////////////////////////////////////////////////////////////
int main()
{
	CalArray calarray;
	int ary[MAX] = { 30, 20, 50, 10, 40 };

	cout << "最大値=" << calarray.findMax(ary) << endl;

	_getch();
	return 0;
}
