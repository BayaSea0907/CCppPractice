/*
課題番号　：L15-9
内容　　　：人manオブジェクトに性別識別数値を設定した後、その数値を読み取って性別を判定表示する。
　　　　　　判定は、switch文を使って性別識別が0なら“男”、1なら“女”、それ以外なら“不明”と表示する。
　　　　　　性別識別数値入力はuiオブジェクトで行い、判定表示はmanオブジェクトで行う。
ファイル名：L15-09.cpp
作成日　　：2015/07/08
作成者　　：BayaSea
*/

//プログラムを書き換えて確認すること：
//□case 0のbreak文を削除（コメント文にする）したらどうなるでしょうか？
//A.男と女の両方が表示された。

//□性別識別を格納する変数の型を、実数型に書き換えたらどうなるでしょうか？
//switchに実数を使うとエラーが起こる

#include <conio.h>
#include <iostream>
using namespace std;

//人クラス定義
class Man {
	int sex;	//性別識別
public:
    //性別識別設定メソッド
	void setSex(int ssex){
		sex = ssex;
    }
    //性判定メソッド
    void judgeSex(){

		//性別の判別
		switch (sex)
		{
			case 0:	cout << "男" << endl;
				break;

			case 1:	cout << "女" << endl;
				break;

			default: cout << "不明" << endl;
				break;
		}
	}
};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Man man;	//人オブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl(){
		inpMan();		    //man入力設定
		man.judgeSex();	    //性判定
	}
	//man入力設定メソッド
	void inpMan(){
		int sex;	//性別識別入力用

		cout << "性別を入力（男は0、女は1）>> ";
		cin >> sex;
		man.setSex(sex);
	}
};
////////////////////////////////////////////////////////////////
int main()
{
	UI ui;			//ユーザインタフェースオブジェクト宣言

	ui.processCtrl();	//インタフェース処理制御

	_getch();
	return 0;
}
