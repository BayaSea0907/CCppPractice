//factoryMethod（製品クラスをtemplateに変更）
//factoryMethod00(normal).cppの変更
//製品クラスProductのインスタンス変数の型をテンプレートに変更
//その結果、製品interfaceクラスIProductもテンプレートに変更
//さらに、オブジェクト生成工場クラスのIFactory、CFactoryもテンプレートへ変更
//
//製品interfaceクラスIProduct、工場interfaceクラスIFactoryは、
//抽象クラスで定義

//factoryMethodの考え方は同じ
//【重要ポイント】
//製品オブジェクト生成は、工場interfaceクラスのCreateInstanceメソッドを
//呼び出さない限り生成できないことがポイント
//
//factoryMethod01(normal-productTemplate).cpp
//結果
//Audi
//CAKE

#include <iostream>
#include <string>
using namespace std;

//製品オブジェクト生成クラス--------------------------------
//////////////////////////////////////////////////////////
//製品interfaceクラス定義（テンプレートinterface抽象クラス）
template<class X>
class IProduct {
public:
	virtual X getInst()const = 0;
	virtual ~IProduct(){}
};
//////////////////////////////////////////////////////////
//製品クラス定義（テンプレート抽象クラス）
template<class X>
class Product : public IProduct<X> {
	X inst;
public:
	Product(X pinst):inst(pinst){}
	X getInst()const{ return inst; }
	~Product(){}
};
//----------------------------------------------------------

//オブジェクト生成クラス------------------------------------
//////////////////////////////////////////////////////////
//工場interfaceクラス定義（テンプレート抽象クラス）
template<class X>
class IFactory
{
	//②この純粋仮想メソッドを③の派生クラスのメソッドで上書きする
	virtual IProduct<X>* create(X cinst) = 0;
public:
	//①ここを呼び出して、製品オブジェクトを生成する
	IProduct<X>* CreateInstance(X cinst)
	{
		return create(cinst);	//②を呼び出す
	}

	virtual ~IFactory(){}
};
//////////////////////////////////////////////////////////
//製品を生成する工場クラス定義（テンプレート工場クラス）
//ここで製品派生クラスオブジェクトを生成する（戻り値は、基本クラスポインタ）
template<class X>
class CFactory : public IFactory<X>
{
protected:
	//③ここで、実際に製品オブジェクトを生成
	IProduct<X>* create(X cinst){ return new Product<X>(cinst); }
public:
	~CFactory(){}
};
//--------------------------------------------------------------------

//////////////////////////////////////////////////////////
int main()
{
	CFactory<string>* cFactoryP1 = new CFactory<string>();		//オブジェクト生成工場生成
	IProduct<string>* carP;

	CFactory<int>* cFactoryP2 = new CFactory<int>();		//オブジェクト生成工場生成
	IProduct<int>* foodsP;

	//工場オブジェクトで製品オブジェクトを生成
	carP = cFactoryP1->CreateInstance("Audi");		//自動車オブジェクト生成
	cout << carP->getInst() << endl;

	foodsP = cFactoryP2->CreateInstance(800);		//食品オブジェクト生成
	cout << foodsP->getInst() << endl;

	delete carP;
	delete foodsP;
	delete cFactoryP1;
	delete cFactoryP2;

	return 0;
}
