/*
課題番号　：L25-DeluxeSpecial2
内容　　　：dicオブジェクトに入力した２つの単語をstring文字列に格納して、辞書書式の順序で比較した
　　　　　　大小関係を表示する。
　　　　　　最初に入力した単語が　!　になるまで繰返す。
　　　　　　入力した２つの単語を辞書書式の順序で比較した大小関係は、単語の長さ（文字数）と文字コー
　　　　　　ドの並び順（英小文字は英大文字よりも大きい）ことを指す。
　　　　　　break文を使ってもよい。
　　　　　　入力と表示はmain関数で行う。
　　　　　　処理を繰返すので、入力、大小比較、結果表示を無限ループで制御して、最初に入力した単語に
　　　　　　!　を入力したときループを抜けるようにする。
ファイル名：L25-DX2.cpp
作成日　　：2016/1/5
作成者　　：BayaSea
*/

//実行時に確認すること：
//□実行例以外に、先に上げた(1)～(3)のすべての例を確認しなさい。
//A.確認しました。

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//辞書クラス定義
class Dictionary {
	string words1;		//単語用
	string words2;		//単語用
	int flag;			//大小関係識別用（０：同じ　１：words1が大きい　
						//				－１：words2が大きい）
public:
	//単語設定　w1：単語、w2：単語
	void setWords(string w1, string w2) {
		words1 = w1;
		words2 = w2;
	}

	//単語辞書順比較
	void compWords() {
		if (words1 == words2) {
			flag = 0;
		}
		else if (words1 > words2) {
			flag = 1;
		}
		else {
			flag = -1;
		}
	}

	//比較結果取得
	int getResult(){
		return flag ;
	}

};
////////////////////////////////////////////////////////////
int main()
{
	Dictionary dic;
	string words1;		//単語１入力用
	string words2;		//単語２入力用
	int flag;			//大小関係識別用（０：同じ　１：words1が大きい　
	//									－１：words2が大きい）

	while (1)
	{
		cout << "単語を入力：終了は !>> ";
		cin >> words1;

		cout << "単語を入力>> ";
		cin >> words2;

		if (words1 == "!") {
			cout << "処理を終了します" << endl;
			break;
		}

		dic.setWords(words1, words2);	  //単語設定メソッド呼び出し
		dic.compWords();			 //単語辞書順比較メソッド呼び出し

		flag = dic.getResult();		//比較結果表示メソッド呼び出し

		switch (flag)
		{
			case -1: cout << words1 << " > " << words2 << endl << endl;
					 break;
			case  0: cout << words1 << " = " << words2 << endl << endl;
				 	 break;
			case  1: cout << words1 << " < " << words2 << endl << endl;
					 break;
		}
	}

	_getch();
	return 0;
}
