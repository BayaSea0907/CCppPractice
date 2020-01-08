//simpleFactory（製品：自動車は製品名、食品は個数）
//sharedポインタ用オブジェクト生成関数（外部関数）を使って、製品オブジェクト（自動車、商品）を生成している
//製品interfaceクラスは一般クラス（仮想メソッド定義）
//simpleFactory01(shared).cpp
//結果
//Audi
//COKE

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
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

//sharedポインタ用オブジェクト生成---------------------------------
/////////////////////////////////////////////////////////////////
//オブジェクト生成テンプレート関数
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
/////////////////////////////////////////////////////////////////
//オブジェクト生成関数
//派生クラスオブジェクトを生成する（戻り値は、基本クラス型のsharedポインタ）
shared_ptr<IProduct> createFactory(int id)
{
    switch(id)
    {
        case 1: return createObject<Car, string>("Audi");
        case 2: return createObject<Foods, int>(800);
       default: return NULL;
    }
}
//-----------------------------------------------------------------
/////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<IProduct> sh_carP;
	shared_ptr<IProduct> sh_foodsP;

	sh_carP = createFactory(1);				//自動車オブジェクト生成
	cout << sh_carP->getName() << endl;

	sh_foodsP = createFactory(2);			//食品オブジェクト生成
	cout << sh_foodsP->getKosu() << endl;
	return 0;
}
