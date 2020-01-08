/*
課題番号　：L25-5
内容　　　：gameオブジェクトのchar型文字配列に格納したタイトル名"XYZ123"に、他の文字列"ABC"をタ
　　　　　　イトル名の後ろに連結し直して、連結したタイトル名を表示する。
　　　　　　連結する文字列"ABC"は、main関数でchar型文字配列の宣言と同時に初期化する。
　　　　　　それぞれの文字配列の要素数は、必要最低限の要素数とする（配列のサイズに注意しましょう）。
　　　　　　格納はオブジェクトで行い、表示はmain関数で行う。
ファイル名：L25-05.cpp
作成日　　：2016/1/4
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ゲームクラス定義
class Game {
	char title[12];		//タイトル
public:
	//タイトル設定
	void setTitle(){
		strcpy_s(title, 7, "XYZ123");
	}

	//タイトル連結　str[]：連結文字列
	void concatTitle(char str[])
	{
		//タイトル文字列の文字数カウント
		int len1 = 0;
		for (; title[len1] != '\0'; len1++);

		//タイトルの連結
		int len2 = 0;

		for (; str[len2] != '\0'; len1++,len2++) {
			title[len1] = str[len2];
		}

		//連結したタイトルの終わりに終端文字'\0'をつける
		title[len1] = '\0';
	}

	//タイトル取得　str[]：タイトル取得用配列
	void getTitle(char str[]){
		strcpy_s(str, 12, title);
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Game game;
	char str[4] = "ABC";		//後ろに連結する文字列
	char title[12];				//連結後タイトル取得用

	game.setTitle();			//タイトル設定メソッドの呼び出し

	game.concatTitle(str);		//タイトル連結メソッドの呼び出し
	game.getTitle(title);		//タイトル取得メソッドの呼び出し

	cout << "連結後の文字列=" << title << endl;

	_getch();
	return 0;
}
