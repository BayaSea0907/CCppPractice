/*
課題番号　：L22-2
内容　　　：L22-1を書き換えて、heroオブジェクトに入力した３つのアイテム名を格納して、ヒーロー名
　　　　　　とそれぞれのアイテム名を表示する。
　　　　　　入力と表示はオブジェクトで行う。
ファイル名：L22-02.cpp
作成日　　：2015.10.1
作成者　　：BayaSea
*/

#include <string>		//文字列操作用
#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	string name = "BERG";		//ヒーロー名
	string item[3];			//アイテム名配列
public:
	//アイテム名入力
	void inpItem(){
		for (int i = 0; i < 3; i++)
		{
			cout << "アイテム名を入力>> ";
			cin >> item[i];
		}
	}

	//ヒーロー名、アイテム名表示
	void show(){
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

	hero.inpItem();		//アイテム名入力メソッドの呼び出し
	hero.show();		//ヒーロー名、アイテム名表示メソッドの呼び出し

	_getch();
	return 0;
}


