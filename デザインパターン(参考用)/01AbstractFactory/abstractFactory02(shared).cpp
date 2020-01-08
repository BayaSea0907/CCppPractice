//AbstractFactory（sharedポインタ使用）
//オブジェクト生成を、生成工場となる関数で行う
//部品となるクラスの生成が、ソースコードの中に散在しなくなるため、変更が容易になる
//また、生成の際に、他の処理を行わせることも容易になる（他のメソッドを呼び出して処理することも可能）
//
//【重要ポイント】
//同じ「タイヤ」であっても違いがあるが、その違いは、部品を作成する工場の違いによって生まれると考えるので、
//部品の内部的な違いを、外部から気にかける必要がなくなる
//一度オブジェクト生成工場を作ってしまえば、後は全ての操作がインタフェースクラス経由で行われる点が利点
//結果的にどんな部品が作られようとも、同じ操作ができる
//また、１つの工場で作成される部品のセットは、常に同じものなので、複数の部品を常に正しい組み合わせで生成できる
//
//【問題点】
//部品が増えると、ほとんど全ての箇所で追加作業が必要になってしまう
//後から部品を追加することは容易ではない
//abstractFactory02(shared).cpp
//結果
//生成工場Ａで作った車の部品は スリックタイヤ（レーシング用）とハイオク
//生成工場Ｂで作った車の部品は スタッドレスタイヤ（寒冷地用）とＬＰガス

#include <iostream>
#include <string>
#include <memory>
using namespace std::tr1;
using namespace std;

///////////////////////////////////////////////////////////////////
//オブジェクト生成テンプレート関数
template<class X>
shared_ptr<X> createObject()
{
	return (shared_ptr<X>)(new X);
}
//------------------------------------------------------------------

//部品クラス定義++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//タイヤ------------------------------------------------------------
//タイヤinterfaceクラス定義（抽象クラス）
class ITire
{
public:
	virtual string getTire()const = 0;
	virtual ~ITire(){}
};
//----------------------------------------------------------------
//スリックタイヤクラス定義
class Tire1 : public ITire
{
	string tire;
public:
	Tire1():tire("スリックタイヤ（レーシング用）"){}
	string getTire()const{ return tire; }
};
//----------------------------------------------------------------
//スタッドレスタイヤクラス定義
class Tire2 : public ITire
{
	string tire;
public:
	Tire2():tire("スタッドレスタイヤ（寒冷地用）"){}
	string getTire()const{ return tire; }
};
//-----------------------------------------------------------------

//燃料クラス---------------------------------------------------------
//燃料interfaceクラス定義（抽象クラス）
class IFuel
{
public:
	virtual string getFuel()const = 0;
	virtual ~IFuel(){}
};
//-----------------------------------------------------------------
//ハイオククラス定義
class Fuel1 : public IFuel
{
	string fuel;
public:
	Fuel1():fuel("ハイオク"){}
	string getFuel()const{ return fuel; }
};
//-----------------------------------------------------------------
//ＬＰガスクラス定義
class Fuel2 : public IFuel
{
	string fuel;
public:
	Fuel2():fuel("ＬＰガス"){}
	string getFuel()const{ return fuel; }
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//オブジェクト生成工場クラス定義+++++++++++++++++++++++++++++++++++++++
//生成工場interfaceクラス定義（抽象クラス）
class IFactory {
public:
	virtual shared_ptr<ITire> CreateTire() = 0;
	virtual shared_ptr<IFuel> CreateFuel() = 0;
	virtual ~IFactory(){}
};
//-----------------------------------------------------------------
//生成工場Ａクラス定義（部品：スリックタイヤとハイオク）
class FactoryA : public IFactory{
public:
	//スリックタイヤ生成
	shared_ptr<ITire> CreateTire(){ return createObject<Tire1>(); }

	//ハイオク生成
	shared_ptr<IFuel> CreateFuel(){ return createObject<Fuel1>(); }
};
//----------------------------------------------------------------
//生成工場Ｂクラス定義（部品：スタッドレスタイヤとＬＰガス）
class FactoryB : public IFactory{
public:
	//スタッドレスタイヤ生成
	shared_ptr<ITire> CreateTire(){ return createObject<Tire2>(); }

	//ＬＰガス生成
	shared_ptr<IFuel> CreateFuel(){ return createObject<Fuel2>(); } 
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<IFactory> sh_factory;				//生成工場管理用

	sh_factory = createObject<FactoryA>();			//生成工場Ａ生成

	cout << "生成工場Ａで作った車の部品は "
		 << sh_factory->CreateTire()->getTire() << "と"
		 << sh_factory->CreateFuel()->getFuel() << endl;

	sh_factory = createObject<FactoryB>();			//生成工場Ｂ生成

	cout << "生成工場Ｂで作った車の部品は "
		 << sh_factory->CreateTire()->getTire() << "と"
		 << sh_factory->CreateFuel()->getFuel() << endl;

	return 0;
}
