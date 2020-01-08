//Strategy（shared）
//ある処理のアルゴリズムを一塊の戦略単位オブジェクトとして考え、必要に応じて戦略単位で交換する
//アルゴリズムをif文などで分岐させる代わりに、戦略単位オブジェクトで交換するので
//交換や他の戦略の追加が簡単に行える

//【プログラム】年齢比較戦略、身長比較戦略のいずれかを戦略オブジェクトとして選択する
//共通戦略interfaceを定義し、派生クラスとしてそれぞれの戦略クラスを定義する
//そのほかに、選択した戦略オブジェクトを管理するクラス（CompOperation）を定義する
//そして、このCompOperationオブジェクトで管理している選択戦略オブジェクトの比較処理を行う
//戦略オブジェクト単位でアルゴリズムを切り替えられるので、柔軟でメンテナンスしやすい設計となる
//
//オブジェクト生成テンプレート関数の引数が多くなりすぎないように、インスタンス変数への初期化は
//メソッドで行うようにしている

//Strategy02(shared).cpp
//結果
//RYOとKENは同年
//RYOが高い

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

//オブジェクト生成テンプレート関数-----------------------------------
///////////////////////////////////////////////////////////////////
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//---------------------------------------------------------------
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
//人クラス定義
class Human {
	string name;	//名前
	int height;		//身長
	int weight;		//体重
	int age;		//年齢
public:
	Human(string hname = "", int hheight = 0, int hweight = 0, int hage = 0)
			:name(hname), height(hheight), weight(hweight), age(hage){}

	string getName()const{ return name; }
	int getHeight()const{ return height; }
	int getWeight()const{ return weight; }
	int getAge()const{ return age; }

	void setName(string sname){ name = sname; }
	void setHeight(int sheight){ height = sheight; }
	void setWeight(int sweight){ weight = sweight; }
	void setAge(int sage){ age = sage; }
};

//Strategy定義----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//比較戦略interfaceクラス定義（抽象クラス定義）
class Comparator {
public:
	virtual int compare(shared_ptr<Human> sh_h1, shared_ptr<Human> sh_h2) = 0;
};

///////////////////////////////////////////////////////////////////
//年齢比較クラス定義
class AgeComparator : public Comparator {
public:
	int compare(shared_ptr<Human> sh_h1, shared_ptr<Human> sh_h2)
	{
		if(sh_h1->getAge() > sh_h2->getAge())			return 1;
		else if(sh_h1->getAge() == sh_h2->getAge())		return 0;
		else											return -1;
	}
};
//----------------------------------------------------------------
//身長比較クラス定義
class HeightComparator : public Comparator {
public:
	int compare(shared_ptr<Human> sh_h1, shared_ptr<Human> sh_h2)
	{
		if(sh_h1->getHeight() > sh_h2->getHeight())			return 1;
		else if(sh_h1->getHeight() == sh_h2->getHeight())	return 0;
		else												return -1;
	}
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//比較操作クラス定義
class CompOperation {
	shared_ptr<Comparator> sh_comparator;	//選択実行する比較戦略オブジェクト管理
public:
	CompOperation(shared_ptr<Comparator> mcomparator):sh_comparator(mcomparator){}

	int compare(shared_ptr<Human> sh_h1, shared_ptr<Human> sh_h2)
	{
		return sh_comparator->compare(sh_h1, sh_h2);
	}
	~CompOperation(){}
};
//----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Human> sh_human1(createObject<Human>());
	sh_human1->setName("RYO");
	sh_human1->setHeight(190);
	sh_human1->setWeight(80);
	sh_human1->setAge(25);

	shared_ptr<Human> sh_human2(createObject<Human>());
	sh_human2->setName("KEN");
	sh_human2->setHeight(180);
	sh_human2->setWeight(75);
	sh_human2->setAge(25);

	//年齢比較
	shared_ptr<Comparator> sh_comparator(createObject<AgeComparator>());
	shared_ptr<CompOperation> sh_comp(createObject<CompOperation>(sh_comparator));

	switch(sh_comp->compare(sh_human1, sh_human2))
	{
		case 1: cout << sh_human1->getName() << "が年上" << endl;  break;
		case 0: cout << sh_human1->getName() << "と" 
					 << sh_human2->getName() << "は同年" << endl;  break;
		default: cout << sh_human2->getName() << "が年上" << endl;  break;
	}

	sh_comparator.reset();
	sh_comp.reset();

	//身長比較
	sh_comparator = createObject<HeightComparator>();
	sh_comp = createObject<CompOperation>(sh_comparator);

	switch(sh_comp->compare(sh_human1, sh_human2))
	{
		case 1: cout << sh_human1->getName() << "が高い" << endl;  break;
		case 0: cout << sh_human1->getName() << "と" 
					 << sh_human2->getName() << "は同じ高さ" << endl;  break;
		default: cout << sh_human2->getName() << "が高い" << endl;  break;
	}

	return 0;
}
