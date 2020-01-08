/*
課題番号　：L26-10
内容　　　：calcarrayオブジェクトに５つの点数を要素とするint型配列（要素数５）を渡して、合計と
　　　　　　平均を表示する。
　　　　　　配列要素数はconst指定子を使って宣言する。
　　　　　　main関数で配列は宣言と同時に初期化する。
　　　　　　表示はmain関数で行う。
ファイル名：L26-A10.cpp
作成日　　：2016/1/18
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 5;					//要素数の定義

//配列計算クラス定義
class CalcArray {
public:
	//合計・平均取得　n[]：点数配列の先頭アドレス、*p：合計用領域のアドレス
	//　　　　　　　　戻り値：double平均点
	double getAveSum(int n[], int* p){
		int sum = 0;	//合計用
		int i;			//添字用


		//合計点格納
		for(i = 0; i < MAX; i++){
			sum += n[i];
		}
		*p = sum;

		//平均点
		return (double)sum / (double)i;

	}
};
/////////////////////////////////////////////////////////////
int main()
{
	CalcArray calcarray;
	int ten[MAX] = { 100, 200, 300, 400, 500 };
	double ave;		//平均点取得用
	int sum;		//合計取得用

	ave = calcarray.getAveSum(ten, &sum);	//合計・平均取得メソッド呼び出し

	cout << "合計=" << sum << " 平均=" << ave << endl;

	_getch();
	return 0;
}

