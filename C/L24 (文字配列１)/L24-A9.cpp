/*
課題番号　：L24-9
内容　　　：gameオブジェクトに入力した最大１０文字までのタイトル名"DEADKINDS"をchar型文字配列に
　　　　　　格納して、そのタイトル名に含まれる英大文字'D'を'#'に置換えたタイトル名を表示する。
　　　　　　置換えにはfor文を使い、要素内容が終端文字（ヌル文字）になるまで繰返す。
　　　　　　入力はmain関数で行い、表示はオブジェクトで１つの文字列として行う。
ファイル名：L24-A9.cpp
作成日　　：2015/12/10
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ゲームクラス定義
class Game {
	char title[11];	//タイトル
public:
	//タイトル設定　str[]：タイトル配列
	void setTitle(char str[]){
		strcpy_s(title, 11, str);
	}

	//文字の置換え
	void chgTitle(){
		//文字列の終端文字'\0'を利用
		for (int i = 0; title[i] != '\0'; i++){
			if (title[i] == 'D'){
				title[i] = '#';
			}
		}
	}
	//タイトル表示
	void show(){
		cout << title << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Game game;		//ゲームオブジェクト宣言
	char title[11];	//タイトル入力用

	cout << "10文字までのタイトル名を入力>> ";
	cin >> title;

	game.setTitle(title);		//タイトル設定メソッドの呼び出し

	game.chgTitle();		//文字の置換えメソッドの呼び出し
	game.show();			//タイトル表示メソッドの呼び出し

	_getch();
	return 0;
}

