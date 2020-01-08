/*
課題番号　：L26-ExtraSpecial3
内容　　　：L26-EX2を書換えて、標準関数strcat関数を使ってムービー名を連結して、同じ結果を表示する。
ファイル名：L26-EX3.cpp
作成日　　：2016/1/28
作成者　　：BayaSea
*/

//確認すること：
//□文字列をコピーする関数は、既に標準関数で用意されていることを確認しなさい。

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
		strcat_s(name, 13, str);
	}

	//ムービー名取得　str[]：ムービー名取得用
	void getName(char str[]){
		strcpy_s(str, 13, name);
	}
};
////////////////////////////////////////////////////////////////
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
