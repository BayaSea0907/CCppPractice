/*
課題番号　：L25-DeluxeSpecial1
内容　　　：partStrオブジェクトに入力した２つのstring文字列を格納して、最初に入力した文字列に、
　　　　　　２番目に入力した文字列が含まれているかどうかを検索した結果を表示する。
　　　　　　含まれる場合は"見つけた"、含まれない場合は"見つからない"と表示する。
　　　　　　break文を使ってもよい。
　　　　　　入力と表示はmain関数で行う。
ファイル名：L25-DX1.cpp
作成日　　：2016/1/5
作成者　　：BayaSea
*/

//実行時に確認すること：
//□すべての実行例を確認しなさい。

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//部分文字列検索クラス定義
class PartStr {
	string str;		//検索対象文字列用
	string part;	//検索文字列（部分文字列用）
	int sw = 0;		//検索結果識別子（０：見つからない　１：見つけた）
public:
	//文字列、検索文字列設　s：検索対象文字列、p：検索文字列
	void setStr(string s, string p) {
		str = s;
		part = p;
	}

	//部分文字列検索
	void searchPartStr()
	{
		/*nullになるまで繰り返す
		for (int i = 0; str[i] != '\0' ; i++)
		{
			//partの先頭の文字を検索
			for (int j = 0; str[i] == part[j]; j++) 
			{
				//先頭の次の文字がnullならば、検索終了
				if (part[j + 1] == '\0') {
					sw = 1;
				}else {
					i++;
				}
			}
			//str[i]が不定にならないうちに処理をやめる
			//if (str[i] == '\0') { break; }
			if (sw == 1){ break; }
		}*/

		//nullになるまで繰り返す
		int i = 0;

		while (1)
		{
			//partの先頭の文字を検索
			for (int j = 0; str[i] == part[j]; j++)
			{
				//先頭の次の文字がnullならば、検索終了
				if (part[j + 1] == '\0') {
					sw = 1;
				}else {
					i++;
				}
			}
			//str[i]が不定にならないうちに処理をやめる
			//if (str[i] == '\0') { break; }
			if (sw == 1){ 
				break; 
			}
			else{
				i++;
			}
		}

	//検索結果取得
	int getSw()
	{
		return sw;
	}

};
////////////////////////////////////////////////////////////
int main()
{
	PartStr partStr;
	string str;			//検索対象文字列用
	string part;		//検索文字列（部分文字列用）

	cout << "文字列を入力>> ";
	cin >> str;

	cout << "部分文字列を入力>> ";
	cin >> part;

	partStr.setStr(str, part);		//文字列、検索文字列設定メソッドの呼び出し
	partStr.searchPartStr();		//部分文字列検索メソッドの呼び出し


	if (partStr.getSw()) {
		cout << "見つけた" << endl;
	}else{
		cout << "見つからない" << endl;
	}

	_getch();
	return 0;
}

