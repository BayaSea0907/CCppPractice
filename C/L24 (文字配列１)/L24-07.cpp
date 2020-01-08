/*
課題番号　：L24-7
内容　　　：heroオブジェクトにヒーロー名"BERG"をchar型文字配列（要素数１０）に格納して、続けて
　　　　　　１文字と文字配列の添字位置を入力する。
　　　　　　そして、入力した１文字と入力した添字位置の文字とを置き換えたヒーロー名を表示する。
　　　　　　入力する添字位置は０～３。０～３以外の添字位置を入力した場合のエラー処理は考えない。
　　　　　　入力はmain関数で行い、表示はオブジェクトで１つの文字列として行う。
ファイル名：L24-07.cpp
作成日　　：2015/12/10
作成者　　：BayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	char name[10];		//ヒーロー名格納用文字配列
public:
	//ヒーロー名設定
	void setName(){
		strcpy_s(name, 10, "BERG");
	}

	//１文字置換　c：置換文字　id：置換添字
	void chgChar(char c, int id){
		name[id] = c;
	}

	//ヒーロー名表示
	void show(){
		cout << name;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero;
	char c; 	//１文字入力用 
	int id; 	//置換添字入力用 

	hero.setName();		//ヒーロー名設定メソッド呼び出し

	cout << "置換１文字と置換添字（0～3)を入力(例: H 2) >> ";
	cin >> c >> id;

	hero.chgChar(c, id);	//１文字置換メソッド呼び出し
	hero.show();			//ヒーロー名表示メソッド呼び出し

	_getch();
	return 0;
}

