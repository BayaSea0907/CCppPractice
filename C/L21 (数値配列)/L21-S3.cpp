/*
課題番号：L21-Special3
内容　　：testオブジェクトに、入力した５つの得点を要素にもつ得点配列（要素数５）を格納して、合計
　　　　　と平均点、各得点と平均点との偏差の計算結果を表示する。
	  　　合計と平均点は、いちどオブジェクトに格納する。
		  入力はmain関数で行い、表示はオブジェクトで行う。
ファイル名：L21-S3.cpp
作成日　　：2015/12/03
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test {
	int ten[5];			//得点配列
	int total = 0;		//合計用（0）
	double ave;			//平均用
public:

	//得点設定　n[]：得点配列
	void setTen(int n[]){
		for (int i = 0; i < 5; i++){
			ten[i] = n[i];
		}
	}

	//合計・平均計算
	void calcAveTotal(){
		int i;			//ループカウンタ

		//合計を求める計算
		for (i = 0; i < 5; i++){
			total += ten[i];
		}

		//平均を求める計算
		ave = (double)total / (double)i;
	}

	//表示
	void show(){
		cout << "合計=" << total << " 平均=" << ave << endl;

		//偏差の表示と計算
		for (int i = 0; i < 5; i++){
			cout << "[" << i << "]の値と平均との偏差="
				<< (double)ten[i] - ave << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;	//テストオブジェクト宣言
	int ten[5];	//得点入力用

	for (int i = 0; i < 5; i++)
	{
		cout << "得点を入力>> ";
		cin >> ten[i];
	}

	test.setTen(ten); 		//得点設定メソッドの呼び出し
	test.calcAveTotal();	//合計・平均計算メソッドの呼び出し
	test.show();			//結果表示メソッドの呼び出し

	_getch();
	return 0;
}


