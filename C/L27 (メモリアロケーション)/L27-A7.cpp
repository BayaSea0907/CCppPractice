/*
課題番号　：L27-7
内容　　　：アロケーションしたアイテム構造体をもつheroオブジェクトに、ヒーロー名とアイテム構造体
　　　　　　（アイテム名と能力）を入力して、ヒーロー名とアイテム構造体のメンバを表示する。
　　　　　　コンストラクタでプロパティのヒーロー名領域とアイテム構造体領域をアロケーションする。
　　　　　　また、デストラクタで、コンストラクタでアロケーションした領域すべてを解放する。
　　　　　　入力と表示はmain関数で行う。
ファイル名：L27-A7.cpp
作成日　　：2016/1/20
作成者　　：BayaSea
*/

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//アイテム構造体の定義：
struct Item {
	string name;	//アイテム名
	int power;	//能力
};

//ヒーロークラス定義
class Hero {
	string* sp;		//ヒーロー名格納用ポインタ
	Item* itmp;		//アイテム構造体格納用ポインタ
public:
	//コンストラクタ
	Hero(){
		sp = new string;		//ヒーロー名領域アロケーション
		itmp = new Item;		//アイテム構造体領域アロケーション
	}

	//ヒーロー名設定　str：ヒーロー名
	void setName(string str){
		sp = &str;
	}

	//アイテム設定　itm：アイテム構造体
	void setItem(Item itm){
		itmp = &itm;
	}

	//ヒーロー名取得　戻り値：ヒーロー名
	string getName(){
		return *sp;
	}

	//アイテム取得　itm：アイテム構造体
	Item getItem(){
		return *itmp;
	}

	//デストラクタ
	~Hero(){
		//ヒーロー名領域解放
		delete sp;

		//アイテム構造体領域解放
		delete itmp;
	}
};
////////////////////////////////////////////////////////
int main()
{
	Hero* p;			//heroオブジェクトアロケーション領域へのポインタ宣言
	string name;		//ヒーロー名入力用


	Item item;		//アイテム構造体入力取得用

	//heroオブジェクトのアロケーション
	p = new Hero;

	//アロケーションできなかった場合
	if (p == NULL)
	{
		cout << "アロケーション失敗" << endl;
	}
	//アロケーションできた場合
	else
	{
		cout << "ヒーロー名を入力>> ";
		cin >> name;

		//ヒーロー名設定メソッド呼び出し
		p->setName(name);

		cout << "アイテムと能力を入力>> ";
		cin >> item.name >> item.power;

		//アイテム設定メソッド呼び出し
		p->setItem(item);

		//ヒーロー名取得メソッドを呼び出して表示
		cout <<	p->getName() << endl;

		//アイテム取得メソッド呼び出し
		item = p->getItem();
		cout << item.name << " " << item.power << endl;

		//heroオブジェクトアロケーション領域の解放（必ず行うこと）
		delete p;
	}

	_getch();
	return 0;
}


