/*
課題番号　：L24-6
内容　　　：heroオブジェクトにヒーロー名"BERG"をchar型文字配列（要素数１０）に格納して、ヒーロ
　　　　　　ー名を表示する。
　　　　　　main関数でchar型文字配列を宣言と同時に初期化したヒーロー名"BERG"を、１つの文字列と
　　　　　　してオブジェクトに格納する。
　　　　　　オブジェクトからヒーロー名を取得して、main関数で１つの文字列として表示する。
ファイル名：L24-06.cpp
作成日　　：2015/12/10
作成者　　：BayaSea
*/

//プログラムを書き換えて確認すること：
//□char型文字配列を宣言と同時に初期化するとき、要素数を書かなくても初期化できることを確認しなさい。
//　    char name[] = "BERG";
//A.確認しました。

//□ヒーロー名"BERG"を１文字ずつ格納して初期化できることを確認しなさい。
//      char name[10] = {'B', 'E', 'R', 'G', '\0'};
//A.確認しました。

//□ヒーロー名を"DORONJOBOY"（１０文字）に置き換えると、表示された後、実行時エラーになることを確
//　認しなさい。（stack around the variable ‘hero’ was corrupted.）


#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	char name[10];		//ヒーロー名格納用文字配列
public:
	//ヒーロー名設定　str[]：ヒーロー名格納用文字配列
	void setName(char str[]){
		strcpy_s(name, 10, str);
	}
	//ヒーロー名取得　str[]：ヒーロー名取得用文字配列　size：str配列の要素数
	void getName(char str[], int size){
		strcpy_s(str, size, name);
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	//１つの文字列単位で格納して初期化した場合 
	char name[] = "BERG";

	//同じ並びの文字列を１文字単位で格納して初期化した場合
	//char name[10] = {'B', 'E', 'R', 'G', '\0'}; 

	char str[10];				//ヒーロー名取得用

	hero.setName(name);		//ヒーロー名設定メソッド呼び出し

	//ヒーロー名取得メソッド呼び出し
	hero.getName(str, 10);		//要素数指定に定数値使用

	//hero.getName(str, sizeof(str)); 	//sizeof関数使用

	cout << str << endl;		 //１つの文字列として表示

	_getch();
	return 0;
}
