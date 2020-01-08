/*
課題番号　：L16-Special3
内容　　　：図形figオブジェクトに行数を設定して、＊を表示する。
　　　　　　ただし、表示する＊は、１行目には１個、２行目には２個、・・・と、それぞれの行には行数と
　　　　　　同じ数だけを表示する。
　　　　　　また、＊は、cout << "*"; で表示する。
　　　　　　行数入力はmain関数で行い、図形表示はfigオブジェクトで行う。
ファイル名：L16-S3.cpp
作成日　　：2015/10/08
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//図形クラス定義
class Figure {
	int line;		//行数
public:
	//行数設定メソッド
	void setLine(int sline)
	{
		line = sline;
	}

	//図形表示メソッド
	void showFig()
	{
		int column = line;			//１行の表示＊最大個数
		int space = line;			//空白数

		//縦方向制御　i：行制御用
		for (int i = 0; i < line; i++)
		{
			int j;					//空白文字表示　：列制御用

			//横方向制御　＊までに空白文字を表示
			space -= 1;				//空白文字の個数取得

			//空白文字表示　int j：列制御用
			for (j = 0; j < space; j++)
			{
				cout << "A";
			}
			
			//＊を個数分表示
			for (j = 0; j < (column - space); j++)
			{
				cout << "*";
			}

			cout << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Figure fig;			//図形オブジェクト宣言
	int line;			//行数入力用

	cout << "何行表示しますか（５行の場合　5）>> ";
	cin >> line;
	fig.setLine(line);		//行数設定メソッド呼び出し

	fig.showFig();			//図形表示メソッドの呼び出し
	_getch();
	return 0;
}

