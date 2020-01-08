/*
課題番号　：L26-11
内容　　　：stroprオブジェクトのアドレスをポインタに格納して、ポインタを使ってオブジェクトに
　　　　　　string型文字列"CUgameAllStar"と入力した１文字を渡して、文字列に１文字があるかどうか
　　　　　　の検索結果を表示する。
　　　　　　文字列に１文字がある場合は“ある”、ない場合は“ない”と表示する。
　　　　　　string型文字列はmain関数で宣言と同時に初期化する。
　　　　　　入力と表示は、main関数で行う。
ファイル名：L26-A11.cpp
作成日　　：2016/1/18
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//文字列操作クラス定義
class StrOpr {
public:
	//文字列検索　str：検索対象文字列　c：検索文字
	//　　　 　戻り値：検索結果（１　見つけた、　０　見つからない）
	int findLetter(string str, char c)
	{
		int result = 0;			//検索結果取得用

		//ヌル文字になるまで繰り返す
		for (int i = 0; str[i] != '\0'; i++){
			//検索文字を見つけた場合
			if (str[i] == c){
				result = 1;
				break;
			}
		}
		return result;
	}
};
/////////////////////////////////////////////////////////////
int main()
{
	StrOpr stropr;
	StrOpr* p;			//stroprオブジェクトへのポインタ
	string str = "CUgameAllStar";
	char c;			//入力検索文字用
	int result;		//検索結果取得用

	p = &stropr;		//stroprオブジェクトのアドレスをポインタへ格納

	cout << "検索文字を入力>> ";
	cin >> c;

	result = p->findLetter(str, c);		//文字列検索メソッド呼び出し

	//検索結果の表示
	if (result){
		cout << "ある" << endl;
	}
	else{
		cout << "ない" << endl;
	}
		
	_getch();
	return 0;
}
