//factoryMethod
//製品オブジェクトを、工場オブジェクトで生成する
//simleFactory（オブジェクト生成外部関数）で生成するのではなく、
//オブジェクト生成オブジェクトで生成する
//製品が、工場で作られるイメージどおりの流れができている
//
//【重要ポイント】
//製品オブジェクト生成は、工場interfaceクラスのCreateInstanceメソッドを
//呼び出さない限り生成できないことがポイント
//
/*
//オブジェクト生成クラス------------------------------------
//工場interfaceクラス定義
class IFactory
{
	//②派生クラスのメソッド③で上書きする
	virtual IProduct* create(string cname) = 0;
public:
	//①このメソッドを呼び出して始まる
	IProduct* CreateInstance(string cname)
	{
		return create(cname);	//②の仮想メソッドを呼び出す
	}
};
////////////////////////////////////////////////////////
class CFactory : public IFactory
{
protected:
	//③ここで、ようやく実際に製品オブジェクトを生成する
	IProduct* create(string cname){ return new Product(cname); }
};
//--------------------------------------------------------------------
*/
//
//factoryMethod00(normal).cpp
//結果
//Audi
//CAKE

#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////
//製品interfaceクラス定義
class IProduct {
public:
	virtual string getName()const{ return ""; }
	virtual int getKosu()const{ return 0; }
	virtual ~IProduct(){}
};

//////////////////////////////////////////////////////////
//製品クラス定義
class Car : public IProduct {
	string name;		//製品名
public:
	Car(string pname):name(pname){}
	string getName()const{ return name; }
	~Car(){}
};

//////////////////////////////////////////////////////////
//食品クラス定義
class Foods : public IProduct {
	int kosu;			//個数
public:
	Foods(int fkosu):kosu(fkosu){}
	int getKosu()const{ return kosu; }
	~Foods(){}
};

//オブジェクト生成クラス------------------------------------
//////////////////////////////////////////////////////////
//工場interfaceクラス定義
class IFactory
{
	virtual IProduct* create(string cname) = 0;
	virtual IProduct* create(int ckosu) = 0;
public:
	//製品オブジェクト生成
	//純粋仮想メソッドを介して、派生クラスCFactoryで実際に生成する
	//cname：製品名　ckosu：個数
	IProduct* CreateInstance(string cname){ return create(cname); }
	IProduct* CreateInstance(int ckosu){ return create(ckosu); }

	virtual ~IFactory(){}
};
//////////////////////////////////////////////////////////
//製品を生成する工場クラス定義
//ここで製品派生クラスオブジェクトを生成する（戻り値は、基本クラスポインタ）
class CFactory : public IFactory
{
protected:
	//ここで、実際に製品オブジェクトを生成
	//cname：製品名　ckosu：個数
	IProduct* create(string cname){ return new Car(cname); }
	IProduct* create(int ckosu){ return new Foods(ckosu); }
public:
	~CFactory(){}
};
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////
int main()
{
	CFactory* cFactoryP = new CFactory();		//オブジェクト生成工場生成
	IProduct* carP;
	IProduct* foodsP;

	//工場オブジェクトで製品オブジェクトを生成
	carP = cFactoryP->CreateInstance("Audi");		//自動車オブジェクト生成
	cout << carP->getName() << endl;

	foodsP = cFactoryP->CreateInstance(800);		//食品オブジェクト生成
	cout << foodsP->getKosu() << endl;

	delete carP;
	delete foodsP;
	delete cFactoryP;

	return 0;
}
