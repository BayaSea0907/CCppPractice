/*
課題番号　：L25-Special2
内容　　　：gameオブジェクトにタイトル名"STARTREK"をコンストラクタでchar型文字配列（要素数１０）
　　　　　　に格納して、タイトル名を表示する。
　　　　　　ただし、配列要素数は必要最低限とする。
　　　　　　表示は、gameオブジェクトで行う。
ファイル名：L25-S2.cpp
作成日　　：2016/1/4
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ゲームクラス定義
class Game {
	char title[10];	//タイトル用
public:
	//コンストラクタ
	Game() {
		strcpy_s(title, 10, "STARTREK");
	}

	//タイトル表示
	void showTitle() {
		cout << title << endl;
	}

};
////////////////////////////////////////////////////////////
int main()
{
	Game game;

	game.showTitle();		//タイトル表示メソッドの呼び出し

	_getch();
	return 0;
}


