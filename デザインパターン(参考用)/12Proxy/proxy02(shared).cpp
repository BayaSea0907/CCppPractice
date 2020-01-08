//proxy（shared：基本的な考え方）
//処理を他のオブジェクトに任せる（代理させる）
//代理を立てる本物のクラス(RealPrint)も、代理するクラス(CProxyPrint)も、共通interfaceの型(IPrint)にする
//それにより、処理を要求するmain関数側では、本物のクラス(RealPrint)のメソッドを呼び出すののと同じ扱いで
//代理クラスのメソッドを呼び出して振る舞わせることができる
//
//【利点】
//代理クラスを定義すると、本当に処理が必要になるまで、本物のクラスの生成を遅らせることができる
//もしも、本物のクラスを生成する必要もないかもしれない場合には、本当に必要になるまで生成を遅らせることができる
//proxy02(shared).cpp
//結果
//ROBOT

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
//--------------------------------------------------------------------

/////////////////////////////////////////////////////////////////
//interfaceクラス定義（本物と代理クラス共通interface抽象クラス）
class IPrint
{
public:
	virtual void print(string str) = 0;
	virtual ~IPrint(){}
};

/////////////////////////////////////////////////////////////////
//本物クラス定義
class RealPrint : public IPrint
{
public:
	//③代理オブジェクトのメソッドから呼び出されて、初めて処理される
	void print(string str){ cout << str << endl; }
};

/////////////////////////////////////////////////////////////////
//代理クラス定義（本物クラスを代理するクラス）
class CProxyPrint : public IPrint
{
	shared_ptr<IPrint> sh_realClass;		//代理する本物オブジェクト管理用ポインタ
public:
	CProxyPrint():sh_realClass(NULL){}

	//①本物クラスの代わりに呼び出される代理クラスのメソッド
	void print(string str)
	{
		//まだ本物オブジェクトが生成されていない場合、本物オブジェクトを生成する
		if(sh_realClass == NULL)
		{
			sh_realClass = createObject<RealPrint>();		//本物オブジェクト生成
		}

		//②ここで、本物オブジェクトのメソッド③を呼び出す
		sh_realClass->print(str);
	}
};

/////////////////////////////////////////////////////////////////
int main()
{
	//代理オブジェクト生成
	shared_ptr<IPrint> sh_iprint(createObject<CProxyPrint>());

	sh_iprint->print("ROBOT");				//代理クラスのメソッド呼び出し

	return 0;
}
