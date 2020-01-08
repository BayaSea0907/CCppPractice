//factoryMethod（sharedポインタ）
//製品オブジェクトとオブジェクト生成工場オブジェクトをsharedポインタで管理
//factoryMethodの考え方を簡略化するために、製品オブジェクトのインスタンス変数は
//stringのみにしてある
//
//factoryMethodの考え方は同じ
//【重要ポイント】
//製品オブジェクトの生成は、工場interfaceクラスのCreateObjectメソッドを
//呼び出さない限り生成できないことがポイント
//
//factoryMethod02(shared).cpp
//結果
//Audi
//銀行は破産しました

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

////////////////////////////////////////////////////////////
//オブジェクト生成テンプレート関数
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//--------------------------------------------------------
//オブジェクト生成テンプレート関数
template<class X, class Y>
shared_ptr<X> createObject(Y n)
{
	return (shared_ptr<X>)(new X(n));
}
////////////////////////////////////////////////////////////

//製品クラス++++++++++++++++++++++++++++++++++++++++++++++++++++++
////////////////////////////////////////////////////////////
//製品interfaceクラス定義（抽象クラス）
class IProduct {
public:
	virtual string getName()const = 0;
	virtual ~IProduct(){}
};

////////////////////////////////////////////////////////////
//製品（自動車）クラス定義
class Car: public IProduct {
	string name;			//製品名
public:
	Car(string cname):name(cname){}
	string getName()const{ return name; }
	~Car(){}
};
//----------------------------------------------------------
//製品（銀行）クラス定義
class Bank: public IProduct {
public:
	Bank(){ cout << "銀行は破産しました" << endl; }
	string getName()const{ return ""; }
	~Bank(){}
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//製品オブジェクト生成（工場）クラス++++++++++++++++++++++++++++++++++++
////////////////////////////////////////////////////////////
//工場interfaceクラス定義（抽象クラス）
class IFactory
{
	//②派生クラスのメソッド③を上書きする
	virtual shared_ptr<IProduct> create(string cname) = 0;
	virtual shared_ptr<IProduct> create() = 0;
public:
	//①ここを呼び出して始まる
	//純粋仮想メソッドを介して、CFactoryで実際に生成する
	shared_ptr<IProduct> CreateInstance(string cname)
	{
		return create(cname);		//②を呼び出す
	}

	shared_ptr<IProduct> CreateInstance()
	{
		return create();			//②を呼び出す
	}

	virtual ~IFactory(){}
};

////////////////////////////////////////////////////////////
//製品オブジェクト生成工場
class CFactory : public IFactory
{
protected:
	//③ここで、実際に製品オブジェクトを生成する
	shared_ptr<IProduct> create(string cname)
	{
		return createObject<Car>(cname);
	}

	shared_ptr<IProduct> create()
	{
		return createObject<Bank>();
	}
public:
	~CFactory(){}
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

////////////////////////////////////////////////////////////
int main()
{
	//工場オブジェクト生成
	shared_ptr<CFactory> sh_cfactory(createObject<CFactory>()); 

	//生成製品オブジェクト管理用
	shared_ptr<IProduct> sh_car;
	shared_ptr<IProduct> sh_bank;

	sh_car = sh_cfactory->CreateInstance("Audi");	//自動車オブジェクト生成
	cout << sh_car->getName() << endl;

	sh_bank = sh_cfactory->CreateInstance();		//銀行オブジェクト生成

	return 0;
}


