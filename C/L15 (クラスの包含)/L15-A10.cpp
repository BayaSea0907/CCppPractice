/*
課題番号　：L15-10
内容　　　：manオブジェクトの年齢を予め0で初期化して、入力した0歳以上の年齢を
　　　　　　格納した後、年齢を表示する。
　　　　　　クラス定義で、manオブジェクトの年齢を0で初期化する。
　　　　　　判定は、年齢が0歳以上ならば年齢をmanオブジェクトに格納し、0歳未満ならばmanオブジェクトの年齢は0と表示する。
　　　　　　年齢入力と年齢表示はuiオブジェクトで行う。
ファイル名：L15-A10.cpp
作成日　　：2015/07/01
作成者　　：BayaSea
*/

//実行時に確認すること：
//□年齢に負値を入力したとき、0を表示することを確認しなさい。

#include <conio.h>
#include <iostream>
using namespace std;

//人クラス定義
class Man {
	int age = 0; //年齢（0）
public:
    //年齢格納メソッド　sage：年齢受取り用
	void setAge(int sage)
	{
		//0歳以上かどうかを判別
		if (sage >= 0)
		{ 
			age = sage;
		}
	}

	//年齢取得メソッド
	int getAge()
	{
		return age;
	}
};

////////////////////////////////////////////////////////////
//ユーザインタフェースクラス定義
class UI {
	Man man;		//人オブジェクト宣言
public:
	//処理制御メソッド
	void processCtrl(){
		inpMan();		//man入力設定
		show();			//表示
	}
	//man入力設定メソッド
	void inpMan()
	{
		//自動変数
		int age;

		cout << "0歳以上の年齢を入力 >> " ;
		cin >> age;
		man.setAge(age);
	}

	//表示メソッド
	void show()
	{
		cout << "年齢は" << man.getAge() << "歳です。" << endl;
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
