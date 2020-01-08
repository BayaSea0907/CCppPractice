/*
課題番号　：L23-Special1
内容　　　：ｈeroオブジェクトにヒーロー名とアイテム構造体を格納して、ヒーロー名とアイテム構造体の
　　　　　　メンバを表示する。
　　　　　　アイテム構造体のメンバは、アイテム名と能力、このアイテムが効果を与える対象の有効構造体。
　　　　　　有効構造体のメンバは、効果を与える敵名とダメージ力。
　　　　　　構造体のメンバに他の構造体をもつことを、構造体の入れ子あるいはネスティングという。
　　　　　　ヒーロー名とアイテム構造体のメンバは、コンストラクタを使って初期化する。
・　　　　　表示は、オブジェクトで行う。
ファイル名：L23-S1.cpp
作成日　　：2015/11/21
作成者　　：BayaSea
*/

#include <string>		//文字列操作用
#include <conio.h>
#include <iostream>
using namespace std;

//有効構造体定義
struct Effect {
	string enemy;	//有効敵名
	int damage;		//ダメージ力
};

//アイテム構造体定義`
struct Item {
	string name; 	//アイテム名
	int power;		//能力
	Effect efc;		//有効構造体
};

////////////////////////////////////////////////////////////////
//ヒーロークラス定義
class Hero {
	string name;	//ヒーロー名
	Item itm;		//アイテム
public:
	//コンストラクタ　ヒーロー名とアイテム構造体初期化
	Hero()
	{
		//ヒーロー名
		name = "BERG";
		//アイテム構造体初期化
		itm = { "sword",200,{"Satan", 30} };
	}

	//表示
	void show()
	{
		cout << "アイテム＝" << itm.name << " 能力＝" << itm.power << endl 
			 << "有効敵=" << itm.efc.enemy << " ダメージ力=" 
			 << itm.efc.damage << endl;
	}

};
////////////////////////////////////////////////////////////////
int main()
{
	Hero hero;

	hero.show();	//表示メソッド呼び出し

	_getch();
	return 0;
}

