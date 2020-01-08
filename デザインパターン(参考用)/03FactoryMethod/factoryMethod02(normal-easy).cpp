//factoryMethod（製品オブジェクトの簡略化）
//factoryMethod00の製品クラスを１つ（インスタンス変数stringのみ）にする
//
//factoryMethodの働きは同じ
//【重要ポイント】
//製品オブジェクト生成は、工場interfaceクラスのCreateInstanceメソッドを
//呼び出さない限り生成できないことがポイント
//
//factoryMethod02(normal-easy).cpp
//結果
//Audi
//CAKE

#include <iostream>
#include <string>
using namespace std;

//製品オブジェクト生成-------------------------------------
//////////////////////////////////////////////////////////
//製品interfaceクラス定義
class IProduct {
public:
	virtual string getName()const{ return ""; }
	virtual ~IProduct(){}
};

//////////////////////////////////////////////////////////
//製品クラス定義
class Product : public IProduct {
	string name;		//製品名
public:
	Product(string pname):name(pname){}
	string getName()const{ return name; }
	~Product(){}
};
//----------------------------------------------------------

//オブジェクト生成クラス------------------------------------
//////////////////////////////////////////////////////////
//工場interfaceクラス定義
class IFactory
{
	//②派生クラスのメソッド③で上書きする
	virtual IProduct* create(string cname) = 0;
public:
	//①ここを呼び出して始まる
	//純粋仮想メソッドを介して、派生クラスCFactoryで実際に生成する
	IProduct* CreateInstance(string cname){ return create(cname); }

	virtual ~IFactory(){}
};
//////////////////////////////////////////////////////////
//製品を生成する工場クラス定義
//ここで製品派生クラスオブジェクトを生成する（戻り値は、基本クラスポインタ）
class CFactory : public IFactory
{
protected:
	//③ここで、実際に製品オブジェクトを生成する
	IProduct* create(string cname){ return new Product(cname); }
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

	foodsP = cFactoryP->CreateInstance("CAKE");		//食品オブジェクト生成
	cout << foodsP->getName() << endl;

	delete carP;
	delete foodsP;
	delete cFactoryP;

	return 0;
}
