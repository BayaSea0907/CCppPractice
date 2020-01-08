/*
課題番号　：L25-2
内容　　　：gameオブジェクトにタイトル名"TwilightLove"をchar型文字配列（要素数２１）に格納して
　　　　　　タイトル名を表示する。
　　　　　　標準関数strcpy_s関数を使わずに、タイトル名取得用文字配列にタイトル名を１文字ずつwhile
　　　　　　文を使ってコピーする。
　　　　　　表示はmain関数で行う。
ファイル名：L25-02.cpp
作成日　　：2015/12/20
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ゲームクラス定義
class Game {
	char title[13];	//タイトル
public:
	//タイトル設定
	void setTitle(){
		strcpy_s(title, 21, "TwilightLove");
	}

	//タイトル取得　str[]：タイトル取得用配列
	void getTitle(char str[]) {
		//１文字ずつコピー　文字列の終端文字'\0'を利用
		int i = 0;

		for (; title[i] != '\0'; i++)
		{
			str[i] = title[i];
		}

		//コピーした文字列の終わりに終端文字'\0'をつける
		str[i] = '\0';
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

