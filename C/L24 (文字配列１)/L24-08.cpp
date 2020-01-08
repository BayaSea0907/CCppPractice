/*
課題番号　：L24-8
内容　　　：heroオブジェクトに、３つのアイテム名（最大９文字）を要素とするchar型２次元文字配列（３
　　　　　　行１０列）を格納して、それぞれのアイテム名を表示する。
　　　　　　main関数で、２次元文字配列を宣言と同時に３つのアイテム名で初期化する。
　　　　　　オブジェクトで２次元文字配列にアイテム名を格納するときと、表示はアイテム名（文字列単位）
　　　　　　で行う。
　　　　　　表示はオブジェクトで行う。
ファイル名：L24-08.cpp
作成日　　：2015/12/10
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	char item[3][10];      //アイテム名２次元配列
public:
	//アイテム名設定　s[][10]：アイテム配列
	void setItem(char s[][10])
	{
		//行単位で文字列を格納する
		for (int i = 0; i < 3; i++)
		{
			strcpy_s(item[i], 10, s[i]);
		}
	}

	//アイテム名表示
	void show()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << item[i] << endl;
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	char str[3][10] = {
		"mant",
		"bigSword",
		"goldenAxe"
	};

	hero.setItem(str); 	//アイテム名設定メソッド呼び出し
	hero.show();		//アイテム名表示メソッド呼び出し

	_getch();
	return 0;
}

