/*
課題番号　：L21-Special1
内容　　　：testオブジェクトに、入力した５つの得点を要素にもつ得点配列（要素数５）を格納して、最高
　　　　　　点と最低点を表示する。
　　　　　　最高点と最低点をもつ要素番号を、いちどオブジェクトに格納する。
　　　　　　最高点と最低点の要素番号格納用プロパティ変数は、クラス定義で0で初期化する。
　　　　　　入力と表示はmain関数で行う。
ファイル名：L21-S1.cpp
作成日　　：2015/11/12
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//テストクラス定義
class Test {
	int ten[5];		//得点配列
	int max = 0;	//最高点の要素番号格納用（0）
	int min = 0;	//最低点の要素番号格納用（0）
public:
	//得点設定　n[]：得点配列
	void setTen(int n[]){
		for (int i = 0; i < 5; i++){
			ten[i] = n[i];
		}
	}

	//最高点・最低点検索
	void searchMaxMin(){
		for (int i = 0; i < 5; i++)
		{
			//最高点の検索
			if (ten[max] < ten[i])
			{
				max = i;
			}
			//最低点の検索
			if (ten[min] > ten[i])
			{
				min = i;
			}
		}
	}

	int getMax(){ return ten[max]; }	//最高点取得
	int getMin(){ return ten[min]; }	//最低点取得
};
////////////////////////////////////////////////////////////
int main()
{
	Test test;		//テストオブジェクト宣言
	int ten[5];		//得点入力用

	//点入力
	for (int i = 0; i < 5; i++){
		cout << "得点を入力>> ";
		cin >> ten[i];
	}

	test.setTen(ten);		//得点入力メソッドの呼び出し
	test.searchMaxMin();	//最高点・最低点検索メソッドの呼び出し

	cout << "最高点=" << test.getMax() << endl;
	cout << "最低点=" << test.getMin() << endl;

	_getch();
	return 0;
}

