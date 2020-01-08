/*
課題番号　：L22-4
内容　　　：L22-3を書き換えて、heroオブジェクトに３つのアイテム名を要素とするアイテム配列を格納
　　　　　　して、オブジェクトに格納したヒーロー名とそれぞれのアイテム名を表示する。
　　　　　　アイテム配列は予めmain関数で初期化する。
　　　　　　ヒーロー名はクラス定義で初期化する。
　　　　　　表示はmain関数で行う。
ファイル名：L22-04.cpp
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
	//アイテム名取得　sitem[]：アイテム名配列
	void getItem(string sitem[])
	{
		for (int i = 0; i < 3; i++)
		{
			sitem[i] = item[i];
		}
	}
	//ヒーロー名取得
	string getName()
	{
		return name;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;	
	string item[3] = { "mant", "sword", "bomb" };		//string配列宣言と初期化
	string str[3];										//アイテム配列取得用

	hero.setItem(item);					//アイテム名設定メソッド呼び出し
	hero.getItem(str);					//アイテム名取得メソッド呼び出し

	cout << hero.getName() << endl;		//ヒーロー名取得

	//アイテム名表示
	for (int i = 0; i < 3; i++)
	{
		cout << str[i] << endl;	
	}

	_getch();
	return 0;
}


