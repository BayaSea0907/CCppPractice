/*
課題番号　：L25-1
内容　　　：gameオブジェクトに入力したタイトル名（最大２０文字）をchar型文字配列に格納して、タイ
　　　　　　トル名の文字数を表示する。
　　　　　　入力と表示はmain関数で行う。
　　　　　　ファイル名：L25-01.cpp
	  作成日　　：2015/12/20
	  作成者　　：BayaSea
	  */

#include <conio.h>
#include <iostream>
using namespace std;

//ゲームクラス定義
class Game {
	char name[21];		//タイトル用
public:
	//タイトル設定　str[]：タイトル文字配列
	void setTitle(char str[]){
		strcpy_s(name, 21, str);
	}
	//文字数取得
	int getLen(){
		int len = 0;		//文字数格納用

		//文字列の終端文字'\0'を利用
		for (; name[len] != '\0'; len++);

		return len;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Game game;
	char title[21];	//タイトル入力用

	cout << "20文字までのタイトル名を入力>> ";
	cin >> title;

	game.setTitle(title);		//タイトル設定メソッドの呼び出し

	cout << "文字数=" << game.getLen() << endl;

	_getch();
	return 0;
}


