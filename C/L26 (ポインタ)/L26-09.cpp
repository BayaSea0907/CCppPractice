/*
課題番号　：L26-9
内容　　　：heroオブジェクトのアドレスをポインタに格納して、ポインタを使ってオブジェクトのヒーロー
　　　　　　名"BERG"を表示する。
　　　　　　ヒーロー名は、クラス定義で初期化する。
　　　　　　表示はmain関数で行う。
ファイル名：L26-09.cpp
作成日　　：2016/1/14
作成者　　：BayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	string name = "BERG";		//アイテム名
public:
	//ヒーロー名取得
	string getName(){
		return name;
	}
};
/////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	Hero* p;		//heroオブジェクトへのポインタ

	p =	&hero; 		//heroオブジェクトのアドレスをポインタへ格納

	cout << p->getName() << endl; 	//ポインタを使ってヒーロー名を表示

	_getch();
	return 0;
}



