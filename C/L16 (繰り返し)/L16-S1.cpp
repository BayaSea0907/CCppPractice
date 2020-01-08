/*
課題番号　：L16-Special1
内容　　　：グラフgraphオブジェクトに点数を設定して、グラフを表示する。
　　　　　　10は●、1は＋で表すものとする。
　　　　　　得点に応じた表示種類●と＋の各個数は別のメソッドで計算して、いちどオブジェクトに格納しておく。
　　　　　　得点入力はmain関数で行い、グラフ表示はgraphオブジェクトで行う。
ファイル名：L16-S1.cpp
作成日　　：2015/10/01
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//グラフクラス定義
class Graph {	
	int score;						// 点数
	int dec;						//十の個数用
public:
	//得点設定メソッド
	void setTen(int ten)
	{
		score = ten;				//得点設定
	}

	//十の個数●計算メソッド
	void calcDec()
	{
		dec = score / 10;			//十の個数
		
	}

	//グラフ表示メソッド
	void showGraph()
	{
		//十の個数●表示
		for (int maru = 0; maru < dec; maru++)
		{
			cout << "●";
		}

		//一の個数＋表示
		for (int tasu = 0; tasu < score%10; tasu++)
		{
			cout << "＋";
		}
		cout << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Graph graph;					//オブジェクト宣言
	int score;						//点数入力用

	cout << "点数を入力（27点の場合　27）>> ";
	cin >> score;

	graph.setTen(score);			//得点設定メソッドの呼び出し

	graph.calcDec();				//十の個数計算メソッドの呼び出し
	graph.showGraph();				//グラフ表示メソッドの呼び出し

	_getch();
	return 0;
}


