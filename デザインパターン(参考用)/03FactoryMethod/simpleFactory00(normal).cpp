//simpleFactory（製品：自動車は製品名、食品は個数）
//オブジェクト生成関数（外部関数）を使って、製品オブジェクト（自動車、商品）を生成している
//製品interfaceクラスは一般クラス（仮想メソッド定義）
//
/*
//製品interfaceクラス定義
class IProduct {
public:
	virtual ~IProduct(){}
	virtual string getName()const{ return ""; }
	virtual int getKosu()const{ return 0; }

//    純粋仮想メソッドでは定義できない
//    理由：抽象クラスの純粋仮想メソッドは、抽象クラスか派生クラスで実装しなければならないため
//    　　　派生Carクラスで実装しているのは、getNameメソッドのみ
//    　　　（getKosuメソッドが実装できていないため）
//    virtual string getName()const = 0;
//    virtual int getKosu()const = 0;

};
//自動車クラス定義
class Car : public IProduct {
public:
	string getName()const{ return name; }
};
//食品クラス定義
class Foods : public IProduct {
public:
	int getKosu()const{ return kosu; }
};
*/
//simpleFactory00(normal).cpp
//結果
//Audi
//COKE

#include <iostream>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////
//製品interfaceクラス定義
class IProduct {
public:
	virtual ~IProduct(){}
	virtual string getName()const{ return ""; }
	virtual int getKosu()const{ return 0; }
};

/////////////////////////////////////////////////////////////////
//自動車クラス定義
class Car : public IProduct {
	string name;			//車種名
public:
	Car(string cname):name(cname){}
	~Car(){}
	string getName()const{ return name; }
};

/////////////////////////////////////////////////////////////////
//食品クラス定義
class Foods : public IProduct {
	int kosu;				//個数
public:
	Foods(int fkosu):kosu(fkosu){}
	~Foods(){}
	int getKosu()const{ return kosu; }
};

/////////////////////////////////////////////////////////////////
//オブジェクト生成関数
//ここで、派生クラスオブジェクトを生成している（戻り値は、基本クラスポインタ）
IProduct* createFactory(int id)
{
    switch(id)
    {
        case 1: return new Car("Audi");
        case 2: return new Foods(800);
       default: return NULL;
    }
}

/////////////////////////////////////////////////////////////////
int main()
{
	IProduct* carP;
	IProduct* foodsP;

	carP = createFactory(1);			//自動車オブジェクト生成
	cout << carP->getName() << endl;

	foodsP = createFactory(2);			//食品オブジェクト生成
	cout << foodsP->getKosu() << endl;

	delete carP;
	delete foodsP;

	return 0;
}
