/*
課題番号　：L26-Special1
内容　　　：stroprオブジェクトにchar型文字配列（最大文字数１０）を渡して、文字列中の英小文字を英
　　　　　　大文字に置き換えた文字列を表示する。
　　　　　　main関数で、文字列は宣言と同時に"gameCU"で初期化する。
　　　　　　表示はmain関数で行う。
ファイル名：L26-S1.cpp
作成日　　：2016/1/18
作成者　　：BayaSea
*/

//プログラムを書き換えて確認すること：
//□引数を、＊ポインタ変数名　にしても、配列を同じように操作できることを確認しましょう。
//A.確認しました。

#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 11;			//配列要素数の定義
//文字列操作クラス定義
class StrOpr {
public:
	/**/
	//英小文字英大文字変換　s[]：文字配列のアドレス
	void smallToBig(char s[]){
		for (int i = 0; s[i] != '\0'; i++){
			if ('a' <= s[i] && s[i] <= 'z'){
				s[i] -= ' ';
			}
		}
	}

	///////////////////////////////////////////////////////////////////
	/*
	//ポインタで配列の先頭アドレスを受け取る関数
	//英小文字英大文字変換　*p：文字配列のアドレス
	void smallToBig(char* p)
	{
		for (int i = 0; *(p + i) != '\0'; i++){
			if ('a' <= *(p + i) && *(p + i) <= 'z'){
				*(p + i) -= ' ';
			}
		}
	}*/
};
/////////////////////////////////////////////////////////////
int main()
{
	StrOpr stropr;
	char str[MAX] = "gameCU";

	stropr.smallToBig(str);	//英小文字英大文字変換メソッド呼び出し

	cout << str << endl;

	_getch();
	return 0;
}

