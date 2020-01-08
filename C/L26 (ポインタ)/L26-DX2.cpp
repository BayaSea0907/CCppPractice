/*
課題番号　：L26-DeluxeSpecial2
内容　　　：stroprオブジェクトにchar型文字配列に格納した文字列"CUgameAllStar"と入力した１文字
　　　　　　を渡して、文字列に１文字があるかどうかの検索結果を表示する。
　　　　　　文字列に１文字がある場合は"ある"、ない場合は"ない"と表示する。
　　　　　　また、文字列に１文字があった場合には、その文字以降の文字列も表示する。
　　　　　　main関数で、char型文字配列はは宣言と同時に初期化する。
　　　　　　表示はmain関数で行う。
ファイル名：L26-DX2.cpp
作成日　　：2016/1/28
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//文字列操作クラス定義
class StrOpr {
public:
	//文字列検索　str[]：検索対象文字配列の先頭アドレス　c：検索文字
	//　　　　　戻り値：char*　検索結果（配列要素のアドレス　ある、NULL　ない）
	char* findLetter(char str[], char c){
		char *p = NULL;		//添字用

		//文字検索
		for (int i = 0; str[i] != '\0'; i++){
			if (str[i] == c){
				p = &str[i];
				break;
			}
		}
		return p;
	}

};
////////////////////////////////////////////////////////////
int main()
{
	StrOpr stropr;
	char str[20] = "CUgameAllStar";
	char c;				//検索文字入力用
	char *p;			//検索結果要素アドレス取得用

	cout << "検索文字を入力>> ";
	cin >> c;

	p = stropr.findLetter(str, c);		//文字列検索メソッド呼び出し

	//検索結果の表示
	if (p == NULL){
		cout << "ない" << endl;
	}
	else{
		cout << "ある" << endl;

		cout << "検索文字以降の文字列=" << p << endl;
	}

	_getch();
	return 0;
}

