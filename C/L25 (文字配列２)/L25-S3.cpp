/*
課題番号　：L25-Special3
内容　　　：scoreオブジェクトのプロパティ配列（要素数１０）をコンストラクタで０で初期化して、すべ
　　　　　　ての要素を表示する。
　　　　　　表示は、scoreオブジェクトで行う。
ファイル名：L25-S3.cpp
作成日　　：2016/1/5
作成者　　：BayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//スコアクラス定義
class Score {
	int ten[10];	//点数
public:
	//コンストラクタ
	Score()
	{
		//要素数と比較
		//for (int i = 0; i < (sizeof(ten) / sizeof(ten[0])); i++) {		
		for (int i = 0; i < 10; i++) {
			ten[i] = 0;
		}
	}

	//点数表示
	void show() {
		for (int i = 0; i < 10; i++) {
			cout << ten[i] << ' ' ;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Score score;

	score.show();		//点数表示メソッドの呼び出し

	_getch();
	return 0;
}


