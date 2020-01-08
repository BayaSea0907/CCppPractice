/*
課題番号　：L22-3
内容　　　：heroオブジェクトに３つのアイテム名を要素とするアイテム配列を格納して、ヒーロー名とそれ
　　　　　　ぞれのアイテム名を表示する。
　　　　　　アイテム配列は予めmain関数で初期化する。
　　　　　　ヒーロー名はクラス定義で初期化する。
　　　　　　表示はオブジェクトで行う。
ファイル名：L22-03.cpp
作成日　　：2015/11/12
作成者　　：BayaSea
*/

#include <string>		//文字列操作用
#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	string name = "BERG";	//ヒーロー名
	string item[3];		//アイテム名配列
public:
	//アイテム名設定　sitem[]：アイテム名配列
	void setItem(string sitem[])
	{
		for (int i = 0; i < 3; i++)
		{
			item[i] = sitem[i];
		}
	}

	//ヒーロー名、アイテム名表示
	void show()
	{
		cout << name << endl;

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
	string item[3] = { "mant", "sword", "bomb" };		//string配列宣言と初期化

	hero.setItem(item);		//アイテム名設定メソッド呼び出し
	hero.show();			//アイテム名表示メソッド呼び出し

	_getch();
	return 0;
}


