/*
課題番号　：L24-2
内容　　　：L24-1を書き換えて、heroオブジェクトにヒーロー名"BERG"を１文字ずつ、for文を使って
　　　　　　char型文字配列（要素数４）に入力して、ヒーロー名を表示する。
　　　　　　for文を使って１文字ずつ表示して、最後に必ず改行する。
　　　　　　繰返し制御は、文字数で行う。
　　　　　　入力と表示は、オブジェクトで行う。
ファイル名：L24-02.cpp
作成日　　：2015/12/10
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	char name[10];		//ヒーロー名格納用文字配列
public:
	//ヒーロー名入力　1文字ずつ入力
	void inpName(){
		for (int i = 0; i < 4; i++)
		{
			cout << "ヒーロー名の１文字を入力>> ";
			cin >> name[i];
		}
	}
	//ヒーロー名表示　１文字ずつ表示
	void show(){
		for (int i = 0; i < 4; i++){
			cout << name[i] ;
		}
		cout << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.inpName();		//ヒーロー名入力メソッド呼び出し
	hero.show();		//ヒーロー名表示メソッド呼び出し

	_getch();
	return 0;
}


