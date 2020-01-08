/*
課題番号　：L25-ExcellentSpecial1
内容　　　：bookオブジェクトに入力したタイトルをstring型文字列に格納して、英小文字を英大文字に置
　　　　　　換えたタイトル名を表示する。
　　　　　　英小文字から英大文字への変換は、計算式を使います。
　　　　　　入力と表示はmain関数で行う。
ファイル名：L25-EX1.cpp
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
public:
	//タイトル設定　str：タイトル文字列
	void(setTitle(string str)) {
		title = str;
	}

	//文字変換
	void chgLetter() {
		for (int i = 0; title[i] != '\0'; i++) {
			if (('a' <= title[i]) &&(title[i] <= 'z') ) {
				title[i] -= ' ';
			}
			else{
				title = "英小文字ではありません";
			}
		}
	}

	//タイトル取得
	string getTitle() {
		return title;
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	Book book;
	string title;		//タイトル入力用
	string str;			//タイトル取得用

	cout << "タイトルを入力（例　StaRLinE）>> ";
	cin >> str;

	book.setTitle(str);		//タイトル設定メソッドの呼び出し
	book.chgLetter();		//文字変換メソッドの呼び出し

	cout << book.getTitle() << endl;

	_getch();
	return 0;
}

