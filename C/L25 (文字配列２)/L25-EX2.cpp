/*
課題番号　：L25-ExtraSpecial2
内容　　　：bookオブジェクトに入力したタイトルをstring文字列に格納して、英文字のみのタイトルに変
　　　　　　換する。そして、続けて入力した文字列（string文字列）を結合した英文字のみのタイトルを表
　　　　　　示する。
　　　　　　入力と表示はmain関数で行う。
ファイル名：L25-EX2.cpp
作成日　　：2016/1/5
作成者　　：BayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//本クラス定義
class Book {
	string title;		//タイトル
	string pack;		//英字のみの文字列用
public:
	//タイトル設定　str：タイトル文字列
	void setTitle(string str) {
		pack = str;
	}

	//英字列作成
	void packAlpha() {
		for (int i = 0; pack[i] != '\0'; i++) 
		{
			if (('a' <= pack[i] && pack[i] <= 'z') 
			   || ('A' <= pack[i] && pack[i] <= 'Z'))
			{
				title += pack[i];
			}
		}
	}

	//英字タイトル結合　str：結合タイトル
	void addPack(string str) {
		pack = title + ' ' + str;
	}

	//英字タイトル取得
	string getPack() {
		return pack;
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	Book book;
	string str;			//タイトル、結合タイトル入力用

	cout << "タイトルを入力（例　S*12ta[rT6r++e?k+=）>> ";
	cin >> str;
	book.setTitle(str);		//タイトル設定メソッドの呼び出し

	book.packAlpha();		  //英字列作成メソッドの呼び出し

	cout << "結合タイトルを入力（例　Milky Way）>> ";
	cin >> str;
	book.addPack(str);		//英字タイトル結合メソッドの呼び出し

	cout << book.getPack() << endl;
	_getch();
	return 0;
}
