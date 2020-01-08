//Builder（shared）
//「作成過程」を決定するDirectorと呼ばれるものと「表現形式」を決定するBuilderと呼ばれるものを組み合わて、
//オブジェクトの生成をより柔軟にし、そのオブジェクトの「作成過程」をもコントロールすることができるようにする
//
//Builder02(shared).cpp
//結果
//作成した塩水の塩は35g 水は150g

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
//塩水クラス定義
class SaltWater {
	double salt;	//塩（g)
	double water;	//水（g）
public:
	SaltWater():salt(0.0), water(0.0){}

	void addSalt(double asalt){ salt += asalt; }		//塩追加
	void addWater(double awater){ water += awater; }	//水追加

	double getSalt()const{ return salt; }				//塩取得
	double getWater()const{ return water; }				//水取得
};

//表現形式------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Builder（表現形式）interfaceクラス定義（抽象クラス）
class Builder {
public:
	virtual void addSolute(double asalt) = 0;
	virtual void addSolvent(double awater) = 0;
	virtual void abandonSolution(double asaltwater) = 0;
	virtual shared_ptr<SaltWater> getResult()const = 0;
};

//////////////////////////////////////////////////////////////////
//塩水Builderクラス定義
class SaltWaterBuilder : public Builder {
	shared_ptr<SaltWater> sh_saltWater;			//生成塩水オブジェクト
public:
	SaltWaterBuilder():sh_saltWater(createObject<SaltWater>()){}		//塩水オブジェクト生成
	void addSolute(double asalt){ sh_saltWater->addSalt(asalt); }		//塩追加
	void addSolvent(double awater){ sh_saltWater->addWater(awater); }	//水追加

	//塩水廃棄
	void abandonSolution(double asaltwater)
	{
		double abandonsalt = asaltwater * (sh_saltWater->getSalt() /
												(sh_saltWater->getSalt() + sh_saltWater->getWater()));
		double abandonwater = asaltwater * (sh_saltWater->getWater() /
												(sh_saltWater->getSalt() + sh_saltWater->getWater()));

		sh_saltWater->addSalt(-abandonsalt);	//塩減少分を追加
		sh_saltWater->addWater(-abandonwater);	//水減少分を追加
	}

	shared_ptr<SaltWater> getResult()const{ return sh_saltWater; }	//現在の塩水取得
};
//--------------------------------------------------------------------

//作成過程------------------------------------------------------------
//////////////////////////////////////////////////////////////////
//Builderオブジェクトの（作成過程）クラス定義
class Director {
	shared_ptr<Builder> sh_builder;		//実際に操作する生成Builderオブジェクトを管理する
public:
	Director(shared_ptr<Builder> sh_dbuilder):sh_builder(sh_dbuilder){}

	//生成Builderオブジェクトの作成過程を書きならべたメソッド
	void constract()
	{
		sh_builder->addSolvent(100);		//水追加
		sh_builder->addSolute(40);			//塩追加
		sh_builder->abandonSolution(70);	//塩水を70％廃棄
		sh_builder->addSolvent(100);		//水追加
		sh_builder->addSolute(15);			//塩追加
	}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	//塩水Builderオブジェクト生成
	shared_ptr<Builder> sh_builder(createObject<SaltWaterBuilder>());

	//塩水Builderオブジェクトの作成過程オブジェクト生成
	shared_ptr<Director> sh_direct(createObject<Director>(sh_builder));

	sh_direct->constract();							//塩水を作る

	shared_ptr<SaltWater> sh_saltWater = sh_builder->getResult();		//作った塩水を取得

	cout << "作成した塩水の塩は" << sh_saltWater->getSalt() << "g"
		 << " 水は" << sh_saltWater->getWater() << "g" << endl;

	return 0;
}
