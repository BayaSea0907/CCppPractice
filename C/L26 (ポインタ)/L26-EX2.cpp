/*
課題番号　：L26-ExtraSpecial2
内容　　　：ムービータイトルを変更したい。
　　　　　　movieオブジェクトにタイトル名"CU"を格納して、改めてオブジェクトに文字列" vs ARASHI"
　　　　　　を渡す。そして、" vs ARASHI"を連結したタイトルを表示する。
　　　　　　連結したタイトル名は、オブジェクトにいちど格納する。
　　　　　　main関数で、タイトル名はchar型文字配列（要素数３）、連結文字列はchar型文字配列（要
　　　　　　素数１１）に宣言と同時に初期化する。
　　　　　　表示はmain関数で行う。
ファイル名：L26-EX2.cpp
作成日　　：2016/1/28
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ムービークラス定義
class Movie {
	char name[13];		//ムービー名
public:
	//ムービー名設定　str[]：ムービー名
	void setName(char str[]){
		strcpy_s(name, 13, str);
	}

	//ムービー名連結　str[]：連結文字列
	void catName(char str[]){

		int len;			//文字列の終端の添え字格納用

		//name配列の終わりを求める
		for (len = 0; name[len] != '\0'; len++);

		//結合
		for (int i = 0; str[i] != '\0'; i++, len++){
			name[len] = str[i];
		}
		
		name[len] = '\0';		//文字列の終わりにヌル文字を格納
	}

	//ムービー名取得　str[]：ムービー名取得用
	void getName(char str[]){
		strcpy_s(str, 13, name);
	}
};
//////////////////////////////////////////////////////////////////
int main()
{
	Movie movie;
	char name[3] = "CU";
	char str[11] = " vs ARASHI";
	char result[13];			//ムービー名取得用

	movie.setName(name);		//ムービー名設定メソッドの呼び出し
	movie.catName(str);	 		//ムービー名連結メソッドの呼び出し
	movie.getName(result);		//ムービー名取得メソッドの呼び出し

	cout << "連結文字列=" << result << endl;

	_getch();
	return 0;
}
