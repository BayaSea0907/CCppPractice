/*
課題番号　：L16-13
内容　　　：九九kukuオブジェクトのメソッドで、２重ループを使って掛け算九九を表示する。
　　　　　　各数値を3桁表示で行う。
　　　　　　（iomanipをインクルードして、coutでsetw(3)に続けて数値を表示する）。
ファイル名：L16-A13.cpp
作成日　　：2015/10/01
作成者　　：BayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//九九クラス定義
class Kuku {
public:
	//九九表示メソッド
	void showKuku()
	{
		cout << "掛ける数   *1   *2   *3   *4   *5   *6   *7   *8   *9" << endl << endl;

		//行（段）の制御　gyo：行（段）用ループカウンタ
		for(int gyo = 1; gyo <= 9; gyo++)
		{
			cout << gyo << "の段 >> ";

			//列の制御　retu：列用ループカウンタ
			for(int retu = 1; retu <= 9; retu++)
			{

				cout << setw(3) << gyo*retu << "　"  ;		//行*列の結果の値を3桁で表示
			}

			cout <<  endl;									//行末の改行
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Kuku kuku;			//九九オブジェクト宣言

	kuku.showKuku();	//九九表示メソッドの呼び出し

	_getch();
	return 0;
}
