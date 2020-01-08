/*
課題番号　：L25-Special4
内容　　　：gameオブジェクトにタイトル名"STARTREK"をstring型文字列に格納した後、１文字ずつ表示
　　　　　　する。
　　　　　　タイトル名は、クラス定義で初期化する。
　　　　　　表示は、gameオブジェクトで行う。
ファイル名：L25-S4.cpp
作成日　　：2016/1/5
作成者　　：BayaSea
*/

//実行時に確認すること：
//□string型オブジェクトの文字列の各文字を[添字]で扱えることを確認しなさい。
//A.確認しました。

//□string型オブジェクトの文字列にもヌル文字があることを確認しなさい。
//A.確認しました。

#include <conio.h>
#include <iostream>
using namespace std;

//ゲームクラス定義
class Game {
	string title = "STARTREK";		//タイトル用
public:
	//タイトル表示　１文字ずつ表示
	void show() {
		for (int i = 0; title[i] != '\0'; i++)
		{
			cout << title[i];
		}
		cout << endl;

	}
};
////////////////////////////////////////////////////////////
int main()
{
	Game game;

	game.show();		//タイトル表示メソッドの呼び出し

	_getch();
	return 0;
}




