//Builder（shared）
//「作成過程」を決定するDirectorと「表現形式」を決定するBuilderとを組み合わて、
//オブジェクトの生成をより柔軟にし、そのオブジェクトの「作成過程」をもコントロールする
//
//Coffee（砂糖入り、クリーム入り、砂糖＆クリーム、Black）を作るものとして、
//それぞれのCoffeeクラスを、Builder interfaceクラスから派生させて定義する
//そして、それぞれのCoffeeの作り方を作成過程Directorクラスを別に定義する
//
//作りたいCoffeeオブジェクトをDirectorオブジェクトに渡すと、Directorオブジェクトが
//作成過程に従ってCoffeeを作ってくれる
//
//このように素材となる「表現形式」を決定するBuilderと「作成過程」を決定するDirector
//を用意することによって、利用者は作りたいBuilderオブジェクトをDirectorオブジェクトに
//渡すだけで、素材内容や作成過程を意識することなくオブジェクトを生成できる

//Builder03(shared-Coffee).cpp
//結果
//オーダーのcoffeeは Cream入り
//オーダーのcoffeeは Sugar入りCream入り
//オーダーのcoffeeは Black

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
//COFFEEクラス定義
class Coffee {
	string coffee;
public:
	Coffee():coffee(""){}

	void addCoffee(string acoffee){ coffee += acoffee; }	//追加
	string getCoffee()const{ return coffee; }				//取得
};

//表現形式------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Builder（表現形式）interfaceクラス定義
class Builder {
public:
	virtual void addSugar() = 0;
	virtual void addCream() = 0;
	virtual void addBlack() = 0;
	virtual shared_ptr<Coffee> getResult()const = 0;
};

//////////////////////////////////////////////////////////////////
//砂糖入りBuilderクラス定義
class SugarCoffeeBuilder : public Builder {
	shared_ptr<Coffee> sh_Coffee;								//Coffeeオブジェクト管理
public:
	SugarCoffeeBuilder():sh_Coffee(createObject<Coffee>()){}	//Coffeeオブジェクト生成

	void addSugar(){ sh_Coffee->addCoffee("Sugar入り"); }		//砂糖追加
	void addCream(){ sh_Coffee->addCoffee(""); }				//Creamなし
	void addBlack(){ sh_Coffee->addCoffee(""); }

	shared_ptr<Coffee> getResult()const{ return sh_Coffee; }	//現在のCoffee取得
};
//---------------------------------------------------------------
//クリーム入りBuilderクラス定義
class CreamCoffeeBuilder : public Builder {
	shared_ptr<Coffee> sh_Coffee;								//Coffeeオブジェクト管理
public:
	CreamCoffeeBuilder():sh_Coffee(createObject<Coffee>()){}	//Coffeeオブジェクト生成

	void addSugar(){ sh_Coffee->addCoffee(""); }				//砂糖なし
	void addCream(){ sh_Coffee->addCoffee("Cream入り"); }		//クリーム追加
	void addBlack(){ sh_Coffee->addCoffee(""); }

	shared_ptr<Coffee> getResult()const{ return sh_Coffee; }	//現在のCoffee取得
};
//---------------------------------------------------------------
//ミルク＆クリーム入りBuilderクラス定義
class SugarCreamCoffeeBuilder : public Builder {
	shared_ptr<Coffee> sh_Coffee;									//Coffeeオブジェクト管理
public:
	SugarCreamCoffeeBuilder():sh_Coffee(createObject<Coffee>()){}	//Coffeeオブジェクト生成

	void addSugar(){ sh_Coffee->addCoffee("Sugar入り"); }			//砂糖追加
	void addCream(){ sh_Coffee->addCoffee("Cream入り"); }			//クリーム追加
	void addBlack(){ sh_Coffee->addCoffee(""); }

	shared_ptr<Coffee> getResult()const{ return sh_Coffee; }		//現在のCoffee取得
};
//---------------------------------------------------------------
//ブラックBuilderクラス定義
class BlackCoffeeBuilder : public Builder {
	shared_ptr<Coffee> sh_Coffee;								//Coffeeオブジェクト管理
public:
	BlackCoffeeBuilder():sh_Coffee(createObject<Coffee>()){}	//Coffeeオブジェクト生成

	void addSugar(){ sh_Coffee->addCoffee(""); }				//砂糖なし
	void addCream(){ sh_Coffee->addCoffee(""); }				//クリームなし
	void addBlack(){ sh_Coffee->addCoffee("Black"); }

	shared_ptr<Coffee> getResult()const{ return sh_Coffee; }	//現在のCoffee取得
};
//--------------------------------------------------------------------

//作成過程------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Builderオブジェクトの（作成過程）クラス定義
class Director {
	shared_ptr<Builder> sh_builder;		//実際に操作する生成Builderオブジェクト管理
public:
	Director(shared_ptr<Builder> sh_dbuilder):sh_builder(sh_dbuilder){}

	//生成Builderオブジェクトの作成過程を書きならべたメソッド
	void constract()
	{
		sh_builder->addSugar();				//砂糖追加
		sh_builder->addCream();				//Cream追加
		sh_builder->addBlack();				//Black追加
	}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	shared_ptr<Builder> sh_builder;

	//Coffeeオブジェクト生成---------------------------------------------------
	//-----------------------------------------------------------------
//	sh_builder = createObject<CreamCoffeeBuilder>();			//クリーム入り
	//-----------------------------------------------------------------
//	sh_builder = createObject<SugarCreamCoffeeBuilder>();   	//砂糖＆クリーム入り
	//-----------------------------------------------------------------
	sh_builder = createObject<BlackCoffeeBuilder>();			//BlackCoffee
	//------------------------------------------------------------------------

	//CoffeeBuilderオブジェクトの作成過程オブジェクト生成
	shared_ptr<Director> sh_direct(createObject<Director>(sh_builder));

	sh_direct->constract();										//coffeeを作る
	shared_ptr<Coffee> sh_coffee = sh_builder->getResult();		//作ったcoffeeを取得

	cout << "オーダーのcoffeeは " << sh_coffee->getCoffee() << endl;

	return 0;
}
