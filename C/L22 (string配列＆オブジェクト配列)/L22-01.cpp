/*
課題番号　：L22-1
内容　　　：heroオブジェクトにヒーロー名と３つのアイテム名（string文字列）を格納して、ヒーロー名
　　　　　　とそれぞれのアイテム名を表示する。
　　　　　　ヒーロー名はクラス定義で初期化する。
　　　　　　格納と表示はオブジェクトで行う。
ファイル名：L22-01.cpp
作成日　　：2015/11/12
作成者　　：BayaSea
*/

#include <string>		//文字列操作用
#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	int* item;			//アイテム名配列
public:
	//アイテム名設定
	void setItem(int* n)
	{
		item = n;
	}
	//ヒーロー名、アイテム名表示
	void show(){
		cout << (unsigned char)item << endl;


	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	int item = 15;

	hero.setItem(&item);		//アイテム名設定メソッドの呼び出し
	hero.show();		//ヒーロー名、アイテム名表示メソッドの呼び出し

	_getch();
	return 0;
}

