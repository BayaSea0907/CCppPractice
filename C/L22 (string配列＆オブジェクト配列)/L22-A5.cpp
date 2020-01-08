/*
課題番号　：L22-5
内容　　　：３人のヒーローが現れたので、それぞれのヒーローをheroオブジェクト配列（要素数３）で扱う。
　　　　　　入力した３人のヒーロー名をオブジェクト配列（要素数３）の各要素に格納して、それぞれのヒ
　　　　　　ーロー名を表示する。
　　　　　　入力と表示はmain関数で行う。
ファイル名：L22-A5.cpp
作成日　　：2015/11/12
作成者　　：BayaSea
*/

#include <string>		//文字列操作用
#include <conio.h>
#include <iostream>
using namespace std;

//ヒーロークラス定義
class Hero {
	string name;		//ヒーロー名
public:
	//ヒーロー名設定　str：ヒーロー名
	void setName(string str)
	{
		name = str;
	}

	//ヒーロー名取得
	string getName()
	{
		return name;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Hero hero[3];		//heroオブジェクト配列
	string name;		//ヒーロー名入力用

	//ヒーロー名入力
	for (int i = 0; i < 3; i++)
	{
		cout << "ヒーロー名を入力>> ";
		cin >> name;

		//ヒーロー名設定
		hero[i].setName(name);
	}

	//ヒーロー名表示
	for (int i = 0; i < 3; i++)
	{
		cout << hero[i].getName() << endl;		//ヒーロー名取得
	}

	_getch();
	return 0;
}

