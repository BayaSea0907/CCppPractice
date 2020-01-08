/*
課題番号　：L22-6
内容　　　：L22-4を書き換えて、heroオブジェクトに３つのアイテム名を要素とするアイテム配列を格納
　　　　　　して、オブジェクトに格納したヒーロー名とアイテム配列を１つのメソッドで取得して、ヒーロ
　　　　　　ー名とそれぞれのアイテム名を表示する。
　　　　　　アイテム配列は予めmain関数で初期化する。
　　　　　　ヒーロー名はクラス定義で初期化する。
　　　　　　表示はmain関数で行う。
ファイル名：L22-A6.cpp
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
	//コンストラクタ item配列を初期化
	Hero(){
		item[0] = "mant" ;
		item[1] = "sword";
		item[2] = "bomb" ;
	}

	//ヒーロー名、アイテム名取得　sitem[]：アイテム名配列
	//　　　　　　　　　　　　　　戻り値：ヒーロー名
	string getNameItem(string sitem[])
	{
		for (int i = 0; i < 3; i++)
		{
			sitem[i] = item[i];
		}

		return name;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	string str[3];			//アイテム配列取得用
	string name;			//ヒーロー名取得用

	name = hero.getNameItem(str);					//ヒーロー名、アイテム名取得メソッド呼び出し

	cout << name << endl; 	//ヒーロー名表示

	//アイテム名表示
	for (int i = 0; i < 3; i++)
	{
		cout << str[i] << endl;
	}

	_getch();
	return 0;
}

