/*
課題番号　：L25-3
内容　　　：L25-2を書き換えて、タイトル名取得用文字配列にタイトル名を１文字ずつdo～while文を使っ
　　　　　　てコピーしてタイトルを表示する。
　　　　　　表示はmain関数で行う。
ファイル名：L25-03.cpp
作成日　　：2015/12/21
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ゲームクラス定義
class Game {
	char name[13];	//タイトル
public:
	//タイトル設定
	void setTitle(){
		strcpy_s(name, 20, "TwilightLove");
	}

	//タイトル取得　str[]：タイトル取得用配列
	void getTitle(char s[]){
		//１文字ずつコピー
		int i = 0;

		do {
			s[i] = name[i];
			i++;

		} while (s[i] != '\0');
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Game game;		//ゲームオブジェクト宣言
	char title[13];	//タイトル取得用

	game.setTitle();			//タイトル設定メソッドの呼び出し
	game.getTitle(title);		//タイトル取得メソッドの呼び出し

	cout << title << endl;

	_getch();
	return 0;
}

