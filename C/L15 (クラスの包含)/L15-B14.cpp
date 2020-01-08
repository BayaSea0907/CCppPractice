/*
課題番号　：L15-14
内容　　　：ヒーローheroオブジェクトにヒーロー名を設定した後、改めて入力した名前と同じかどうかを判定した結果を表示する。
　　　　　　ヒーロー名と名前は、string型文字列とする。
　　　　　　ヒーロー名と名前の入力は、uiオブジェクトで行い、判定表示はheroオブジェクトで行う。
ファイル名：L15-B14.cpp
作成日　　：2015/07/21
作成者　　：BayaSea
*/
//プログラムを書き換えて確認すること：
//□比較演算子を否定　!=　にして、異なる名前を入力するとどうなるでしょうか？
//　比較演算子の等号（　==　）と否定（　!=　）との比較評価の違いを確認しましょう。

#include <string>		//stringオブジェクトを使うために必要
#include <conio.h>
#include <iostream>
using namespace std;

//HEROクラス定義
class Hero {
	string name;		//ヒーロー名
public:
    //ヒーロー名設定メソッド
	void setName(string sname)
	{
		name = sname;
	}

	//ヒーロー名判定メソッド
	void judgeName(string str)
	{
		//最初と、確認で入力した名前を比較
		if (name == str)
		{
			cout << "ヒーローの名前は" << name << "さんで合ってます。" << endl;
		}
		else
		{
			cout << name << "さんと、" << str << "さんは別人です。" << endl;
		}
	}
};
////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Hero hero;		//heroオブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl(){
		inpHero();		    //hero入力設定
		inpStrJudge();		//比較文字列入力判定
	}
	//hero入力設定メソッド
	void inpHero()
	{
		//自動変数
		string name;

		cout << "ヒーローの名前を設定。 >> ";
		cin >> name;

		hero.setName(name);
	}
	//比較名入力判定メソッド
	void inpStrJudge()
	{
		//自動変数
		string name;

		cout << "もう一度ヒーローの名前を入力してください。 >>";
		cin >> name;

		//ヒーロー名比較メソッドを呼び出す
		hero.judgeName(name);
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
