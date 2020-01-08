//Strategy（normal）
//ある処理のアルゴリズムを一塊の戦略単位オブジェクトとして考え、必要に応じて戦略単位で交換する
//アルゴリズムをif文などで分岐させる代わりに、戦略単位オブジェクトで交換するので
//交換や他の戦略の追加が簡単に行える

//【プログラム】年齢比較戦略、身長比較戦略のいずれかを戦略オブジェクトとして選択する
//共通戦略interfaceを定義し、派生クラスとしてそれぞれの戦略クラスを定義する
//そのほかに、選択した戦略オブジェクトを管理するクラス（CompOperation）を定義する
//そして、このCompOperationオブジェクトで管理している選択戦略オブジェクトの比較処理を行う
//戦略オブジェクト単位でアルゴリズムを切り替えられるので、柔軟でメンテナンスしやすい設計となる
//
//Strategy01(normal).cpp
//結果
//RYOとKENは同年
//RYOが高い

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////
//人クラス定義
class Human {
	string name;	//名前
	int height;		//身長
	int weight;		//体重
	int age;		//年齢
public:
	Human(string hname, int hheight, int hweight, int hage)
			:name(hname), height(hheight), weight(hweight), age(hage){}

	string getName()const{ return name; }
	int getHeight()const{ return height; }
	int getWeight()const{ return weight; }
	int getAge()const{ return age; }
};

//Strategy定義----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//比較戦略interfaceクラス定義（抽象クラス定義）
class Comparator {
public:
	virtual int compare(Human* h1P,Human* h2P) = 0;
};

///////////////////////////////////////////////////////////////////
//年齢比較クラス定義
class AgeComparator : public Comparator {
public:
	int compare(Human* h1P, Human* h2P)
	{
		if(h1P->getAge() > h2P->getAge())			return 1;
		else if(h1P->getAge() == h2P->getAge())		return 0;
		else										return -1;
	}
};
//----------------------------------------------------------------
//身長比較クラス定義
class HeightComparator : public Comparator {
public:
	int compare(Human* h1P, Human* h2P)
	{
		if(h1P->getHeight() > h2P->getHeight())			return 1;
		else if(h1P->getHeight() == h2P->getHeight())	return 0;
		else											return -1;
	}
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//比較操作クラス定義
class CompOperation {
	Comparator* comparatorP;	//選択実行する比較戦略オブジェクト管理ポインタ
public:
	CompOperation(Comparator* mcomparatorP):comparatorP(mcomparatorP){}

	int compare(Human* h1P, Human* h2P)
	{
		return comparatorP->compare(h1P, h2P);
	}
	~CompOperation(){ delete comparatorP; }		//比較戦略オブジェクトの解放
};
//----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	Human* human1P = new Human("RYO", 190, 80, 25);
	Human* human2P = new Human("KEN", 180, 75, 25);

	//年齢比較
	CompOperation* comp1P = new CompOperation(new AgeComparator());

	switch(comp1P->compare(human1P, human2P))
	{
		case 1: cout << human1P->getName() << "が年上" << endl;  break;
		case 0: cout << human1P->getName() << "と" 
					 << human2P->getName() << "は同年" << endl;  break;
		default: cout << human2P->getName() << "が年上" << endl;  break;
	}
	delete comp1P;

	//身長比較
	comp1P = new CompOperation(new HeightComparator());

	switch(comp1P->compare(human1P, human2P))
	{
		case 1: cout << human1P->getName() << "が高い" << endl;  break;
		case 0: cout << human1P->getName() << "と" 
					 << human2P->getName() << "は同じ高さ" << endl;  break;
		default: cout << human2P->getName() << "が高い" << endl;  break;
	}

	delete comp1P;
	delete human1P;
	delete human2P;

	return 0;
}
