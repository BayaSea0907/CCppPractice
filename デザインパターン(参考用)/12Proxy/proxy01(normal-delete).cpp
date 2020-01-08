//proxy（生成領域の解放タイミング解決方法）
//一般のポインタを使っている場合、delete解放のタイミングが問題になる
//sharedポインタを使うプログラムでは不要である
//オブジェクト生成関数を使って、オブジェクトを生成した場合、生成オブジェクトを解放するタイミングが問題になる
//生成と解放は、できるだけ同じあるいは近い場所で行うほうがわかり易い
//例えば、simpleFactoryやfactoryMethodパターンのような場合、main関数で解放しているが、
//何を解放しなければならないのか、さらに、解放し忘れの可能性が大きくなるなど、プログラマーに過度の負荷を
//かけてしまう
//
/*
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

	carP = createFactory(1);
	foodsP = createFactory(2);

	//問題点　生成派生オブジェクトを利用している場所で解放させている
	delete carP;
	delete foodsP;

	return 0;
}
*/
//【重要ポイント】
//代理クラスで生成派生オブジェクトとを管理させ、代理オブジェクトが消滅する時点で
//自動的に生成派生オブジェクトを解放させるので、解放を意識させなくしている
//代理オブジェクトは、宣言で領域を確保する
//宣言により、代理オブジェクトがスコープを抜けた時に、自動的に生成派生オブジェクトが
//解放される点が利点である
//proxy01(normal-delete).cpp
//結果
//Audi
//COKE

#include <iostream>
#include <string>
using namespace std;

//クラス定義と派生オブジェクト生成関数-------------------------------
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
//オブジェクト生成工場関数
//ここで、オブジェクトを生成している（戻り値は、基本クラスポインタ）
IProduct* createFactory(int id)
{
    switch(id)
    {
        case 1: return new Car("Audi");
        case 2: return new Foods(800);
       default: return NULL;
    }
}
//-------------------------------------------------------------------

/////////////////////////////////////////////////////////////////
//Proxyクラス定義（本物のクラスの代理クラス）
//生成したオブジェクトをデストラクタで解放する
class Proxy : public IProduct
{
	IProduct* realClassP;	//生成オブジェクト管理用ポインタ
public:
	Proxy(IProduct* productP = NULL):realClassP(productP){}

	//生成オブジェクトを管理する
	void setRealClassP(IProduct* productP){ realClassP = productP; }
	void operator=(IProduct* productP)
{
if(realClassP != NULL)	delete realClassP;
realClassP = productP;
}

	//生成オブジェクトのメソッドを呼び出す
	string getName()const{ return realClassP->getName(); }
	int getKosu()const{ return realClassP->getKosu(); }

	//生成オブジェクトを解放
	~Proxy(){ delete realClassP; }
};

/////////////////////////////////////////////////////////////////
int main()
{
	Proxy proxy;		//（重要）代理クラスのオブジェクト宣言

	//代理クラスで生成オブジェクトを管理する
//	proxy.setRealClassP(createFactory(1));		//メソッド使用
	proxy = createFactory(1);				//演算子overload使用

	cout << proxy.getName() << endl;

	proxy = createFactory(2);				//演算子overload使用
	cout << proxy.getKosu() << endl;

	return 0;
}
