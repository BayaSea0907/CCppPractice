/*
課題番号　：L26-Special2
内容　　　：stroprオブジェクトに２つのchar型文字配列（要素数１０）を渡して、第２引数の文字列
　　　　　　を第１引数の文字配列にコピーした第１引数の文字列を表示する。
　　　　　　文字列のコピーは１文字ずつ行う。
　　　　　　main関数で、第２引数の文字配列は宣言と同時に"AllStar"で初期化する。
　　　　　　表示はmain関数で行う。
ファイル名：L26-S2.cpp
作成日　　：2016/1/18
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//文字列操作クラス定義
class StrOpr {
public:
	//文字列コピー　s1[]：文字配列の先頭アドレス、s2[]：文字配列の先頭アドレス
	void copyStr(char s1[], char s2[]){
		int i = 0;			//添字用

		for (; s2[i] != '\0'; i++){
			s1[i] = s2[i];
		}
		s1[i] = '\0';
	}
};
/////////////////////////////////////////////////////////////
int main()
{
	StrOpr stropr;
	char org[10] = "AllStar";
	char trg[10];

	stropr.copyStr(trg, org);		//文字列コピーメソッド呼び出し

	cout << "trg=" << trg << endl;

	_getch();
	return 0;
}

